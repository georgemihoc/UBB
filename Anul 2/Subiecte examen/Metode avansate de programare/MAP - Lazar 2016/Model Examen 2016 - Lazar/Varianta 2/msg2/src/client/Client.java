package client;

import client.net.TcpClient;
import client.service.MessengerClient;
import client.ui.ConsoleUi;

public class Client {

    public static void main(String[] args) {
        System.out.println(">java Client user - to start\nuser::text - to send a message\nquit - to quit");
        new ConsoleUi(args[0],  new MessengerClient(new TcpClient())).run();
    }
}
