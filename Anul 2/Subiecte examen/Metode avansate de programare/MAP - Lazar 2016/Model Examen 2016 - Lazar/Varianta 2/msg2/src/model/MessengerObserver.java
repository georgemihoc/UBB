package model;

public interface MessengerObserver {
    void update(User user);
    void update(Message message);
}
