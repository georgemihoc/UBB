package tcpClient.service;

/**
 * Created by Narcis2007 on 16.01.2016.
 */
public interface AsyncCallback<T> {
    public void onSuccess(T t);
    public void onException(Exception e);
}
