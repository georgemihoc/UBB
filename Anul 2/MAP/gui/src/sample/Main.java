package sample;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
//        AnchorPane root = new AnchorPane();
//
//        HBox hBox = new HBox();
//
//
//        Button buttonOk = new Button("Ok");
//        Button buttonCancel = new Button("Cancel");
//
//        hBox.getChildren().add(buttonOk);
//        hBox.getChildren().add(buttonCancel);
//
//        root.getChildren().add(hBox);
//
//        TextField textField = new TextField();
//        root.getChildren().add(textField);
//
//        AnchorPane.setTopAnchor(hBox,50d);
//        AnchorPane.setLeftAnchor(hBox,50d);
//        AnchorPane.setBottomAnchor(textField,100d);
//
//
//        buttonOk.setOnAction(new EventHandler<ActionEvent>() {
//            @Override
//            public void handle(ActionEvent actionEvent) {
//                textField.setText("boss");
//            }
//        });


/////////////Incarcare din ExViewController
////        ExController ctrl = new ExController();
////        ExView view = new ExView(ctrl);
////
////        ctrl.setView(view);
//
//        AnchorPane root = view.getRoot();

        //Incarcare din fisier fxml
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("exView.fxml"));
        AnchorPane root = loader.load();


        Scene scene = new Scene(root,400,400);
        primaryStage.setScene(scene);
        primaryStage.show();


    }


    public static void main(String[] args) {
        launch(args);
    }
}
