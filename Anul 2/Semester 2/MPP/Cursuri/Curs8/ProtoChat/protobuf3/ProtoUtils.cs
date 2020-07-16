using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using chat.services;
using chat.model;
using Chat.Protocol;
using proto=Chat.Protocol;
namespace protobuf
{
    static class ProtoUtils
    {
        public static ChatRequest createLoginRequest(chat.model.User user)
        {
            //new proto.User {Id = user.Id, Passwd = user.Password};
            proto.User userDTO = new proto.User {Id = user.Id, Passwd = user.Password};
            ChatRequest request = new ChatRequest{Type = ChatRequest.Types.Type.Login, User = userDTO};
              
            return request;
        }

        public static ChatRequest createLogoutRequest(chat.model.User user)
        {
            proto.User userDTO = new proto.User {Id = user.Id};
            ChatRequest request = new ChatRequest{Type=ChatRequest.Types.Type.Logout, User = userDTO};
            return request;
        }
        public static ChatRequest createSendMesssageRequest(chat.model.Message message)
        {
            proto.Message messageDTO = new proto.Message
            {
                SenderId = message.Sender.Id,
                ReceiverId = message.Receiver.Id,
                Text = message.Text
            };
               
            ChatRequest request = new ChatRequest{  Type=ChatRequest.Types.Type.SendMessage, Message=messageDTO};
            return request;
        }

       
        public static ChatRequest createLoggedFriendsRequest(chat.model.User user)
        {
            proto.User userDTO = new proto.User{Id=user.Id};
            ChatRequest request = new ChatRequest
            {
                Type = ChatRequest.Types.Type.GetLoggedFriends,
                User = userDTO
            };
            return request;
        }


        public static ChatResponse createOkResponse()
        {
            ChatResponse response = new ChatResponse{ Type=ChatResponse.Types.Type.Ok};
            return response;
        }

        
        public static ChatResponse createErrorResponse(String text)
        {
            ChatResponse response = new ChatResponse{
                Type=ChatResponse.Types.Type.Error, Error=text};
            return response;
        }
        
        public static ChatResponse createFriendLoggedInResponse(chat.model.User user)
        {
            proto.User userDTO = new proto.User{ Id=user.Id};                                    
            ChatResponse response = new ChatResponse{ Type=ChatResponse.Types.Type.FriendLoggedIn, User=userDTO};
            return response;
        }
        
        public static ChatResponse createFriendLoggedOutResponse(chat.model.User user)
        {
            proto.User userDTO = new proto.User {Id = user.Id};
            ChatResponse response = new ChatResponse {Type = ChatResponse.Types.Type.FriendLoggedOut, User = userDTO};
            return response;
        }

        public static ChatResponse createNewMessageResponse(chat.model.Message message)
        {
            proto.Message messageDTO = new proto.Message
            {
                SenderId = message.Sender.Id,
                ReceiverId = message.Receiver.Id,
                Text = message.Text
            };

            ChatResponse response = new ChatResponse { Type=ChatResponse.Types.Type.NewMessage,Message=messageDTO};
        return response;
        }


        public static ChatResponse createLoggedFriendsResponse(chat.model.User[] users)
        {
            ChatResponse response = new ChatResponse { 
                Type=ChatResponse.Types.Type.GetLoggedFriends
        };
            foreach (chat.model.User user in users)
            {
                proto.User userDTO = new proto.User {Id = user.Id};
            
                response.Friends.Add(userDTO);
            }

            return response;
        }
        
        public static String getError(ChatResponse response)
        {
            String errorMessage = response.Error;
            return errorMessage;
        }
        
        public static chat.model.User getUser(ChatResponse response)
        {
            chat.model.User user = new chat.model.User(response.User.Id);
            return user;
        }

        
        public static chat.model.Message getMessage(ChatResponse response)
        {
            chat.model.User sender = new chat.model.User(response.Message.SenderId);
            chat.model.User receiver = new chat.model.User(response.Message.ReceiverId);
            chat.model.Message message = new chat.model.Message(sender, receiver, response.Message.Text);
            return message;
        }
        
        public static chat.model.User[] getFriends(ChatResponse response)
        {
            chat.model.User[] friends = new chat.model.User[response.Friends.Count];
            for (int i = 0; i < response.Friends.Count; i++)
            {
                chat.model.User user = new chat.model.User(response.Friends[i].Id);
                friends[i] = user;
            }
            return friends;
        }
        
        public static chat.model.User getUser(ChatRequest request)
        {
            chat.model.User user = new chat.model.User(request.User.Id);
            user.Password = request.User.Passwd;
            return user;
        }
        public static chat.model.Message getMessage(ChatRequest request)
        {
            chat.model.User sender = new chat.model.User(request.Message.SenderId);
            chat.model.User receiver = new chat.model.User(request.Message.ReceiverId);
            chat.model.Message message = new chat.model.Message(sender, receiver, request.Message.Text);
            return message;
        }
         
    }
}