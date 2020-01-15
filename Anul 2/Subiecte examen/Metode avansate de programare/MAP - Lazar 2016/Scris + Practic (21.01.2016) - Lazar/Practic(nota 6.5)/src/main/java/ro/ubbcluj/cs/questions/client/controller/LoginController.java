package ro.ubbcluj.cs.questions.client.controller;

import javafx.concurrent.Service;
import javafx.concurrent.Task;
import ro.ubbcluj.cs.questions.client.service.QuestionClient;
import ro.ubbcluj.cs.questions.common.model.User;

public class LoginController {
    private final QuestionClient questionClient;

    public LoginController(QuestionClient questionClient) {
        this.questionClient = questionClient;
    }

    public Service<User> authService(String username, String password) {
        return new Service<User>() {
            @Override
            protected Task<User> createTask() {
                return new Task<User>() {
                    @Override
                    protected User call() throws Exception {
                        User user = new User(username, password);
                        questionClient.setUser(user);
                        questionClient.getAll();
                        return user;
                    }
                };
            }
        };
    }
}
