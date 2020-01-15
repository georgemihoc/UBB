package server.net;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.ExecutorService;

public class NotificationServer {
    private List<NotificationHandler> notificationHandlers = Collections.synchronizedList(new ArrayList<>());

    public NotificationServer(ExecutorService executorService) throws IOException {
        ServerSocket notificationServerSocket = new ServerSocket(1235);
        executorService.submit(() -> {
            while (true) {
                try {
                    notificationHandlers.add(new NotificationHandler(notificationServerSocket.accept()));
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });

    }
    public void notifyClients(String content) {
        System.out.println("Notifying " + content);
        for (int i = notificationHandlers.size() - 1; i >= 0; i--) {
            try {
                notificationHandlers.get(i).write(content);
            } catch (Exception e) {
                notificationHandlers.get(i).close();
                notificationHandlers.remove(i);
            }
        }
    }

    private static class NotificationHandler {
        private final Socket socket;
        private PrintWriter printWriter;

        public NotificationHandler(Socket socket) throws IOException {
            this.socket = socket;
            printWriter = new PrintWriter(socket.getOutputStream());
        }

        public void write(String content) {
            printWriter.println(content);
            printWriter.flush();
        }

        public void close() {
            try {
                printWriter.close();
                socket.close();
            } catch (Exception ignore) {
            }
        }
    }

}
