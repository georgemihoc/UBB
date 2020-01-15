package ro.ubbcluj.cs.questions.client;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import ro.ubbcluj.cs.questions.client.controller.LoginController;
import ro.ubbcluj.cs.questions.client.controller.QuestionController;
import ro.ubbcluj.cs.questions.client.service.QuestionClient;
import ro.ubbcluj.cs.questions.client.view.QuestionView;
import ro.ubbcluj.cs.questions.client.view.WelcomeView;
import ro.ubbcluj.cs.questions.common.model.Question;
import ro.ubbcluj.cs.questions.common.model.User;

public class ClientApp extends Application {
    private static final Log LOG = LogFactory.getLog(ClientApp.class);
    private Stage stage;
    private QuestionClient questionClient;

    @Override
    public void start(Stage primaryStage) throws Exception {
        stage = primaryStage;
        questionClient = new QuestionClient();
        LoginController loginController = new LoginController(questionClient);
        WelcomeView view = new WelcomeView(this, loginController);
        Scene scene = new Scene(view);
        stage.setScene(scene);
        stage.setTitle("Posts");
        stage.show();
    }

    public void userAuthenticated(User value) {
        QuestionView view = new QuestionView(this, new QuestionController(questionClient));
        Scene scene = new Scene(view);
        stage.setScene(scene);
    }

    public void postAdded(Question value) {
        QuestionView view = new QuestionView(this, new QuestionController(questionClient));
        Scene scene = new Scene(view);
        stage.setScene(scene);
    }
}