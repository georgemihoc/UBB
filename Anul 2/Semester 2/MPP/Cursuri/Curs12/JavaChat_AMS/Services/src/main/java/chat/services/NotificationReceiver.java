package chat.services;

import chat.notification.Notification;

/**
 * Created by grigo on 5/2/17.
 */
public interface NotificationReceiver {
    void start(NotificationSubscriber subscriber);
    void stop();
}
