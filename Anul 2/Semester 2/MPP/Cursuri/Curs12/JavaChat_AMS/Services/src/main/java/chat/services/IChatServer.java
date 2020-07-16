package chat.services;

import chat.model.Message;
import chat.model.User;

/**
 * Created by IntelliJ IDEA.
 * User: grigo
 * Date: Mar 18, 2009
 * Time: 1:32:07 PM
 */
public interface IChatServer {
    void login(User user, IChatClient client) throws ChatException;
    void sendMessage(Message message) throws ChatException;
    void sendMessageToAll(Message message) throws ChatException;
    void logout(User user, IChatClient client) throws ChatException;
    User[] getLoggedUsers() throws ChatException;
}
