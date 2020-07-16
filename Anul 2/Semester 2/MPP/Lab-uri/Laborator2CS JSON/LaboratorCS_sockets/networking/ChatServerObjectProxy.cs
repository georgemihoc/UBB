// using System;
// using System.Collections.Generic;
// using System.Threading;
// using System.Net;
// using System.Net.Sockets;
// using System.Runtime.Serialization;
// using System.Runtime.Serialization.Formatters.Binary;
// using swim.services;
// using swim.model;
// using swim.network.dto;
// using swim.network.protocol;
// namespace swim.network.server
// {
// 	///
// 	/// <summary> * Created by IntelliJ IDEA.
// 	/// * User: grigo
// 	/// * Date: Mar 18, 2009
// 	/// * Time: 4:36:34 PM </summary>
// 	/// 
// 	public class ChatServerProxy : IServices
// 	{
// 		private string host;
// 		private int port;
//
// 		private IObserver client;
//
// 		private NetworkStream stream;
// 		
//         private IFormatter formatter;
// 		private TcpClient connection;
//
// 		private Queue<Response> responses;
// 		private volatile bool finished;
//         private EventWaitHandle _waitHandle;
// 		public ChatServerProxy(string host, int port)
// 		{
// 			this.host = host;
// 			this.port = port;
// 			responses=new Queue<Response>();
// 		}
//
// 		public virtual void login(String username,String passsword, IObserver client)
// 		{
// 			initializeConnection();
// 			Organizator user = new Organizator(0,username,passsword);
// 			UserDTO udto = DTOUtils.getDTO(user);
// 			sendRequest(new LoginRequest(udto));
// 			Response response =readResponse();
// 			if (response is OkResponse)
// 			{
// 				this.client=client;
// 				return;
// 			}
// 			if (response is ErrorResponse)
// 			{
// 				ErrorResponse err =(ErrorResponse)response;
// 				closeConnection();
// 				throw new ChatException(err.Message);
// 			}
// 		}
//
// 		public virtual void addInscriere(string nume, int varsta, int idProba)
// 		{
// 			//MessageDTO mdto =DTOUtils.getDTO(message);
// 			Inscriere i = new Inscriere(0, 0, idProba);
// 			InscriereDTO mdto = DTOUtils.getDTO(i, nume, varsta);
// 			sendRequest(new AddParticipantRequest(mdto));
// 			Response response =readResponse();
// 			if (response is ErrorResponse)
// 			{
// 				ErrorResponse err =(ErrorResponse)response;
// 				throw new ChatException(err.Message);
// 			}
// 		}
//
// 		//public virtual IEnumerable<Proba> getProbe()
// 		//{
// 		//	//sendRequest()
// 		//}
//
// 		public virtual Organizator[] getLoggedFriends(Organizator user)
// 		{
// 			UserDTO udto = DTOUtils.getDTO(user);
// 			sendRequest(new GetLoggedFriendsRequest(udto));
// 			Response response = readResponse();
// 			if (response is ErrorResponse)
// 			{
// 				ErrorResponse err = (ErrorResponse)response;
// 				throw new ChatException(err.Message);
// 			}
// 			GetLoggedFriendsResponse resp = (GetLoggedFriendsResponse)response;
// 			UserDTO[] frDTO = resp.Friends;
// 			Organizator[] friends = DTOUtils.getFromDTO(frDTO);
// 			return friends;
// 		}
//
// 		public virtual Proba[] getProbe(Organizator user)
// 		{
// 			UserDTO udto = DTOUtils.getDTO(user);
// 			sendRequest(new GetProbeRequest(udto));
// 			Response response = readResponse();
// 			if (response is ErrorResponse)
// 			{
// 				ErrorResponse err = (ErrorResponse)response;
// 				throw new ChatException(err.Message);
// 			}
// 			GetProbeResponse resp = (GetProbeResponse)response;
// 			ProbaDTO[] frDTO = resp.Probe;
// 			Proba[] probe = DTOUtils.getFromDTO(frDTO);
// 			return probe;
// 		}
// 		public virtual Participant[] getParticipanti(Organizator user)
// 		{
// 			UserDTO udto = DTOUtils.getDTO(user);
// 			sendRequest(new GetParticipantiRequest(udto));
// 			Response response = readResponse();
// 			if (response is ErrorResponse)
// 			{
// 				ErrorResponse err = (ErrorResponse)response;
// 				throw new ChatException(err.Message);
// 			}
// 			GetParticipantiResponse resp = (GetParticipantiResponse)response;
// 			ParticipantDTO[] frDTO = resp.Participanti;
// 			Participant[] participanti = DTOUtils.getFromDTO(frDTO);
// 			return participanti;
// 		}
// 		public virtual Inscriere[] getInscrieri(Organizator user)
// 		{
// 			UserDTO udto = DTOUtils.getDTO(user);
// 			sendRequest(new GetInscrieriRequest(udto));
// 			Response response = readResponse();
// 			if (response is ErrorResponse)
// 			{
// 				ErrorResponse err = (ErrorResponse)response;
// 				throw new ChatException(err.Message);
// 			}
// 			GetInscrieriResponse resp = (GetInscrieriResponse)response;
// 			InscriereDTO2[] frDTO = resp.Inscrieri;
// 			Inscriere[] inscrieri = DTOUtils.getFromDTO(frDTO);
// 			return inscrieri;
// 		}
//
//
// 		private void closeConnection()
// 		{
// 			finished=true;
// 			try
// 			{
// 				stream.Close();
// 				//output.close();
// 				connection.Close();
//                 _waitHandle.Close();
// 				client=null;
// 			}
// 			catch (Exception e)
// 			{
// 				Console.WriteLine(e.StackTrace);
// 			}
//
// 		}
//
// 		private void sendRequest(Request request)
// 		{
// 			try
// 			{
//                 formatter.Serialize(stream, request);
//                 stream.Flush();
// 			}
// 			catch (Exception e)
// 			{
// 				throw new ChatException("Error sending object "+e);
// 			}
//
// 		}
//
// 		private Response readResponse()
// 		{
// 			Response response =null;
// 			try
// 			{
//                 _waitHandle.WaitOne();
// 				lock (responses)
// 				{
//                     //Monitor.Wait(responses); 
//                     response = responses.Dequeue();
//                 
// 				}
// 				
//
// 			}
// 			catch (Exception e)
// 			{
// 				Console.WriteLine(e.StackTrace);
// 			}
// 			return response;
// 		}
// 		private void initializeConnection()
// 		{
// 			 try
// 			 {
// 				connection=new TcpClient(host,port);
// 				stream=connection.GetStream();
//                 formatter = new BinaryFormatter();
// 				finished=false;
//                 _waitHandle = new AutoResetEvent(false);
// 				startReader();
// 			}
// 			catch (Exception e)
// 			{
//                 Console.WriteLine(e.StackTrace);
// 			}
// 		}
// 		private void startReader()
// 		{
// 			Thread tw =new Thread(run);
// 			tw.Start();
// 		}
//
//
// 		private void handleUpdate(UpdateResponse update)
// 		{
// 			if (update is LoggedInResponse)
// 			{
//
// 				LoggedInResponse loggedInResponse =(LoggedInResponse)update;
// 				Organizator friend =DTOUtils.getFromDTO(loggedInResponse.UserDto);
// 				Console.WriteLine("Friend logged in "+friend);
// 				try
// 				{
// 					client.loggedIn(friend);
// 				}
// 				catch (ChatException e)
// 				{
//                     Console.WriteLine(e.StackTrace); 
// 				}
// 			}
//
// 			if (update is ParticipantAdaugatResponse)
// 			{
// 				ParticipantAdaugatResponse partInscris =(ParticipantAdaugatResponse)update;
// 				Inscriere inscriere =DTOUtils.getFromDTO(partInscris.InscriereDto);
// 				try
// 				{
// 					//client.participantInscris();
// 					client.refresh(inscriere);
// 				}
// 				catch (ChatException e)
// 				{
//                     Console.WriteLine(e.StackTrace);
// 				}
// 			}
// 		}
// 		public virtual void run()
// 			{
// 				while(!finished)
// 				{
// 					try
// 					{
//                         object response = formatter.Deserialize(stream);
// 						Console.WriteLine("response received "+response);
// 						if (response is UpdateResponse)
// 						{
// 							 handleUpdate((UpdateResponse)response);
// 						}
// 						else
// 						{
// 							
// 							lock (responses)
// 							{
//                                 					
// 								 
//                                 responses.Enqueue((Response)response);
//                                
// 							}
//                             _waitHandle.Set();
// 						}
// 					}
// 					catch (Exception e)
// 					{
// 						Console.WriteLine("Reading error "+e);
// 					}
// 					
// 				}
// 			}
// 		//}
// 	}
//
// }