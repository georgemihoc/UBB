package chat.client.ams;

import chat.client.gui.FriendsListModel;
import chat.client.gui.MessagesListModel;
import chat.model.Message;
import chat.model.User;
import chat.notification.Notification;
import chat.notification.NotificationType;
import chat.services.*;

import javax.swing.*;

/**
 * Created by IntelliJ IDEA.
 * User: grigo
 * Date: Mar 18, 2009
 * Time: 2:54:28 PM
 */
public class ChatClientCtrlAMS implements NotificationSubscriber {

    private FriendsListModel friendsModel;
    private MessagesListModel messagesModel;
    private IChatServicesAMS server;
    private User user;
    private NotificationReceiver receiver;

    public ChatClientCtrlAMS(IChatServicesAMS server) {
        this.server = server;
        friendsModel=new FriendsListModel();
        messagesModel=new MessagesListModel();
    }

    public void setReceiver(NotificationReceiver receiver) {
        this.receiver = receiver;
    }

    public ListModel getFriendsModel(){
        return friendsModel;
    }

    public ListModel getMessagesModel(){
        return messagesModel;
    }



    public void logout() {
        try {
            server.logout(user);
        } catch (ChatException e) {
            System.out.println("Logout error "+e);
        }finally {
            receiver.stop();
        }
    }

    public void login(String id, String pass) throws ChatException {
        User userL= new User(id,pass,"");
        server.login(userL);
        user=userL;
        User[] loggedInFriends=server.getLoggedUsers();
        System.out.println("Logged friends "+loggedInFriends.length);
        for(User us : loggedInFriends){
            if (!us.getId().equals(id))
            friendsModel.friendLoggedIn(us.getId());
        }
        receiver.start(this);

    }


    public void sendMessageToAll(String txtMsg) throws ChatException{
        server.sendMessageToAll(new Message(new User(user.getId()),txtMsg, new User("")));
    }


    @Override
    public void notificationReceived(Notification notif) {
        try {
            System.out.println("Ctrl notificationReceived ... " + notif.getType());
            SwingUtilities.invokeLater(()->{
                switch (notif.getType()) {
                    case NEW_MESSAGE: {
                        messagesModel.newMessage(notif.getSender(), notif.getTextMessage());
                        break;
                    }
                    case USER_LOGGED_IN: {
                        friendsModel.friendLoggedIn(notif.getUser());
                        break;
                    }
                    case USER_LOGGED_OUT: {
                        friendsModel.friendLoggedOut(notif.getUser());
                        break;
                    }
                }});
        }catch(Exception ex){
            ex.printStackTrace();
        }
    }
}
