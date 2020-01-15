package tcpClient.service;

import tcpClient.model.MessengerObserver;
import tcpClient.model.MyMessage;
import tcpClient.model.User;
import tcpClient.net.TcpClient;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Future;

/**
 * Created by Narcis2007 on 15.01.2016.
 */
public class MessengerService {
    private ExecutorService executorService;
    private TcpClient tcpClient;

    public MessengerService(ExecutorService executorService, TcpClient rpcClient) {
        this.executorService = executorService;

        this.tcpClient = rpcClient;
    }

    public boolean login(String username) {
        String status= tcpClient.sendAndReceive("login",username);
        System.out.println(status);
        if(status.equals("logged")) {
            executorService.submit(()->tcpClient.startListening());
            return true;
        }
        return false;
    }

    public void setObserver(MessengerObserver messengerObserver) {
        tcpClient.setObserver(messengerObserver);
    }

    public void getUsers(AsyncCallback<List<User>> asyncCallback) {
        String[] users=tcpClient.sendAndReceive("getUsers",null).split(";");
        List<User> userList=new ArrayList<>();
        for(String userAndStatus:users)
            userList.add(new User(userAndStatus));
        asyncCallback.onSuccess(userList);
    }

    public void logout(String username,AsyncCallback<User> asyncCallback) {
        String usernameAndStatus=tcpClient.sendAndReceive("logout",username);
        asyncCallback.onSuccess(new User(usernameAndStatus));
    }


    public Future<MyMessage> send(String username, String text) {
        return executorService.submit(()->{
            String usernameAndText=tcpClient.sendAndReceive("send",text);
            return new MyMessage(usernameAndText);
        });
    }
}
