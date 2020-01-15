package com.company.repository;

import com.company.model.User;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Narcis2007 on 15.01.2016.
 */
public class Repository {
    public List<User> getUsers() {
        return users;
    }

    public void setUsers(List<User> users) {
        this.users = users;
    }

    private List<User> users;

    public Repository() {
        this.users=new ArrayList<User>();
        users.add(new User("narcis","pass"));
        users.add(new User("admin","pass"));
    }


    public User findByUsername(String data) {
        for(User u:users)
            if(u.getUsername().equals(data))
                return u;
        return null;
    }
}
