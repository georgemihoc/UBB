package sample;
import javafx.event.ActionEvent;

public class ExController {
    private ExView view;

    public void setView(ExView view) {
        this.view = view;
    }

    public void handleOk(ActionEvent actionEvent) {
        this.view.textField.setText("boss");

    }
}
