package com.company;

import com.company.net.NotificationServer;
import com.company.net.RpcServer;
import com.company.repository.Repository;
import com.company.service.MessengerService;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {

    public static void main(String[] args) {

        ExecutorService executorService = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());
        RpcServer rpcServer = new RpcServer(executorService);
        NotificationServer notificationServer=new NotificationServer(executorService);
        MessengerService service=new MessengerService(rpcServer,notificationServer,new Repository());
        service.start();


    }
}
