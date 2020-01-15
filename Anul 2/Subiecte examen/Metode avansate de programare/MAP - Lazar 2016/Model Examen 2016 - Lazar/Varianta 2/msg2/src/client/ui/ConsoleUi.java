package client.ui;

import model.Message;
import model.MessengerObserver;
import model.User;
import client.service.AsyncCallback;
import client.service.MessengerClient;

import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Future;

public class ConsoleUi implements MessengerObserver {
    private final String username;
    private final MessengerClient messengerClient;
    private boolean online;

    public ConsoleUi(String username, MessengerClient messengerClient) {
        this.username = username;
        this.messengerClient = messengerClient;
        this.messengerClient.setMessengerObserver(this);
    }

    public void run() {
        try {
            User user = messengerClient.login(username);
            if (user == null) {
                System.out.println("Invalid user");
                return;
            }
            messengerClient.getUsersAsync(new AsyncCallback<List<User>>() {
                @Override
                public void onSuccess(List<User> users) {
                    users.forEach(u -> System.out.println(u));
                }

                @Override
                public void onFailure(Exception e) {
                    System.out.println("Get users failed " + e.getMessage());
                }
            });
            online = true;
            while (online) {
                Scanner scanner = new Scanner(System.in);
                String cmd = scanner.nextLine();
                if ("quit".equals(cmd)) {
                    messengerClient.logoutAsync(username, new AsyncCallback<User>() {
                        @Override
                        public void onSuccess(User user) {
                            online = false;
                            System.out.println(user);
                        }

                        @Override
                        public void onFailure(Exception e) {
                            System.out.println("Logout failed " + e.getMessage());
                        }
                    });

                } else { //username text
                    try {
                        Future<Boolean> res = messengerClient.send(cmd);
                        System.out.println("Message sent " + res.get());
                    } catch (Exception e) {
                        System.out.println("Send failed " + e.getMessage());
                    }
                }
            }
        } catch (Exception e) {
            System.out.println("Unexpected exception " + e.getMessage());
            e.printStackTrace();
        }
    }

    @Override
    public void update(User user) {
        System.out.println(user);
    }

    @Override
    public void update(Message message) {
        System.out.println(message);
    }
}
