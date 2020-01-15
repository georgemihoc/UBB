package client.service;

import model.MessengerObserver;
import model.User;
import client.net.TcpClient;

import java.io.IOException;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class MessengerClient {
    private final TcpClient tcpClient;
    private ExecutorService executorService = Executors.newFixedThreadPool(4);

    public MessengerClient(TcpClient tcpClient) {
        this.tcpClient = tcpClient;
    }

    public void setMessengerObserver(MessengerObserver messengerObserver) {
        tcpClient.setMessengerObserver(messengerObserver);
    }

    public User login(String username) throws Exception {
        String usernameAndStatus = tcpClient.sendAndReceive("login", username);
        executorService.submit(() -> {
            tcpClient.startListening();
        });
        return new User(usernameAndStatus);
    }

    public void getUsersAsync(AsyncCallback<List<User>> asyncCallback) {
        executorService.submit(() -> { //runnable
            try {
                String usernameAndStatusArray = tcpClient.sendAndReceive("getUsers", null);
                asyncCallback.onSuccess(User.asList(usernameAndStatusArray));
            } catch (Exception e) {
                asyncCallback.onFailure(e);
            }
        });
    }

    public void logoutAsync(String username, AsyncCallback<User> asyncCallback) {
        executorService.submit(() -> { //runnable
            try {
                String usernameAndStatus = tcpClient.sendAndReceive("logout", username);
                tcpClient.stopListening();
                asyncCallback.onSuccess(new User(usernameAndStatus));
            } catch (Exception e) {
                asyncCallback.onFailure(e);
            }
        });
    }

    public Future<Boolean> send(String userAndText) {
        return executorService.submit(new Callable<Boolean>() {
            @Override
            public Boolean call() throws Exception {
                String res = tcpClient.sendAndReceive("send", userAndText); // returns "true" or "false"
                return Boolean.valueOf(res);
            }
        });
    }
}
