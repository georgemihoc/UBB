package service;

import domain.Task;
import utils.events.TaskStatusEvent;
import utils.observer.Observer;
import utils.runner.ObservableTaskRunner;

import java.util.List;

public class TasksService {

    private ObservableTaskRunner runner;

    public TasksService(List<Task> container) {
        this.runner = new ObservableTaskRunner(container);
    }

    public void addTaskObserver(Observer<TaskStatusEvent> observer) {
        runner.addObserver(observer);
    }

    public void excuteOneTask() {
        runner.executeOneTask();
    }

    public void executeAll() {
        runner.executeAll();
    }

    public void close() {
        runner.close();
    }

    public void cancelRunner() {
        runner.cancel();
    }
}

