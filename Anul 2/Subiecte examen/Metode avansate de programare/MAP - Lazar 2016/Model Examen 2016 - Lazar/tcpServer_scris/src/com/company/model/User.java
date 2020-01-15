package com.company.model;

/**
 * Created by Narcis2007 on 15.01.2016.
 */
public class User {
    private String status="offline";

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPass() {
        return pass;
    }

    public void setPass(String pass) {
        this.pass = pass;
    }

    private String username;
    private String pass;

    public User(String admin, String pass) {

        this.username = admin;
        this.pass = pass;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return username+":"+status+"\n";
    }

    public String getStatus() {
        return status;
    }
}
