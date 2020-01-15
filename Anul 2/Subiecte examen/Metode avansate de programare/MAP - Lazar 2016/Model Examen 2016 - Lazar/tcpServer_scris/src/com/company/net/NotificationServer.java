package com.company.net;


import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.ExecutorService;

/**
 * Created by Narcis2007 on 15.01.2016.
 */
public class NotificationServer {

    private ExecutorService executorService;
    private List<NotificationHandler> handlers= Collections.synchronizedList(new ArrayList<>());

    public NotificationServer(ExecutorService executorService){
        this.executorService = executorService;
        try {
            ServerSocket sSocket = new ServerSocket(8081);
            executorService.submit(()->{
                while(true){

                    handlers.add(new NotificationHandler(sSocket.accept()));
                    System.out.println("notification handler added"+handlers.size());
                }

            });
        } catch (IOException e) {
            e.printStackTrace();
        }


    }
    public void notifyClients(String data){
//            synchronized (handlers) {
                System.out.println("notifyClients:" + data + handlers.size());
//                for (int i = handlers.size() - 1; i >= 0; i--) {
//                    System.out.println("clients notified:" + i);
//                    handlers.get(i).write(data);
//                    handlers.get(i).close();
//                    handlers.remove(i);
//                }
                handlers.forEach((h)->{
                    h.write(data);
//                    h.close();
                });
                //handlers.clear();
//            }

    }
    private class NotificationHandler{

        private  PrintWriter printWriter;
        private Socket socket;

        public NotificationHandler(Socket socket) throws IOException {

            this.socket = socket;
            printWriter=new PrintWriter(socket.getOutputStream());
        }


        public void write(String data) {
            System.out.println("ready to send notification data");
            printWriter.println(data);
            printWriter.flush();
            System.out.println("sent notification "+data);

        }

        public void close() {
            try {
                socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }

        }
    }
}
