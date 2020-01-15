package model;

import java.util.ArrayList;
import java.util.List;

public class User {
    private String username;
    private boolean online;

    public User(String usernameAndStatus) {//alex::true
        int pos = usernameAndStatus.indexOf("::");
        if (pos == -1) {
            throw new IllegalArgumentException("Use username::online format");
        }
        username = usernameAndStatus.substring(0, pos);
        online = Boolean.valueOf(usernameAndStatus.substring(pos+2));
    }

    public User(String username, boolean isOnline) {
        this.username = username;
        this.online = isOnline;
    }

    @Override
    public String toString() {
        return username + "::" + online;
    }

    public static List<User> asList(String usernameAndStatusArray) {//alex::true;ana::false
        String[] usernameAndStatus = usernameAndStatusArray.split(";");
        List<User> users = new ArrayList<>();
        for (String us : usernameAndStatus) {
            users.add(new User(us));
        }
        return users;
    }

    public void setOnline(boolean online) {
        this.online = online;
    }
}
