package ro.ubbcluj.cs.questions.client.controller;

import javafx.concurrent.Service;
import javafx.concurrent.Task;

import ro.ubbcluj.cs.questions.client.service.QuestionClient;
import ro.ubbcluj.cs.questions.common.model.Question;

public class QuestionController {
    private final QuestionClient questionClient;

    public QuestionController(QuestionClient questionClient) {
        this.questionClient = questionClient;
    }

    public Service<Question[]> getPostsService() {
        return new Service<Question[]>() {
            @Override
            protected Task<Question[]> createTask() {
                return new Task<Question[]>() {
                    @Override
                    protected Question[] call() throws Exception {
                        return questionClient.getAll();
                    }
                };
            }
        };
    }


    public Service<Question> addService(Question question1) {
        return new Service<Question>() {
            @Override
            protected Task<Question> createTask() {
                return new Task<Question>() {
                    @Override
                    protected Question call() throws Exception {
                        return questionClient.add(question1);
                    }
                };
            }
        };
    }

    public QuestionClient getQuestionClient() {
        return questionClient;
    }

}
