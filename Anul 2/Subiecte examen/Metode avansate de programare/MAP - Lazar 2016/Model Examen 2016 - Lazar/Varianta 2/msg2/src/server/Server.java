package server;

import model.Message;
import model.User;
import server.net.NotificationServer;
import server.net.RpcServer;
import server.repository.UserRepository;
import server.service.MessengerService;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;
import java.util.concurrent.*;

public class Server {
    public static void main(String[] args) throws IOException {
        ExecutorService executorService = Executors.newFixedThreadPool(4);
        RpcServer rpcServer = new RpcServer(executorService);
        new MessengerService(new UserRepository(), rpcServer, new NotificationServer(executorService));
        rpcServer.start();
    }

}
