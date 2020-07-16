package chat.services;

import chat.model.Message;
import chat.model.User;

/**
 * Created by grigo on 5/2/17.
 */
public interface IChatNotificationService {
    void userLoggedIn(User user);
    void userLoggedOut(User user);
    void newMessage(Message message);
}
