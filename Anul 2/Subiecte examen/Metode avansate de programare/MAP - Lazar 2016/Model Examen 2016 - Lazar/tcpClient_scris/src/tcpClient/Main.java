package tcpClient;

import tcpClient.net.TcpClient;
import tcpClient.service.MessengerService;
import tcpClient.ui.ConsoleUI;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;


public class Main {

    public static void main(String[] args) {
//	    new TcpClient().test();
        ExecutorService executorService= Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());
        new ConsoleUI("narcis",new MessengerService(executorService,new TcpClient())).run();
    }
}
