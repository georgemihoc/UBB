package chat.network.utils;

import chat.network.protobuffprotocol.ProtoChatWorker;
import chat.services.IChatServer;

import java.net.Socket;


public class ChatProtobuffConcurrentServer extends AbsConcurrentServer {
    private IChatServer chatServer;
    public ChatProtobuffConcurrentServer(int port, IChatServer chatServer) {
        super(port);
        this.chatServer = chatServer;
        System.out.println("Chat- ChatProtobuffConcurrentServer");
    }

    @Override
    protected Thread createWorker(Socket client) {
        ProtoChatWorker worker=new ProtoChatWorker(chatServer,client);
        Thread tw=new Thread(worker);
        return tw;
    }
}