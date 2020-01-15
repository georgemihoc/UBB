package tcpClient.model;

/**
 * Created by Narcis2007 on 15.01.2016.
 */
public class User {
    private String username;
    private String status;

    public User(String username, String status) {
        this.username = username;
        this.status = status;
    }

    public User(String userAndStatus) {
        this.username=userAndStatus.split(":")[0];
        this.status=userAndStatus.split(":")[1];
    }

    @Override
    public String toString() {
        return "User{" +
                "username='" + username + '\'' +
                ", status='" + status + '\'' +
                '}';
    }
}
