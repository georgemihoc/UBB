package model;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class MessageTask extends Task {
    private String mesaj;
    private String from;
    private String to;
    private LocalDateTime date;

    private static final DateTimeFormatter DATE_TIME_FORMATTER = DateTimeFormatter.ofPattern("yyyy-MM-dd hh:mm");

    public MessageTask(String taskId, String descriere, String mesaj, String from, String to, LocalDateTime date) {
        super(taskId,descriere);
        this.mesaj = mesaj;
        this.from = from;
        this.to = to;
        this.date = date;
    }

    @Override
    public void execute() {
        super.execute();
        String taskMessage = "message=" + mesaj + "|from="+from + "|to="+to + "|date=" + date.format(DATE_TIME_FORMATTER);
        System.out.println(taskMessage);
    }
}
