package chat.client;

import chat.client.ams.ChatClientCtrlAMS;
import chat.client.ams.LoginWindowAMS;

import org.springframework.context.support.ClassPathXmlApplicationContext;


/**
 * Created by grigo on 5/2/17.
 */
public class StartAMSRpcClient {

    public static void main(String[] args) {
        ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("spring-client.xml");
        ChatClientCtrlAMS ctrl=context.getBean("chatCtrl",ChatClientCtrlAMS.class);
        LoginWindowAMS logWin=new LoginWindowAMS("Chat XYZ", ctrl);
        logWin.setSize(200,200);
        logWin.setLocation(150,150);
        logWin.setVisible(true);

    }
}
