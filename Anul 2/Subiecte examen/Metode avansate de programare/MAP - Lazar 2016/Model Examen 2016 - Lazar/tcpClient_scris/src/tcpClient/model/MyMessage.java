package tcpClient.model;

/**
 * Created by Narcis2007 on 16.01.2016.
 */
public class MyMessage {
    private final String text;
    private final String username;

    public MyMessage(String usernameAndText) {
        this.username=usernameAndText.split(";")[0];
        this.text=usernameAndText.split(";")[1];
    }

    public MyMessage(String username, String text) {
        this.username=username;
        this.text=text;
    }

    @Override
    public String toString() {
        return username+":"+text;
    }
}
