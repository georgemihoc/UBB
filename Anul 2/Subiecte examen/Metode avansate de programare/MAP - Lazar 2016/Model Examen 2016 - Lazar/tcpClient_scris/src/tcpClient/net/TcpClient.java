package tcpClient.net;

import tcpClient.model.MessengerObserver;
import tcpClient.model.MyMessage;
import tcpClient.model.User;

import java.io.*;
import java.net.Socket;

/**
 * Created by Narcis2007 on 13.01.2016.
 */
public class TcpClient {
    private Socket notificationSocket;
    private MessengerObserver observer;
    private boolean listening;

    public TcpClient(){
        try {
            notificationSocket = new Socket("localhost", 8081);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public void test() {
        try {
            Socket socket =new Socket("localhost",7000);
            InputStream is=socket.getInputStream();
            OutputStream os =socket.getOutputStream();
            PrintWriter writer=new PrintWriter(os);
            writer.println("test:hello");
            writer.flush();
            BufferedReader reader = new BufferedReader(new InputStreamReader(is));
            System.out.println(reader.readLine());
        } catch (IOException e) {

        }
    }

    public String sendAndReceive(String method, String username) {
        PrintWriter writer;
        BufferedReader reader;
        String data = null;
        try {
            System.out.println("creating a socket");
            Socket socket = new Socket("localhost", 8000);
            writer=new PrintWriter(socket.getOutputStream());
            reader=new BufferedReader(new InputStreamReader(socket.getInputStream()));
            System.out.println("reader writer");

        System.out.println("send data");
        writer.println(method+":"+username);
        writer.flush();

        try {
            System.out.println("about to read data");
            data = reader.readLine();
            System.out.println("received:"+data);

        } catch (IOException e) {
            e.printStackTrace();
        } } catch (IOException e) {
        e.printStackTrace();
    }
        return data;
    }

    public void startListening() {
        try {

            BufferedReader reader = new BufferedReader(new InputStreamReader(notificationSocket.getInputStream()));
            listening=true;
            System.out.println("listening");
            while(listening){
                System.out.println("ready to read notification data");
                String data=reader.readLine();
                System.out.println("notification received:"+data);
                if (data.split(":")[0].equals("user"))
                        observer.update(new User(data.split(":")[1], data.split(":")[2]));
                if (data.split(":")[0].equals("message"))
                        observer.update(new MyMessage(data.split(":")[1]));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void setObserver(MessengerObserver messengerObserver) {
        this.observer=messengerObserver;
    }
}
