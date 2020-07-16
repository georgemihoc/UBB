package chat.server;

import chat.model.Message;
import chat.model.User;
import chat.persistence.MessageRepository;
import chat.persistence.UserRepository;
import chat.services.*;

import java.util.Map;
import java.util.Set;
import java.util.TreeSet;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * Created by grigo on 5/2/17.
 */
public class ChatServerAMSImpl implements IChatServicesAMS {
    private UserRepository userRepository;
    private MessageRepository messageRepository;
    private Map<String, User> loggedClients;
    private IChatNotificationService notificationService;

    public ChatServerAMSImpl(UserRepository uRepo, MessageRepository mRepo, IChatNotificationService service) {

        userRepository= uRepo;
        messageRepository=mRepo;
        loggedClients=new ConcurrentHashMap<>();
        notificationService=service;
    }


    public synchronized void login(User user) throws ChatException {
        User userR=userRepository.findBy(user.getId(),user.getPasswd());
        if (userR!=null){
            if(loggedClients.get(user.getId())!=null)
                throw new ChatException("User already logged in.");
            loggedClients.put(user.getId(), user);
            notificationService.userLoggedIn(new User(user.getId()));
        }else
            throw new ChatException("Authentication failed.");
    }

    @Override
    public void sendMessageToAll(Message message) throws ChatException {

        messageRepository.save(message);
        notificationService.newMessage(message);
    }

    public synchronized void logout(User user) throws ChatException {
        User localClient=loggedClients.remove(user.getId());
        if (localClient==null)
            throw new ChatException("User "+user.getId()+" is not logged in.");
        else
            notificationService.userLoggedOut(user);
    }

    public synchronized User[] getLoggedUsers() throws ChatException {
        Set<User> result=new TreeSet<User>();
        System.out.println("Logged users: ");
        for (String user : loggedClients.keySet()){
            result.add(new User(user));
            System.out.print("+"+user);
        }
        return result.toArray(new User[result.size()]);
    }
}
