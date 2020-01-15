package tcpClient.ui;

import tcpClient.model.MessengerObserver;
import tcpClient.model.MyMessage;
import tcpClient.model.User;
import tcpClient.service.AsyncCallback;
import tcpClient.service.MessengerService;

import java.util.List;
import java.util.Scanner;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;

/**
 * Created by Narcis2007 on 15.01.2016.
 */
public class ConsoleUI implements MessengerObserver
{
    private String username;
    private MessengerService service;
    private boolean online;

    public ConsoleUI(String username,MessengerService messengerService) {
        this.username = username;

        this.service = messengerService;
        service.setObserver(this);
    }

    public void run() {
        if(service.login(username)){
            System.out.println("user authenticated");
            service.getUsers(new AsyncCallback<List<User>>() {
                @Override
                public void onSuccess(List<User> users) {
                    System.out.println("users: ");
                    users.forEach(u->System.out.println(u));
                }

                @Override
                public void onException(Exception e) {
                    System.out.println(e.getMessage());
                }
            });
            online=true;
            while(online) {
                Scanner scanner = new Scanner(System.in);
                String cmd = scanner.nextLine();
                if (cmd.equals("quit"))
                    service.logout(username,new AsyncCallback<User>() {
                        @Override
                        public void onSuccess(User user) {
                            online = false;
                            System.out.println("user logged out:"+user.toString());
                        }

                        @Override
                        public void onException(Exception e) {

                        }
                    });
                else{
                    Future<MyMessage> message =service.send(cmd.split(":")[0],cmd.split(":")[1]);
                    try {
                        System.out.println("message sent:"+message.get().toString());
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    } catch (ExecutionException e) {
                        e.printStackTrace();
                    }
                }
            }
            System.out.println("exitting app");

        }
        else {
            System.out.println("incorrect username");
        }

    }

    @Override
    public void update(User user) {
        System.out.println(user.toString());
    }

    @Override
    public void update(MyMessage message) {
        System.out.println("new message:"+message.toString());
    }
}
