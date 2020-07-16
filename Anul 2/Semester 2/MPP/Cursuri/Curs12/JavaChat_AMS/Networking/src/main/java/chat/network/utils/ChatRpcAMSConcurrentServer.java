package chat.network.utils;

import chat.network.rpcprotocol.ams.ChatClientAMSRpcReflectionWorker;
import chat.services.IChatServicesAMS;

import java.net.Socket;

/**
 * Created by grigo on 5/2/17.
 */
public class ChatRpcAMSConcurrentServer extends AbsConcurrentServer {
    private IChatServicesAMS chatServer;
    public ChatRpcAMSConcurrentServer(int port, IChatServicesAMS chatServer) {
        super(port);
        this.chatServer = chatServer;
        System.out.println("Chat- ChatRpcAMSConcurrentServer port "+port);
    }

    @Override
    protected Thread createWorker(Socket client) {
        ChatClientAMSRpcReflectionWorker worker=new ChatClientAMSRpcReflectionWorker(chatServer, client);

        Thread tw=new Thread(worker);
        return tw;
    }
}
