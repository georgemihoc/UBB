package sample;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.HBox;

public class ExView {
    private ExController ctrl;
    private AnchorPane root;
    TextField textField = new TextField();

    public ExView(ExController ctrl) {
        this.ctrl = ctrl;
        initView();
    }

    private void initView() {
        root = new AnchorPane();

        HBox hBox = new HBox();


        Button buttonOk = new Button("Ok");
        buttonOk.setOnAction(ctrl::handleOk);
        Button buttonCancel = new Button("Cancel");

        hBox.getChildren().add(buttonOk);
        hBox.getChildren().add(buttonCancel);

        root.getChildren().add(hBox);

        root.getChildren().add(textField);

        AnchorPane.setTopAnchor(hBox,50d);
        AnchorPane.setLeftAnchor(hBox,50d);
        AnchorPane.setBottomAnchor(textField,100d);

    }

    public AnchorPane getRoot() {
        return root;
    }
}