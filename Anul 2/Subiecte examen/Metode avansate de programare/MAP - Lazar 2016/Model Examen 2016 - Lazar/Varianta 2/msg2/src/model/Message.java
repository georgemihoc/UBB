package model;

public class Message {
    private String sender;
    private String text;

    public Message(String senderAndText) { //sender::text
        int pos = senderAndText.indexOf("::");
        if (pos == -1) {
            throw new IllegalArgumentException("Use sender::text format");
        }
        sender = senderAndText.substring(0, pos);
        text = senderAndText.substring(pos+2);
    }

    @Override
    public String toString() {
        return sender + "::" + text;
    }
}
