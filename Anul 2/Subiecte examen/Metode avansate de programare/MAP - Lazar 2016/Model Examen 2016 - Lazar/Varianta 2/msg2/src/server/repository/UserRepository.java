package server.repository;

import model.User;

import java.util.Collection;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;

public class UserRepository {
    private ConcurrentMap<String, User> users = new ConcurrentHashMap<>();
    public UserRepository() {
        users.put("alex", new User("alex", false));
        users.put("ana", new User("ana", false));
        users.put("teo", new User("teo", false));
        users.put("iulian", new User("iulian", false));
    }

    public Collection<User> findAll() {
        return users.values();
    }

    public User findByUsername(String username) {
        return users.get(username);
    }
}
