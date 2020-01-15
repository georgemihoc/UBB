package com.company.service;

import com.company.model.User;
import com.company.net.NotificationServer;
import com.company.net.RpcServer;
import com.company.repository.Repository;

import java.util.List;

/**
 * Created by Narcis2007 on 15.01.2016.
 */
public class MessengerService {

    private NotificationServer notificationServer;
    private RpcServer rpcServer;
    private Repository repository;

    public MessengerService(RpcServer rpcServer, NotificationServer notificationServer, Repository repository) {
        this.notificationServer=notificationServer;
        this.rpcServer = rpcServer;
        this.repository = repository;



        rpcServer.handle("test",(data)->{
                System.out.println("test succeeded :"+data);
            return null;
        });

        rpcServer.handle("login",(data)->{
            System.out.println("login:"+data);
            if(changeUserStatus(data).equals("ok")){
                notificationServer.notifyClients("user:"+data+":online");
                return "logged";
            }
            return "bad";
        });

        rpcServer.handle("getUsers",(data)->{
            System.out.println("getting users");
            List<User> users=repository.getUsers();
            String usersString = "";
            for(User u:users)
                usersString=usersString+u.getUsername()+":"+u.getStatus()+";";
            return usersString;
        });

        rpcServer.handle("logout",(data)->{
            System.out.println("logging out "+data);
            User user=repository.findByUsername(data);
            if(user!=null) {
                user.setStatus("offline");
                return user.toString();
            }
            return "bad";
        });

        rpcServer.handle("send",(data)->{
            System.out.println("sending message "+data);
            notificationServer.notifyClients("message:"+data);
            return data;
        });







    }

    private String changeUserStatus(String data) {
        User u=repository.findByUsername(data);
        if(u==null)
            return "bad";
        u.setStatus("online");
        return "ok";
//        return data+":"+"online";
    }

    public void start() {
        rpcServer.start();
    }
}
