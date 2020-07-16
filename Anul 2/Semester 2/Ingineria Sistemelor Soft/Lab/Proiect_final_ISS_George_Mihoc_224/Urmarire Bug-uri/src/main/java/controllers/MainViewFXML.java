package controllers;

import javafx.application.Platform;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javafx.scene.layout.AnchorPane;

import javafx.stage.Stage;
import javafx.stage.Window;
import model.Angajat;
import model.Bug;
import model.Pozitie;

import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.ResourceBundle;


public class MainViewFXML extends Window implements Initializable {
    public TitledPane addBugPane;
    public AnchorPane anchorPaneAdmin;
    public Menu menuBar;
    public ListView<Angajat> listAngajati;
    public TextField textFieldNume;
    public TextArea textFieldPozitie;
    public Button buttonAddBug;
    public Button buttonRemoveBug;
    private ViewController ctrl;

    public TextField textFieldDenumire;
    public TextArea textFieldDescriere;
    public AnchorPane loginPane;
    public AnchorPane mainPane;
    public TextField textfieldUsername;
    public PasswordField passwordField;
    @FXML
    private ListView<Bug> list;
    public ListView<Bug> listRezolvate;

    private String currentUsername;
    private String currentPassword;


    public MainViewFXML() {

    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {

        listAngajati.getSelectionModel().selectedItemProperty().addListener(
                (observable,oldvalue,newValue)-> completeFields(newValue));
    }

    private void completeFields(Angajat newValue) {
        textFieldNume.setText(newValue.getUsername());
        textFieldPozitie.setText(newValue.getPozitie());
    }

    public void setTasksService(ViewController ctrl) throws Exception {
        this.ctrl = ctrl;
        menuBar.setVisible(false);
        mainPane.setVisible(false);
        anchorPaneAdmin.setVisible(false);
    }




    public void clearFields(){
        textFieldDenumire.clear();
        textFieldDescriere.clear();
    }

    public void handleRefreshButton(ActionEvent actionEvent) {
        initDataTesterOrProgramator();
    }

    public void handleLoginButton(ActionEvent actionEvent) throws Exception {
        String username = textfieldUsername.getText();
        String password = passwordField.getText();

        try {
            System.out.println(ctrl.login(username, password));

            currentUsername = username;
            currentPassword = password;

            switch (ctrl.login(username, password)){
                case PROGRAMATOR:
                    showProgrammerWindow();
                    break;
                case TESTER:
                    showTesterWindow();
                    break;
                case ADMINISTRATOR:
                    showAdminWindow();
                    break;
                case ERROR:
                    showErrorMessage("Invalid credentials");
                    break;
            }

        }
        catch (Exception exception){
            showErrorMessage("Invalid credentials");
        }
    }

    private void initDataAdmin() {
        listAngajati.getItems().clear();
        for (Angajat angajat:
             ctrl.getListAngajati()) {
            listAngajati.getItems().add(angajat);
        }
    }

    private void showAdminWindow() {
        textfieldUsername.clear();
        passwordField.clear();
        loginPane.setVisible(false);
        mainPane.setVisible(false);

        menuBar.setVisible(true);
        anchorPaneAdmin.setVisible(true);

        initDataAdmin();
    }



    private void showTesterWindow() {
        textfieldUsername.clear();
        passwordField.clear();
        loginPane.setVisible(false);
        mainPane.setVisible(true);

//        menuBar.setVisible(true);
        anchorPaneAdmin.setVisible(false);
        addBugPane.setVisible(true);

        buttonRemoveBug.setVisible(false);


        initDataTesterOrProgramator();
    }

    private void showProgrammerWindow() {
        textfieldUsername.clear();
        passwordField.clear();
        loginPane.setVisible(false);
        mainPane.setVisible(true);

//        menuBar.setVisible(true);
        anchorPaneAdmin.setVisible(false);
        addBugPane.setVisible(false);

        buttonRemoveBug.setVisible(true);

        initDataTesterOrProgramator();
    }

    private void initDataTesterOrProgramator() {
        list.getItems().clear();
        listRezolvate.getItems().clear();
        for (Bug bug :
                ctrl.getAllBug()){
            if(bug.getRezolvat().equals("activ")){
                list.getItems().add(bug);
            }
            else {
                listRezolvate.getItems().add(bug);
            }
        }
    }

    public void enterKey(javafx.scene.input.KeyEvent keyEvent) throws Exception {
        if(keyEvent.getCode().toString().equals("ENTER"))
            handleLoginButton(null);
    }

    public void handleLogout(ActionEvent actionEvent) throws Exception {
        mainPane.setVisible(false);
        anchorPaneAdmin.setVisible(false);
        loginPane.setVisible(true);
    }

    void showErrorMessage(String text){
        Alert message=new Alert(Alert.AlertType.ERROR);
        message.setTitle("Mesaj eroare");
        message.setContentText(text);
        message.showAndWait();
    }





    public void handleAddAngajatButton(ActionEvent actionEvent) {
        String username = textFieldNume.getText();
        String pozitie = textFieldPozitie.getText();
        try {
            ctrl.addAngajat(username, pozitie);

        }catch (Exception exception){
            showErrorMessage(exception.getLocalizedMessage());
        }
    }

    public void handleRefreshAdmin(ActionEvent actionEvent) {
        initDataAdmin();
    }

    public void handleDeleteAdmin(ActionEvent actionEvent) {
        Angajat angajat = listAngajati.getSelectionModel().getSelectedItem();
        ctrl.deleteAngajat(angajat);
    }

    public void handleAddButton(ActionEvent actionEvent) throws Exception {

        String denumire = textFieldDenumire.getText();
        String descriere = textFieldDescriere.getText();

        try {
            ctrl.addBug(denumire, descriere);
        }catch (Exception exception){
            showErrorMessage(exception.getLocalizedMessage());
        }
    }

    public void handleRemoveBug(ActionEvent actionEvent) {
        Bug bug = list.getSelectionModel().getSelectedItem();
        ctrl.removeBug(bug);

    }

    public void handleUpdateAngajat(ActionEvent actionEvent) {
        Angajat angajat = listAngajati.getSelectionModel().getSelectedItem();
        if(!angajat.getUsername().equals(textFieldNume.getText()) || !angajat.getPozitie().equals(textFieldPozitie.getText())){
            angajat.setUsername(textFieldNume.getText());
            angajat.setPozitie(textFieldPozitie.getText());
            ctrl.updateAngajat(angajat);
        }
    }
}