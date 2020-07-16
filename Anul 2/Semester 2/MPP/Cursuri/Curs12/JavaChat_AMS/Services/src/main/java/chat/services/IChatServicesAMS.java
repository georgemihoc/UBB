package chat.services;

import chat.model.Message;
import chat.model.User;

/**
 * Created by grigo on 5/2/17.
 */
public interface IChatServicesAMS {
    void login(User user) throws ChatException;
    void sendMessageToAll(Message message) throws ChatException;
    void logout(User user) throws ChatException;
    User[] getLoggedUsers() throws ChatException;
}
