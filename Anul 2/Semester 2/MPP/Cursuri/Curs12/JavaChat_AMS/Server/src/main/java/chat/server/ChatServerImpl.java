package chat.server;

import chat.model.Message;
import chat.model.User;
import chat.persistence.MessageRepository;
import chat.persistence.UserRepository;
import chat.services.ChatException;
import chat.services.IChatClient;
import chat.services.IChatServer;

import java.util.Map;
import java.util.Set;
import java.util.TreeSet;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * Created by IntelliJ IDEA.
 * User: grigo
 * Date: Mar 18, 2009
 * Time: 1:39:47 PM
 */
public class ChatServerImpl implements IChatServer {

    private UserRepository userRepository;
    private MessageRepository messageRepository;
    private Map<String, IChatClient> loggedClients;

    public ChatServerImpl(UserRepository uRepo, MessageRepository mRepo) {

        userRepository= uRepo;
        messageRepository=mRepo;
        loggedClients=new ConcurrentHashMap<>();;
    }


    public synchronized void login(User user, IChatClient client) throws ChatException {
        User userR=userRepository.findBy(user.getId(),user.getPasswd());
        if (userR!=null){
            if(loggedClients.get(user.getId())!=null)
                throw new ChatException("User already logged in.");
            loggedClients.put(user.getId(), client);
            notifyFriendsLoggedIn(user);
        }else
            throw new ChatException("Authentication failed.");
    }

    private final int defaultThreadsNo=5;

    private void notifyFriendsLoggedIn(User user) throws ChatException {
        ExecutorService executor= Executors.newFixedThreadPool(defaultThreadsNo);
          for(String  userID:loggedClients.keySet()) {
              if (!userID.equals(user.getId())) {
                  IChatClient chatClient = loggedClients.get(userID);
                  if (chatClient != null)
                      executor.execute(() -> {
                          try {
                              System.out.println("Notifying users [" + user.getId() + "] logged in.");
                              chatClient.userLoggedIn(user);
                          } catch (ChatException e) {
                              System.err.println("Error notifying friend " + e);
                          }
                      });
              }
          }

        executor.shutdown();
    }

    private void notifyUserLoggedOut(User user) throws ChatException {
        ExecutorService executor= Executors.newFixedThreadPool(defaultThreadsNo);
        for(String  userID:loggedClients.keySet()) {
            IChatClient chatClient = loggedClients.get(userID);
            if (chatClient!=null)
                executor.execute(() -> {
                    try {
                        //    System.out.println("Notifying ["+us.getId()+"] friend ["+user.getId()+"] logged out.");
                        System.out.println("Notifying users  ["+user.getId()+"] logged out.");

                        chatClient.userLoggedOut(user);
                    } catch (ChatException e) {
                        System.out.println("Error notifying friend " + e);
                    }
                });

        }
        executor.shutdown();

    }


    public synchronized void sendMessage(Message message) throws ChatException {
        String id_receiver=message.getReceiver().getId();
        IChatClient receiverClient=loggedClients.get(id_receiver);
        if (receiverClient!=null) {      //the receiver is logged in
            messageRepository.save(message);
            receiverClient.messageReceived(message);
        }
        else
            throw new ChatException("User "+id_receiver+" not logged in.");
    }

    @Override
    public void sendMessageToAll(Message message) throws ChatException {
        ExecutorService executor= Executors.newFixedThreadPool(defaultThreadsNo);

        messageRepository.save(message);
        for(String  userID:loggedClients.keySet()) {
            if (!userID.equals(message.getSender().getId())) {
                IChatClient chatClient = loggedClients.get(userID);
                if (chatClient != null)
                    executor.execute(() -> {
                        try {
                            //    System.out.println("Notifying ["+us.getId()+"] friend ["+user.getId()+"] logged out.");
                            System.out.println("Notifying users  new  message.");

                            chatClient.messageReceived(message);
                        } catch (ChatException e) {
                            System.out.println("Error notifying friend " + e);
                        }
                    });

            }
        }
        executor.shutdown();
    }

    public synchronized void logout(User user, IChatClient client) throws ChatException {
        IChatClient localClient=loggedClients.remove(user.getId());
        if (localClient==null)
            throw new ChatException("User "+user.getId()+" is not logged in.");
        notifyUserLoggedOut(user);
    }

    public synchronized User[] getLoggedUsers() throws ChatException {
       //Iterable<User> friends=userRepository.getFriendsOf(user);
        Set<User> result=new TreeSet<User>();
        System.out.println("Logged users: ");
        for (String user : loggedClients.keySet()){
               result.add(new User(user));
                System.out.print("+"+user);
            }

        System.out.println("Size "+result.size());
        return result.toArray(new User[result.size()]);
    }
}
