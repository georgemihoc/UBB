package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

public class ExController2 {
    private ExView view;
    @FXML
    public TextField textFieldOk;
    public void handleOk(ActionEvent actionEvent) {
        textFieldOk.setText("OK");
    }

    public void handleCancel(ActionEvent actionEvent) {
        // do what you have to do

    }
}
