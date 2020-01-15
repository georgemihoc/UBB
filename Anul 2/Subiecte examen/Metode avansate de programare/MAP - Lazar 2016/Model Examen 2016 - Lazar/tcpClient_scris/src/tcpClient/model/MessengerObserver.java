package tcpClient.model;

/**
 * Created by Narcis2007 on 15.01.2016.
 */
public interface MessengerObserver {
    void update(User user);
    void update(MyMessage message);
}
