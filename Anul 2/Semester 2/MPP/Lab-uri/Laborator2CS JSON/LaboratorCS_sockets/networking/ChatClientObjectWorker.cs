using System;
using System.Collections.Generic;
using System.Threading;
using System.Net.Sockets;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using Chat.Protocol;
using Google.Protobuf;
using Newtonsoft.Json;
using Newtonsoft.Json.Serialization;
using swim.services;
using swim.model;
using swim.network.dto;
using swim.network.protocol;
namespace swim.networking
{
	
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
                    Console.WriteLine("SALUT");
                    ChatRequest request = ChatRequest.Parser.ParseDelimitedFrom(stream);
                    Console.WriteLine("SAL");
                    ChatResponse response =handleRequest(request);
                    if (response!=null)
                    {
                        sendResponse( response);
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
            var serializerSettings = new JsonSerializerSettings();
            serializerSettings.ContractResolver = new CamelCasePropertyNamesContractResolver();
            
            InscriereDTO mdto = DTOUtils.getDTO(inscriere, nume, varsta);
            Console.WriteLine("Message received  " + inscriere);
            try
            {
                String JSONString = JsonConvert.SerializeObject(mdto,serializerSettings);
                Message message = new Message {JSonString = JSONString};
                ChatResponse response = new ChatResponse { Type=ChatResponse.Types.Type.ParticipantInscris,MessageAdd= message};
                
                sendResponse(response);
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

        private ChatResponse handleRequest(ChatRequest request)
        {
            Console.WriteLine("WHAT REQUEST");
            ChatResponse response = null;
            ChatRequest.Types.Type reqType = request.Type;
            switch (reqType)
            {
                case ChatRequest.Types.Type.Login:
                {
                    Console.WriteLine("Login request ...");
                    String JSONString = request.Message.JSonString;
                    Organizator user = JsonConvert.DeserializeObject<Organizator>(JSONString);
                    try
                    {
                        lock (server)
                        {
                            Console.WriteLine(user.Username + user.Password);
                            server.login(user.Username, user.Password, this);
                        }

                        return new ChatResponse {Type = ChatResponse.Types.Type.Ok};
                    }
                    catch (ChatException e)
                    {
                        connected = false;
                        return new ChatResponse
                        {
                            Type = ChatResponse.Types.Type.Error, Error = e.Message
                        };
                    }
                }
                //              case ChatRequest.Types.Type.SendMessage:
                // {
                // 	Console.WriteLine("SendMessageRequest ...");
                //              chat.model.Message message = ProtoUtils.getMessage(request);
                // 	try
                // 	{
                //                  lock (server)
                //                  {
                //                      server.sendMessage(message);
                //                  }
                //                      return ProtoUtils.createOkResponse();
                // 	}
                // 	catch (ChatException e)
                // 	{
                // 		return ProtoUtils.createErrorResponse(e.Message);
                // 	}
                // }

                case ChatRequest.Types.Type.GetProbe:
                {
                    Console.WriteLine("GetProbe Request ...");
                    // chat.model.User user = ProtoUtils.getUser(request);  //DTOUtils.getFromDTO(udto);
                    try
                    {
                        List<String> probe;
                        lock (server)
                        {

                            probe = server.getProbe(new Organizator(0, "", ""));
                        }

                        ChatResponse responseProto = new ChatResponse
                        {
                            Type = ChatResponse.Types.Type.GetProbe
                        };
                        foreach (var VARIABLE in probe)
                        {
                            responseProto.Message.Add(new Message {JSonString = VARIABLE});
                        }

                        return responseProto;
                    }
                    catch (ChatException e)
                    {
                        return new ChatResponse
                        {
                            Type = ChatResponse.Types.Type.Error, Error = e.Message
                        };
                    }
                }
                case ChatRequest.Types.Type.GetParticipanti:
                {
                    Console.WriteLine("GetParticipanti Request ...");
                    // chat.model.User user = ProtoUtils.getUser(request);  //DTOUtils.getFromDTO(udto);
                    try
                    {
                        List<String> participanti;
                        lock (server)
                        {

                            participanti = server.getParticipanti(new Organizator(0, "", ""));
                        }

                        ChatResponse responseProto = new ChatResponse
                        {
                            Type = ChatResponse.Types.Type.GetParticipanti
                        };
                        foreach (var VARIABLE in participanti)
                        {
                            responseProto.Message.Add(new Message {JSonString = VARIABLE});
                        }

                        return responseProto;
                    }
                    catch (ChatException e)
                    {
                        return new ChatResponse
                        {
                            Type = ChatResponse.Types.Type.Error, Error = e.Message
                        };
                    }
                }
                case ChatRequest.Types.Type.GetInscrieri:
                {
                    Console.WriteLine("GetInscrieri Request ...");
                    // chat.model.User user = ProtoUtils.getUser(request);  //DTOUtils.getFromDTO(udto);
                    try
                    {
                        List<String> inscrieri;
                        lock (server)
                        {

                            inscrieri = server.getInscrieri(new Organizator(0, "", ""));
                        }

                        ChatResponse responseProto = new ChatResponse
                        {
                            Type = ChatResponse.Types.Type.GetInscrieri
                        };
                        foreach (var VARIABLE in inscrieri)
                        {
                            responseProto.Message.Add(new Message {JSonString = VARIABLE});
                        }

                        return responseProto;
                    }
                    catch (ChatException e)
                    {
                        return new ChatResponse
                        {
                            Type = ChatResponse.Types.Type.Error, Error = e.Message
                        };
                    }
                    
                }
                case ChatRequest.Types.Type.AddInscriere:
                {
                    Console.WriteLine("SendMessageRequest ...");
                    InscriereDTO inscriereDto = JsonConvert.DeserializeObject<InscriereDTO>(request.Message.JSonString);
                    Console.WriteLine("TEST WORKER ADD INSCRIERE"+inscriereDto.Nume + inscriereDto.Varsta);
                    try
                    {
                        lock (server)
                        {
                            server.addInscriere(inscriereDto.Nume, inscriereDto.Varsta, inscriereDto.IdProba);
                        }

                        return new ChatResponse {Type = ChatResponse.Types.Type.Ok};
                    }
                    catch (ChatException e)
                    {
                        return new ChatResponse
                        {
                            Type = ChatResponse.Types.Type.Error, Error = e.Message
                        };
                    }
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
        private void sendResponse(ChatResponse response)
        {
            Console.WriteLine("sending response "+response);
            lock (stream)
            {
                response.WriteDelimitedTo(stream);
                stream.Flush();
            }

        }
    }
}