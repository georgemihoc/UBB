package chat.server;

import chat.model.Message;
import chat.model.User;
import chat.notification.Notification;
import chat.notification.NotificationType;
import chat.services.IChatNotificationService;
import org.springframework.jms.core.JmsOperations;

/**
 * Created by grigo on 5/2/17.
 */
public class NotificationServiceImpl implements IChatNotificationService {
    private JmsOperations jmsOperations;

    public NotificationServiceImpl(JmsOperations operations) {
        jmsOperations=operations;
    }

    @Override
    public void userLoggedIn(User user) {
        System.out.println("user logged in notification");
        Notification notif=new Notification(NotificationType.USER_LOGGED_IN,user.getId());
        jmsOperations.convertAndSend(notif);
        System.out.println("Sent message to ActiveMQ... " +notif);
    }

    @Override
    public void userLoggedOut(User user) {
        System.out.println("user logged out notification");
        Notification notif=new Notification(NotificationType.USER_LOGGED_OUT,user.getId());
        jmsOperations.convertAndSend(notif);
        System.out.println("Sent message to ActiveMQ... " +notif);
    }

    @Override
    public void newMessage(Message message) {
        System.out.println("New message notification");
        Notification notif=new Notification(NotificationType.NEW_MESSAGE,message.getSender().getId(),message.getText());
        jmsOperations.convertAndSend(notif);
        System.out.println("Sent message to ActiveMQ... " +notif);
    }
}
