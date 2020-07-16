package com.company.sem1.model;

import com.company.sem1.Constants;

import java.time.LocalDateTime;

public class MessageTask extends Task {
    private String message;
    private String from;
    private String to;
    private LocalDateTime date;

    public MessageTask(String taskId, String desc, String message, String from, String to, LocalDateTime date) {
        super(taskId, desc);
        this.message = message;
        this.from = from;
        this.to = to;
        this.date = date;
    }

    public void execute() {
        System.out.println(toString());

    }

    @Override
    public String toString() {
        return super.toString()+ " " + message + " " + from + "  " + to + " " + " " + date.format(Constants.DATE_TIME_FORMATTER);

    }
}
