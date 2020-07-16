package controller;

import domain.Nota;
import domain.NotaDto;
import domain.Tema;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ListChangeListener;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.util.Callback;
import service.ServiceManager;

import java.util.List;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class NotaController {

    ObservableList<NotaDto> modelGrade = FXCollections.observableArrayList();

    private ServiceManager service;


    @FXML
    TableColumn<NotaDto, String> tableColumnName;
    @FXML
    TableColumn<NotaDto, String> tableColumnTema;
    @FXML
    TableColumn<NotaDto, Double> tableColumnNota;
    @FXML
    TableColumn<NotaDto, String> tableColumnProfesor;
    @FXML
    TableColumn<NotaDto, Integer> tableColumnGrupa;
    @FXML
    TableView<NotaDto> tableViewNote;
    //----------------------end TableView fx:id----------------

    @FXML
    TextField textFieldName;
    @FXML
    TextField textFieldTema;
    @FXML
    TextField textFieldNota;

    @FXML
    public void initialize() {
        tableColumnName.setCellValueFactory(new PropertyValueFactory<NotaDto,String>("studentName"));
        tableColumnNota.setCellValueFactory(new PropertyValueFactory<NotaDto,Double>("nota"));
        tableColumnTema.setCellValueFactory(new PropertyValueFactory<NotaDto,String>("temaId"));
        tableColumnProfesor.setCellValueFactory(new PropertyValueFactory<NotaDto,String>("profesor"));
        tableColumnGrupa.setCellValueFactory(new PropertyValueFactory<NotaDto,Integer>("grupa"));
        tableViewNote.setItems(modelGrade);

        textFieldName.textProperty().addListener(new ChangeListener<String>() {
            @Override
            public void changed(ObservableValue<? extends String> observable, String oldValue, String newValue) {
                handleFilter();
            }
        });
        //echivalent doar ca folosind functie lambda
        textFieldTema.textProperty().addListener((x,y,z) -> handleFilter());
    }

    private List<NotaDto> getNotaDTOList() {
        return service.findAllGrades()
                .stream()
                .map(n -> new NotaDto(n.getStudent().getName(), n.getTema().getId(), n.getValue(), n.getProfesor(),n.getStudent().getGroup()))
                .collect(Collectors.toList());
    }

    private void handleFilter() {
        Predicate<NotaDto> byName = n-> n.getStudentName().startsWith(textFieldName.getText());
        Predicate<NotaDto> byTema = n -> n.getTemaId().contains(textFieldTema.getText());
        List<NotaDto> list = getNotaDTOList();
        List<NotaDto> listaFiltrata = list.stream()
                .filter(byName.and(byTema))
                .collect(Collectors.toList());
        modelGrade.setAll(listaFiltrata);
}

    public void setService(ServiceManager service) {
        this.service = service;
        modelGrade.setAll(getNotaDTOList());
    }
}
