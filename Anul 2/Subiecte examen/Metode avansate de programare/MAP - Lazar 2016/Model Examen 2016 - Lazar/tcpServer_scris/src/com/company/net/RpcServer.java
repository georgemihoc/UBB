package com.company.net;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;
import java.util.concurrent.ExecutorService;

/**
 * Created by Narcis2007 on 13.01.2016.
 */
public class RpcServer {
    private ConcurrentMap<String, Handler> handlers=new ConcurrentHashMap<>();
    ExecutorService executorService;
    private boolean running =true;

    public RpcServer(ExecutorService executorService) {
        this.executorService=executorService;
    }

//    public void test() {
//        try {
//            ServerSocket serverSocket =new ServerSocket(8000);
//            while(true){
//                Socket socket = serverSocket.accept();
//                InputStream is=socket.getInputStream();
//                OutputStream os=socket.getOutputStream();
//                PrintWriter writer=new PrintWriter(os);
//
//                BufferedReader reader=new BufferedReader(new InputStreamReader(is));
//                String s=reader.readLine();
//                s=s+" world";
//                writer.println(s);
//                writer.flush();
//
//
//            }
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//    }

    public void start() {
        try {
            ServerSocket serverSocket =new ServerSocket(8000);
            while(running){
                executorService.submit(new RpcHandler(serverSocket.accept()));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void handle(String name, Handler method) {
        handlers.put(name,method);
    }
    private class RpcHandler implements Runnable{
        private Socket socket;

        public RpcHandler(Socket socket){

            this.socket = socket;
        }

        @Override
        public void run() {

                try {
                    InputStream is = socket.getInputStream();

                    OutputStream os = socket.getOutputStream();
                    PrintWriter writer = new PrintWriter(os);

                    BufferedReader reader = new BufferedReader(new InputStreamReader(is));
                    System.out.println("about to read data");
                    String s = reader.readLine();
                    System.out.println("received data");
                    String method = s.split(":")[0];
                    String data = s.split(":")[1];

                    writer.println(handlers.get(method).handle(data));
                    writer.flush();
//                    handlers.get("notify").handle(data);

                } catch (IOException e) {
                    e.printStackTrace();
                }
        }
    }
}
