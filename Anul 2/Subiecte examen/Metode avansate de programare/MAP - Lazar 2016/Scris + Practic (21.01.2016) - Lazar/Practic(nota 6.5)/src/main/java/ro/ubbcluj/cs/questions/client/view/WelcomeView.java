package ro.ubbcluj.cs.questions.client.view;

import javafx.collections.ObservableList;
import javafx.concurrent.Service;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Node;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import ro.ubbcluj.cs.questions.client.ClientApp;
import ro.ubbcluj.cs.questions.client.controller.LoginController;
import ro.ubbcluj.cs.questions.common.model.User;


public class WelcomeView extends VBox
{
    private ClientApp clientApp;
    private TextField username;
    private PasswordField password;
    private Button authButton;
    private ProgressIndicator progressIndicator;
    private LoginController loginController;



    public WelcomeView(ClientApp clientApp, LoginController loginController) {
        this.loginController = loginController;
        this.clientApp = clientApp;
        ObservableList<Node> children = getChildren();
        children.add(new Text("Welcome"));
        // username (label + textfield)
        children.add(new Label("Username:"));
        username = new TextField();
        children.add(username);
        // password (label + textfield)
        children.add(new Label("Password:"));
        password = new PasswordField();
        children.add(password);
        // auth button (login or cancel)
        authButton = new Button("Login");
        authButton.setOnAction(authHandler);
        children.add(authButton);
        // progress indicator
        progressIndicator = new ProgressIndicator();
        progressIndicator.setVisible(false);
        children.add(progressIndicator);
    }

    private final EventHandler<ActionEvent> authHandler = event -> {
        progressIndicator.setVisible(true);
        Service<User> authService = loginController.authService(username.getText(), password.getText());
        authService.setOnSucceeded(e -> {
            progressIndicator.setVisible(false);
            clientApp.userAuthenticated(authService.getValue());
        });
        authService.setOnFailed(e -> {
            progressIndicator.setVisible(false);
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error");
            alert.setHeaderText("An error occurred");
            alert.setContentText(authService.getException().getMessage());
            alert.showAndWait();
        });
        authService.start();
    };

}