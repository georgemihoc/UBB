using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using chat.services;
using chat.model;
using chat.protocol.protobuf;
using proto=chat.protocol.protobuf;
namespace protobuf
{
    static class ProtoUtils
    {
        public static ChatRequest createLoginRequest(chat.model.User user)
        {
            proto.User userDTO = proto.User.CreateBuilder().SetId(user.Id).SetPasswd(user.Password).Build();
            ChatRequest request = ChatRequest.CreateBuilder().SetType(ChatRequest.Types.Type.Login)
                    .SetUser(userDTO).Build();
            return request;
        }

        public static ChatRequest createLogoutRequest(chat.model.User user)
        {
            proto.User userDTO = proto.User.CreateBuilder().SetId(user.Id).Build();
            ChatRequest request = ChatRequest.CreateBuilder().SetType(ChatRequest.Types.Type.Logout)
                 .SetUser(userDTO).Build();
            return request;
         }
                public static ChatRequest createSendMesssageRequest(chat.model.Message message)
                {
                    proto.Message messageDTO = proto.Message.CreateBuilder().
                            SetSenderId(message.Sender.Id)
                            .SetReceiverId(message.Receiver.Id)
                            .SetText(message.Text).Build();
                    ChatRequest request = ChatRequest.CreateBuilder()
                            .SetType(ChatRequest.Types.Type.SendMessage)
                            .SetMessage(messageDTO).Build();
                    return request;
                }

       
                public static ChatRequest createLoggedFriendsRequest(chat.model.User user)
                {
                    proto.User userDTO = proto.User.CreateBuilder().SetId(user.Id).Build();
                    ChatRequest request = ChatRequest.CreateBuilder().SetType(ChatRequest.Types.Type.GetLoggedFriends)
                         .SetUser(userDTO).Build();
                    return request;
                }


                 public static ChatResponse createOkResponse()
                {
                    ChatResponse response = ChatResponse.CreateBuilder()
                            .SetType(ChatResponse.Types.Type.Ok).Build();
                    return response;
                }

        
                public static ChatResponse createErrorResponse(String text)
                {
                    ChatResponse response = ChatResponse.CreateBuilder()
                            .SetType(ChatResponse.Types.Type.Error)
                            .SetError(text).Build();
                    return response;
                }
        
                public static ChatResponse createFriendLoggedInResponse(chat.model.User user)
                {
                    proto.User userDTO = proto.User.CreateBuilder().SetId(user.Id).Build();                                    
                    ChatResponse response = ChatResponse.CreateBuilder()
                            .SetType(ChatResponse.Types.Type.FriendLoggedIn)
                            .SetUser(userDTO).Build();
                    return response;
                }
        
                public static ChatResponse createFriendLoggedOutResponse(chat.model.User user)
                {
                    proto.User userDTO = proto.User.CreateBuilder().SetId(user.Id).Build();                                    
                    ChatResponse response = ChatResponse.CreateBuilder()
                            .SetType(ChatResponse.Types.Type.FriendLoggedOut)
                            .SetUser(userDTO).Build();
                    return response;
                }

                public static ChatResponse createNewMessageResponse(chat.model.Message message)
                 {
                     proto.Message messageDTO = proto.Message.CreateBuilder().
                            SetSenderId(message.Sender.Id)
                            .SetReceiverId(message.Receiver.Id)
                            .SetText(message.Text).Build();
                   
                     ChatResponse response = ChatResponse.CreateBuilder()
                             .SetType(ChatResponse.Types.Type.NewMessage)
                             .SetMessage(messageDTO).Build();
                     return response;
                 }

         
           public static ChatResponse createLoggedFriendsResponse(chat.model.User[] users){
                 ChatResponse.Builder response=ChatResponse.CreateBuilder()
                         .SetType(ChatResponse.Types.Type.GetLoggedFriends);
                 foreach (chat.model.User user in users){
                    proto.User userDTO = proto.User.CreateBuilder().SetId(user.Id).Build();                                    
                     response.AddFriends(userDTO);
                 }

                 return response.Build();
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
                     chat.model.User[] friends = new chat.model.User[response.FriendsCount];
                     for (int i = 0; i < response.FriendsCount; i++)
                     {
                         chat.model.User user = new chat.model.User(response.FriendsList[i].Id);
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
