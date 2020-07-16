package controller;


import domain.MessageTask;
import javafx.application.Platform;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.concurrent.Task;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.KeyEvent;
import service.MessageTaskService;
import utils.events.MessageTaskChangeEvent;
import utils.events.TaskStatusEvent;
import utils.observer.Observer;
import utils.runner.ObservableTaskRunner;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

public class MessageTaskController implements Observer<MessageTaskChangeEvent> {

    private MessageTaskService service;
    private ObservableList<MessageTask> model = FXCollections.observableArrayList();

    @FXML
    private TableView<MessageTask> tableView;
    @FXML
    private TableColumn<MessageTask, String> tableColumnDesc;
    @FXML
    private TableColumn<MessageTask, String> tableColumnFrom;
    @FXML
    private TableColumn<MessageTask, String> tableColumnTo;
    @FXML
    private TableColumn<MessageTask, String> tableColumnData;

    @FXML
    public void initialize() {
        tableColumnDesc.setCellValueFactory(new PropertyValueFactory<MessageTask, String>("description"));
        tableColumnFrom.setCellValueFactory(new PropertyValueFactory<MessageTask, String>("from"));
        tableColumnTo.setCellValueFactory(new PropertyValueFactory<MessageTask, String>("to"));
        tableColumnData.setCellValueFactory(new PropertyValueFactory<MessageTask, String>("date"));

        tableView.setItems(model);

        txtSubject.textProperty().addListener(x -> handleFilter());
        txtTo.textProperty().addListener(x -> handleFilter());
        txtFrom.textProperty().addListener(x -> handleFilter());
    }

    @Override
    public void update(MessageTaskChangeEvent messageTaskChangeEvent) {
        model.setAll(StreamSupport.stream(service.getAll().spliterator(), false)
                .collect(Collectors.toList()));
    }

    public void setMessageTaskService(MessageTaskService messageTaskService) {
        this.service = messageTaskService;
        messageTaskService.addObserver(this);
        initModel();
    }

    private void initModel() {
        List<MessageTask> list = StreamSupport.stream(service.getAll().spliterator(), false)
                .collect(Collectors.toList());
        model.setAll(list);
    }

    @FXML
    TextField txtFrom;

    @FXML
    TextField txtTo;

    @FXML
    TextField txtSubject;

    public void handleFilter() {
        String subject = txtSubject.getText();
        String from = txtFrom.getText();
        String to = txtTo.getText();
        Predicate<MessageTask> bySubjectPredicate = m -> m.getDescription().contains(subject);
        Predicate<MessageTask> fromPredicate = m -> m.getFrom().contains(from);
        Predicate<MessageTask> toPredicate = m -> m.getTo().contains(to);

        model.setAll(StreamSupport.stream(service.getAll().spliterator(), false)
                .filter(bySubjectPredicate.and(fromPredicate).and(toPredicate))
                .collect(Collectors.toList()));
    }

    public void handleFilterFrom(KeyEvent keyEvent) {
        handleFilter();
    }

    public void handleFilterBySubject(KeyEvent keyEvent) {
        handleFilter();
    }

    public void handleFilterTo(KeyEvent keyEvent) {
        handleFilter();
    }


    @FXML
    ProgressBar progressBar;
    @FXML
    ProgressIndicator indicatorBar;

    @FXML
    Label labelStatus;

    @FXML Button buttonSendMessagesAllAtOnce;
    @FXML Button buttonCancelSendMessages;

    @FXML private Button buttonSendMessagesOneByOne;

//-------------------------------------send messages concurrently using Executor ----------------//
    public void handleSendMessagesConcurrently(ActionEvent actionEvent) {
        clearTextArea();

        //TasksService tasksService=new TasksService(model.stream().collect(Collectors.toList()));
        ObservableTaskRunner runner=new ObservableTaskRunner(model.stream().collect(Collectors.toList()));
        Observer<TaskStatusEvent> observer=event-> {
            switch (event.getTaskExecutionStatus()) {
                case Running: {
                    appendMessageToTextArea("Starting execution of :" + event.getTask());
                    break;
                }
                case Completed: {
                    appendMessageToTextArea("Completed execution of " + event.getTask());
                    break;
                }
            }
        };

        runner.addObserver(observer);
        runner.executeAll();
//        tasksService.addTaskObserver(observer);
//        tasksService.executeAll();

    }

    @FXML
    TextArea taskExecutionStatusMessages;

    private void appendMessageToTextArea(String text){

        Platform.runLater(new Runnable() {
            @Override public void run() {
                taskExecutionStatusMessages.appendText(text+"\n" + "-------------------------------------"+"\n");
            }
        });

    }

    private void clearTextArea(){

        Platform.runLater(new Runnable() {
            @Override public void run() {
                taskExecutionStatusMessages.setText("");
            }
        });

    }


    //-------------------------------------send messages on separate Thread ----------------//
    private Task<List<MessageTask>> taskSendMessage;

    public Task<List<MessageTask>> createTask() {
        return new Task<List<MessageTask>>() {
            @Override
            protected List<MessageTask> call() throws Exception {
                List<MessageTask> messages = model.stream().collect(Collectors.toList());
                int index;
                List<MessageTask> result=new ArrayList<>();
                for (index = 0; index < messages.size(); index++) {
                    if (this.isCancelled() == true) {
                        return null;
                    } else {
                        MessageTask m = messages.get(index);
                        m.execute();
                        result.add(m);
                        updateMessage("Message -- " + m.getMessage() + " sent....");
                        updateProgress(index, messages.size() - 1);
                    }
                }
                    return result;
            }

        };
    }

    public void handleSendMessagesOneByOne(ActionEvent actionEvent) {

        taskSendMessage = createTask();

        //-----------------------task execution status monitoring ------------------------//
        progressBar.progressProperty().bind(taskSendMessage.progressProperty());
        indicatorBar.progressProperty().bind(taskSendMessage.progressProperty());
        labelStatus.textProperty().bind(taskSendMessage.messageProperty());


        buttonCancelSendMessages.setDisable(false);
        buttonSendMessagesOneByOne.setDisable(true);

        taskSendMessage.setOnSucceeded(x->{
            labelStatus.textProperty().unbind();
            labelStatus.setText(taskSendMessage.getValue().size() +" messages were sent....");


            buttonCancelSendMessages.setDisable(true);
            buttonSendMessagesOneByOne.setDisable(false);

        });

        Thread th=new Thread(taskSendMessage);
        //th.setDaemon(true);
        th.start();
    }

    public void handleCancelSendMessageButton(ActionEvent actionEvent) {

        taskSendMessage.cancel(true);

        progressBar.progressProperty().unbind();
        indicatorBar.progressProperty().unbind();
        labelStatus.textProperty().unbind();

        buttonCancelSendMessages.setDisable(true);
        buttonSendMessagesOneByOne.setDisable(false);

        progressBar.setProgress(0);
        indicatorBar.setProgress(0);
    }
}
