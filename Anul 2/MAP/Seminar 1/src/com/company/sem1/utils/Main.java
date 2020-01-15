package com.company.sem1.utils;

import com.company.sem1.container.Strategy;
import com.company.sem1.model.MessageTask;

import java.time.LocalDateTime;

public class Main {

    public static void main(String[] args) {
        System.out.println("tun");
        MessageTask t = new MessageTask( "123", "descriere", "mesaj", "de la", "pentru", LocalDateTime.now());
        MessageTask[] l = createMessageTaskArray();

        t.execute();
    }

    private static MessageTask[] createMessageTaskArray() {
    }
}
