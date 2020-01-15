package server.service;

import model.Message;
import model.User;
import server.net.NotificationServer;
import server.net.RpcServer;
import server.repository.UserRepository;

public class MessengerService {
    private final UserRepository userRepository;
    private final NotificationServer notificationServer;

    public MessengerService(UserRepository userRepository, RpcServer rpcServer, NotificationServer notificationServer) {
        this.notificationServer = notificationServer;
        this.userRepository = userRepository;
        rpcServer.handle("login", (username) -> {
            return changeUserStatus(username, true);
        });
        rpcServer.handle("logout", (username) -> {
            return changeUserStatus(username, false);
        });
        rpcServer.handle("send", (usernameAndText) -> {//ana::pauza?
            notificationServer.notifyClients("message::" + new Message(usernameAndText).toString());
            return "true";
        });
        rpcServer.handle("getUsers", (args) -> {
            StringBuilder sb = new StringBuilder();
            userRepository.findAll().forEach(user -> sb.append(user.toString()).append(";"));
            sb.setLength(sb.length() - 1);
            return sb.toString();
        });
    }
    private String changeUserStatus(String username, boolean online) {
        User user = userRepository.findByUsername(username);
        if (user == null) {
            throw new IllegalArgumentException("Unknown user");
        }
        user.setOnline(online);
        notificationServer.notifyClients("user::" + user.toString());
        return user.toString();
    }

}
