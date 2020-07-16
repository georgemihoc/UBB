using System;
using System.Threading;
using System.Net.Sockets;

using chat.services;
using Chat.Protocol;
using Google.Protobuf;

namespace protobuf
{
   public class ProtoV3ChatWorker:IChatObserver
    {
        private IChatServer server;
		private TcpClient connection;

		private NetworkStream stream;
		private volatile bool connected;
		public ProtoV3ChatWorker(IChatServer server, TcpClient connection)
		{
			this.server = server;
			this.connection = connection;
			try
			{
				
				stream=connection.GetStream();
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
					
                    ChatRequest request = ChatRequest.Parser.ParseDelimitedFrom(stream);
                    Console.WriteLine("Request parsed");
					ChatResponse response =handleRequest(request);
					if (response!=null)
					{
					   sendResponse(response);
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
		public virtual void messageReceived(chat.model.Message message)
		{
			Console.WriteLine("Message received  "+message);
			try
			{
				sendResponse(ProtoUtils.createNewMessageResponse(message));
			}
			catch (Exception e)
			{
				throw new ChatException("Sending error: "+e);
			}
		}

	public virtual void friendLoggedIn(chat.model.User friend)
		{
			Console.WriteLine("Friend logged in "+friend);
			try
			{
				sendResponse(ProtoUtils.createFriendLoggedInResponse(friend));
			}
			catch (Exception e)
			{
                Console.WriteLine(e.StackTrace);
			}
		}
		public virtual void friendLoggedOut(chat.model.User friend)
		{
			Console.WriteLine("Friend logged out "+friend);
			try
			{
				sendResponse(ProtoUtils.createFriendLoggedOutResponse(friend));
			}
			catch (Exception e)
			{
                Console.WriteLine(e.StackTrace);
			}
		}

		private ChatResponse handleRequest(ChatRequest request)
		{
			ChatResponse response =null;
            ChatRequest.Types.Type reqType=request.Type;
            switch(reqType){
                case ChatRequest.Types.Type.Login:
			{
				Console.WriteLine("Login request ...");
				chat.model.User user =ProtoUtils.getUser(request);
				try
                {
                    lock (server)
                    {
                        server.login(user, this);
                    }
					return ProtoUtils.createOkResponse();
				}
				catch (ChatException e)
				{
					connected=false;
					return ProtoUtils.createErrorResponse(e.Message);
				}
			}
                case ChatRequest.Types.Type.Logout:
			{
				Console.WriteLine("Logout request");
                chat.model.User user = ProtoUtils.getUser(request);
				try
				{
                    lock (server)
                    {

                        server.logout(user, this);
                    }
					connected=false;
					return ProtoUtils.createOkResponse();

				}
				catch (ChatException e)
				{
				   return ProtoUtils.createErrorResponse(e.Message);
				}
			}
                case ChatRequest.Types.Type.SendMessage:
			{
				Console.WriteLine("SendMessageRequest ...");
                chat.model.Message message = ProtoUtils.getMessage(request);
				try
				{
                    lock (server)
                    {
                        server.sendMessage(message);
                    }
                        return ProtoUtils.createOkResponse();
				}
				catch (ChatException e)
				{
					return ProtoUtils.createErrorResponse(e.Message);
				}
			}

                case ChatRequest.Types.Type.GetLoggedFriends:
			{
				Console.WriteLine("GetLoggedFriends Request ...");
                chat.model.User user = ProtoUtils.getUser(request);  //DTOUtils.getFromDTO(udto);
				try
				{
                    chat.model.User[] friends;
                    lock (server)
                    {

                         friends = server.getLoggedFriends(user);
                    }
					return ProtoUtils.createLoggedFriendsResponse(friends);
				}
				catch (ChatException e)
				{
					return ProtoUtils.createErrorResponse(e.Message);
				}
			}
            }
			return response;
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
