import chat.network.utils.AbstractServer;
import chat.network.utils.ChatRpcAMSConcurrentServer;
import chat.network.utils.ServerException;
import org.springframework.context.support.ClassPathXmlApplicationContext;


/**
 * Created by grigo on 5/2/17.
 */
public class StartAMSRpcServer {
    public static void main(String[] args) {
        ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("spring-server.xml");
        AbstractServer server=context.getBean("chatTCPServer",ChatRpcAMSConcurrentServer.class);
        try {
            server.start();
        } catch (ServerException e) {
            System.err.println("Error starting the server" + e.getMessage());
        }
    }
}
