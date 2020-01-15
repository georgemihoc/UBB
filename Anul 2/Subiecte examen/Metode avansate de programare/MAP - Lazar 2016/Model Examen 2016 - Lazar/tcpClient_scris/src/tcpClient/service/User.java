package tcpClient.service;

/**
 * Created by Narcis2007 on 15.01.2016.
 */
public class User {
    private final String username;
    private final String status;

    public User(String usernameAndStatus) {
        this.username=usernameAndStatus.split(":")[0];
        this.status=usernameAndStatus.split(":")[1];
    }

    @Override
    public String toString() {
        return  username + ':' + status +"\n";
    }
}
