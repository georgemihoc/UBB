import controllers.MainViewFXML;
import controllers.ViewController;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;
import repository.*;
import service.Service;

public class Main extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("Urmarire Bug-uri");
        FXMLLoader loader=new FXMLLoader(getClass().getResource("mainView.fxml"));
        Pane myPane = (AnchorPane) loader.load();
        MainViewFXML ctrl=loader.getController();

        BugDbRepository repoBug = new BugDbRepository();
        AngajatDbRepository repoAngajat = new AngajatDbRepository();

        Service service = new Service(repoAngajat,repoBug);

        ViewController clientController = new ViewController(ctrl,service);
        System.out.println("BOss");

        ctrl.setTasksService(clientController);
        Scene myScene = new Scene(myPane);
        primaryStage.setScene(myScene);


        primaryStage.setOnCloseRequest(new EventHandler<WindowEvent>() {
            public void handle(WindowEvent we) {
            }
        });
        primaryStage.show();
    }
    public static void main(String[] args) throws Exception {
        System.out.println("boss");
        launch(args);
    }
}
