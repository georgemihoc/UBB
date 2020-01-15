package client.service;

public interface AsyncCallback<T> {
    void onSuccess(T result);
    void onFailure(Exception e);

}
