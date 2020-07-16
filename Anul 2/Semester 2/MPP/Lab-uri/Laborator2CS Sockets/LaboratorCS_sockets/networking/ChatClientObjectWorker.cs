using System;
using System.Threading;
using System.Net;
using System.Net.Sockets;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using swim.services;
using swim.model;
using swim.network.dto;
using swim.network.protocol;
namespace swim.networking
{

	
	
	///
	/// <summary> * Created by IntelliJ IDEA.
	/// * User: grigo
	/// * Date: Mar 18, 2009
	/// * Time: 4:04:43 PM </summary>
	/// 
	public class ChatClientWorker :  IObserver //, Runnable
	{
		private IServices server;
		private TcpClient connection;

		private NetworkStream stream;
		private IFormatter formatter;
		private volatile bool connected;
		public ChatClientWorker(IServices server, TcpClient connection)
		{
			this.server = server;
			this.connection = connection;
			try
			{
				
				stream=connection.GetStream();
                formatter = new BinaryFormatter();
				connected=true;
			}
			catch (Exception e)
			{
                Console.WriteLine(e.StackTrace);
			}
		}

		public virtual void run()
		{
			while(connected)
			{
				try
				{
                    object request = formatter.Deserialize(stream);
					object response =handleRequest((Request)request);
					if (response!=null)
					{
					   sendResponse((Response) response);
					}
				}
				catch (Exception e)
				{
                    Console.WriteLine(e.StackTrace);
				}
				
				try
				{
					Thread.Sleep(1000);
				}
				catch (Exception e)
				{
                    Console.WriteLine(e.StackTrace);
				}
			}
			try
			{
				stream.Close();
				connection.Close();
			}
			catch (Exception e)
			{
				Console.WriteLine("Error "+e);
			}
		}
		public virtual void participantInscris(string nume,int varsta, int idProba )
		{
			Inscriere i = new Inscriere(0, 0, idProba);
			InscriereDTO mdto = DTOUtils.getDTO(i,nume,varsta);
			Console.WriteLine("Message received  "+i);
			try
			{
				sendResponse(new ParticipantAdaugatResponse(mdto));
			}
			catch (Exception e)
			{
				throw new ChatException("Sending error: "+e);
			}
		}
		public virtual void inscriereEfectuata(Inscriere inscriere,string nume, int varsta)
		{
			InscriereDTO mdto = DTOUtils.getDTO(inscriere, nume, varsta);
			Console.WriteLine("Message received  " + inscriere);
			try
			{
				sendResponse(new ParticipantAdaugatResponse(mdto));
			}
			catch (Exception e)
			{
				throw new ChatException("Sending error: " + e);
			}
		}

		public virtual void loggedIn(Organizator user)
		{
			UserDTO udto =DTOUtils.getDTO(user);
			Console.WriteLine("Friend logged in "+user);
			try
			{
				sendResponse(new LoggedInResponse(udto));
			}
			catch (Exception e)
			{
                Console.WriteLine(e.StackTrace);
			}
		}

		public void refresh(Inscriere inscriere)
		{
			Console.WriteLine("Worker refresh");
		}


		private Response handleRequest(Request request)
		{
			Response response =null;
			if (request is LoginRequest)
			{
				Console.WriteLine("Login request ...");
				LoginRequest logReq =(LoginRequest)request;
				UserDTO udto =logReq.User;
				Organizator user =DTOUtils.getFromDTO(udto);
				try
                {
                    lock (server)
                    {
                        server.login(user, this);
                    }
					return new OkResponse();
				}
				catch (ChatException e)
				{
					connected=false;
					return new ErrorResponse(e.Message);
				}
			}
			if (request is AddParticipantRequest)
			{
				Console.WriteLine("SendMessageRequest ...");
				AddParticipantRequest addReq =(AddParticipantRequest)request;
				InscriereDTO mdto =addReq.InscriereDto;
				Inscriere inscriere =DTOUtils.getFromDTO(mdto);
				try
				{
                    lock (server)
                    {
                        server.addInscriere(mdto.Nume,mdto.Varsta,inscriere.IdProba);
                    }
                        return new OkResponse();
				}
				catch (ChatException e)
				{
					return new ErrorResponse(e.Message);
				}
			}
			if (request is GetLoggedFriendsRequest)
			{
				Console.WriteLine("GetLoggedFriends Request ...");
				GetLoggedFriendsRequest getReq = (GetLoggedFriendsRequest)request;
				UserDTO udto = getReq.User;
				Organizator user = DTOUtils.getFromDTO(udto);
				try
				{
					Organizator[] friends;
					lock (server)
					{

						friends = server.getLoggedFriends(user);
					}
					UserDTO[] frDTO = DTOUtils.getDTO(friends);
					return new GetLoggedFriendsResponse(frDTO);
				}
				catch (ChatException e)
				{
					return new ErrorResponse(e.Message);
				}
			}
			if (request is GetProbeRequest)
			{
				Console.WriteLine("GetProbe Request ...");
				GetProbeRequest getReq = (GetProbeRequest)request;
				UserDTO udto = getReq.User;
				Organizator user = DTOUtils.getFromDTO(udto);
				try
				{
					Proba[] friends;
					lock (server)
					{

						friends = server.getProbe(user);
					}
					ProbaDTO[] frDTO = DTOUtils.getDTO(friends);
					return new GetProbeResponse(frDTO);
				}
				catch (ChatException e)
				{
					return new ErrorResponse(e.Message);
				}
			}
			if (request is GetParticipantiRequest)
			{
				Console.WriteLine("GetParticipanti Request ...");
				GetParticipantiRequest getReq = (GetParticipantiRequest)request;
				UserDTO udto = getReq.User;
				Organizator user = DTOUtils.getFromDTO(udto);
				try
				{
					Participant[] friends;
					lock (server)
					{

						friends = server.getParticipanti(user);
					}
					ParticipantDTO[] frDTO = DTOUtils.getDTO(friends);
					return new GetParticipantiResponse(frDTO);
				}
				catch (ChatException e)
				{
					return new ErrorResponse(e.Message);
				}
			}
			if (request is GetInscrieriRequest)
			{
				Console.WriteLine("GetInscrieri Request ...");
				GetInscrieriRequest getReq = (GetInscrieriRequest)request;
				UserDTO udto = getReq.User;
				Organizator user = DTOUtils.getFromDTO(udto);
				try
				{
					Inscriere[] friends;
					lock (server)
					{

						friends = server.getInscrieri(user);
					}
					InscriereDTO2[] frDTO = DTOUtils.getDTO(friends);
					return new GetInscrieriResponse(frDTO);
				}
				catch (ChatException e)
				{
					return new ErrorResponse(e.Message);
				}
			}
			return response;
		}

	private void sendResponse(Response response)
		{
			Console.WriteLine("sending response "+response);
            formatter.Serialize(stream, response);
            stream.Flush();
			
		}
	}

}