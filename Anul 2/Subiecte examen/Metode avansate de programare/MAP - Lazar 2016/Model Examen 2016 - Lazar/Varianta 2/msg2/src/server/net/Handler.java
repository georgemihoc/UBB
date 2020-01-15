package server.net;

@FunctionalInterface
public interface Handler {
    String handle(String args) throws Exception;
}

