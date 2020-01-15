package server.net;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ExecutorService;

public class RpcServer {
    private final ExecutorService executorService;
    private final Map<String, Handler> handlers = new HashMap<>();

    public RpcServer(ExecutorService executorService) {
        this.executorService = executorService;
    }

    public void start() throws IOException {
        ServerSocket rpcServerSocket = new ServerSocket(1234);
        while (true) {
            executorService.submit(new RpcHandler(rpcServerSocket.accept()));
        }
    }

    public void handle() {

    }

    public void handle(String what, Handler handler) {
        handlers.put(what, handler);
    }

    private class RpcHandler implements Runnable {
        private final Socket socket;

        public RpcHandler(Socket socket) {
            this.socket = socket;
        }

        @Override
        public void run() {
            try {
                BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                String what = bufferedReader.readLine();
                String args = bufferedReader.readLine();
                Handler handler = handlers.get(what);
                String resultCode = "ok";
                String resultBody = null;
                if (handler == null) {
                    resultCode = "nok";
                    resultBody = "Unknown method";
                } else {
                    try {
                        resultBody = handler.handle(args);
                    } catch (Exception e) {
                        resultCode = "nok";
                        resultBody = e.getMessage();
                    }
                }
                PrintWriter printWriter = new PrintWriter(socket.getOutputStream());
                printWriter.println(resultCode);
                printWriter.println(resultBody);
                System.out.println(what + ", " + args + " -> " + resultCode + ", " + resultBody);
                printWriter.flush();
                printWriter.close();
                bufferedReader.close();
                socket.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
