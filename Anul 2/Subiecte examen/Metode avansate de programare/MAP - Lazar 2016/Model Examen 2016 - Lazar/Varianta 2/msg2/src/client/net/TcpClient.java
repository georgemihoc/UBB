package client.net;

import model.Message;
import model.MessengerObserver;
import model.User;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class TcpClient {
    private MessengerObserver messengerObserver;
    private boolean listening;
    private Socket listeningSocket;

    public String sendAndReceive(String what, String args) throws Exception { // (what, args) -> result
        Socket socket = new Socket("localhost", 1234);
        PrintWriter printer = new PrintWriter(socket.getOutputStream());
        printer.println(what);
        printer.println(args);
        printer.flush();
        BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        String code = reader.readLine(); // success or exception
        String body = reader.readLine(); // result or exception message
        reader.close();
        printer.close();
        socket.close();
        if (code.equalsIgnoreCase("ok")) {
            return body;
        } else {
            throw new Exception(body);
        }
    }

    public void setMessengerObserver(MessengerObserver messengerObserver) {
        this.messengerObserver = messengerObserver;
    }

    public void startListening() {
        try {
            listeningSocket = new Socket("localhost", 1235);
            BufferedReader reader = new BufferedReader(new InputStreamReader(listeningSocket.getInputStream()));
            listening = true;
            while (listening) {
                String notification = reader.readLine(); // user:alex:true, message:alex:pauza?
                if (notification.startsWith("user")) {
                    messengerObserver.update(new User(notification.substring(6)));
                } else {
                    messengerObserver.update(new Message(notification.substring(8)));
                }
            }
            reader.close();
            listeningSocket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void stopListening() {
        listening = false;
        try {
            listeningSocket.close();
        } catch (IOException ignore) {
            ignore.printStackTrace();
        }
    }
}
