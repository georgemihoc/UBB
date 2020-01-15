package ro.ubbcluj.cs.questions.client.view;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.concurrent.Service;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Node;
import javafx.scene.control.*;

import javafx.scene.layout.VBox;
import ro.ubbcluj.cs.questions.client.ClientApp;
import ro.ubbcluj.cs.questions.client.controller.QuestionController;
import ro.ubbcluj.cs.questions.common.model.Question;
import ro.ubbcluj.cs.questions.common.model.User;

import java.util.ArrayList;

import ro.ubbcluj.cs.questions.client.controller.Globals;

public class QuestionView extends VBox {

//    private final TextField post;
    private ObservableList<Question> observableList;
    private QuestionController questionController;
    private final ProgressIndicator progressIndicator;

    private TextField post;

    private Button updateButton;
    private Button answerButton;

    public QuestionView(ClientApp clientApp, QuestionController questionController) {
        this.clientApp = clientApp;
        this.questionController = questionController;
        ListView<Question> listView = new ListView<Question>();
        observableList = FXCollections.observableArrayList(new ArrayList<>());
        observableList.parallelStream();
        listView.setItems(observableList);
        getChildren().add(listView);
        progressIndicator = new ProgressIndicator();
        progressIndicator.setVisible(false);
        getChildren().add(progressIndicator);
        fetchPosts(Globals.id);
        Globals.id++;
        ObservableList<Node> children = getChildren();
        post = new TextField();
        children.add(post);
        updateButton = new Button("Next");
        updateButton.setOnAction(updateHandler);
        children.add(updateButton);

    }

    private final EventHandler<ActionEvent> updateHandler = event -> {
        if (Globals.id<=this.questionController.getQuestionClient().getNumber())
        {
            observableList.clear();
            fetchPosts(Globals.id);
            Globals.id++;
        }
        observableList.clear();
        Question question1 = this.questionController.getQuestionClient().getOne(Globals.id-2);
        if (post.getText().equals(question1.getCorrectAnswer()))
        {
            answerButton = new Button("Correct Answer");
        }
        else {
            answerButton = new Button("Wrong Answer");
        }
        ListView<Question> listView = new ListView<Question>();
        getChildren().add(listView);
        ObservableList<Node> children = getChildren();
        children.add(answerButton);

    };
    private ClientApp clientApp;
    private final EventHandler<ActionEvent> addHandler = event -> {
        progressIndicator = new ProgressIndicator();
        progressIndicator.setVisible(true);
        User user = this.questionController.getQuestionClient().getUser();
        Question question1 = new Question(post.getText(),user.getUsername());
        Service<Question> addService = questionController.addService(question1);
        addService.setOnSucceeded(e -> {
            progressIndicator.setVisible(false);
            clientApp.postAdded(addService.getValue());
        });
        addService.setOnFailed(e -> {
            progressIndicator.setVisible(false);
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error");
            alert.setHeaderText("An error occurred");
            alert.setContentText(addService.getException().getMessage());
            alert.showAndWait();
        });
        addService.start();
    };


    private void fetchPosts(int id) {
        progressIndicator.setVisible(true);
        Service<Question[]> getPostsService = questionController.getPostsService();
        getPostsService.setOnSucceeded(e -> {
            progressIndicator.setVisible(false);
            observableList.addAll(questionController.getQuestionClient().getOne(id));
        });
        getPostsService.setOnFailed(e -> {
            progressIndicator.setVisible(false);
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error");
            alert.setHeaderText("An error occurred");
            alert.setContentText(getPostsService.getException().getMessage());
            alert.showAndWait();
        });
        getPostsService.start();
    }

}
