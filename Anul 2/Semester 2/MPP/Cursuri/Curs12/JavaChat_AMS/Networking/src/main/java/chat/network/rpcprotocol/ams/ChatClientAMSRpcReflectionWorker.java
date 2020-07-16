package chat.network.rpcprotocol.ams;

import chat.model.Message;
import chat.model.User;
import chat.network.dto.DTOUtils;
import chat.network.dto.MessageDTO;
import chat.network.dto.UserDTO;
import chat.network.rpcprotocol.Request;
import chat.network.rpcprotocol.Response;
import chat.network.rpcprotocol.ResponseType;
import chat.services.ChatException;
import chat.services.IChatClient;
import chat.services.IChatServer;
import chat.services.IChatServicesAMS;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.net.Socket;

/**
 * Created by grigo on 3/26/16.
 */
public class ChatClientAMSRpcReflectionWorker implements Runnable {
    private IChatServicesAMS server;
    private Socket connection;

    private ObjectInputStream input;
    private ObjectOutputStream output;
    private volatile boolean connected;
    public ChatClientAMSRpcReflectionWorker(IChatServicesAMS server, Socket connection) {
        this.server = server;
        this.connection = connection;
        try{
            output=new ObjectOutputStream(connection.getOutputStream());
            output.flush();
            input=new ObjectInputStream(connection.getInputStream());
            connected=true;
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void run() {
        while(connected){
            try {
                Object request=input.readObject();
                System.out.println("Received request");
                Response response=handleRequest((Request)request);
                if (response!=null){
                    sendResponse(response);
                }
            } catch (IOException|ClassNotFoundException e) {
                e.printStackTrace();
            }
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        try {
            input.close();
            output.close();
            connection.close();
        } catch (IOException e) {
            System.out.println("Error "+e);
        }
    }





    private static Response okResponse=new Response.Builder().type(ResponseType.OK).build();
    //  private static Response errorResponse=new Response.Builder().type(ResponseType.ERROR).build();
    private Response handleRequest(Request request){
        Response response=null;
        String handlerName="handle"+(request).type();
        System.out.println("HandlerName "+handlerName);
        try {
            Method method=this.getClass().getDeclaredMethod(handlerName, Request.class);
            response=(Response)method.invoke(this,request);
            System.out.println("Method "+handlerName+ " invoked");
        } catch (NoSuchMethodException|InvocationTargetException|IllegalAccessException e) {
            e.printStackTrace();
        }
        return response;
    }

    private Response handleLOGIN(Request request){
        System.out.println("Login request ..."+request.type());
        UserDTO udto=(UserDTO)request.data();
        User user=DTOUtils.getFromDTO(udto);
        try {
            server.login(user);
            return okResponse;
        } catch (ChatException e) {
            connected=false;
            return new Response.Builder().type(ResponseType.ERROR).data(e.getMessage()).build();
        }
    }

    private Response handleLOGOUT(Request request){
        System.out.println("Logout request...");
        UserDTO udto=(UserDTO)request.data();
        User user=DTOUtils.getFromDTO(udto);
        try {
            server.logout(user);
            connected=false;
            return okResponse;

        } catch (ChatException e) {
            return new Response.Builder().type(ResponseType.ERROR).data(e.getMessage()).build();
        }
    }


    private Response handleSEND_MESSAGE_ALL(Request request){
        System.out.println("SendMessageAllRequest ...");
        MessageDTO mdto=(MessageDTO)request.data();
        Message message=DTOUtils.getFromDTO(mdto);
        try {
            server.sendMessageToAll(message);
            return okResponse;
        } catch (ChatException e) {
            return new Response.Builder().type(ResponseType.ERROR).data(e.getMessage()).build();
        }


    }

    private Response handleGET_LOGGED_USERS(Request request){
        System.out.println("GetLoggedFriends Request ...");
        try {
            User[] friends=server.getLoggedUsers();
            UserDTO[] frDTO=DTOUtils.getDTO(friends);
            return new Response.Builder().type(ResponseType.GET_LOGGED_USERS).data(frDTO).build();
        } catch (ChatException e) {
            return new Response.Builder().type(ResponseType.ERROR).data(e.getMessage()).build();
        }
    }

    private void sendResponse(Response response) throws IOException{
        System.out.println("sending response "+response);
        output.writeObject(response);
        output.flush();
    }
}
