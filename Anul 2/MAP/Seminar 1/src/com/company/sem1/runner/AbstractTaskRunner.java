package com.company.sem1.runner;

import com.company.sem1.model.Task;
import com.company.sem1.runner.TaskRunner;

public class AbstractTaskRunner implements TaskRunner {
    private TaskRunner runner;

    public AbstractTaskRunner(TaskRunner runner) {
        this.runner= runner;
    }

    @Override
    public void executeOneTask() {
        runner.executeOneTask();
    }

    @Override
    public void executeAll() {
        while(runner.hasTask())
            executeOneTask();
    }

    @Override
    public void addTask(Task t) {
        runner.addTask(t);
    }

    @Override
    public boolean hasTask() {
        return runner.hasTask();
    }
}
