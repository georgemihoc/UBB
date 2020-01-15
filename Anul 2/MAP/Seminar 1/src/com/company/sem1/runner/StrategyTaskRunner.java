package com.company.sem1.runner;

import com.company.sem1.container.Container;
import com.company.sem1.container.Strategy;
import com.company.sem1.factory.Factory;
import com.company.sem1.factory.TaskContainerFactory;
import com.company.sem1.model.Task;

public class StrategyTaskRunner  implements TaskRunner{
    private Container container;

    @Override
    public void executeOneTask() {
        if(!container.isEmpty())
            container.remove().execute();
    }

    @Override
    public void executeAll() {
        while(!container.isEmpty())
            executeOneTask();
    }

    @Override
    public void addTask(Task t) {
        container.add(t);
    }

    @Override
    public boolean hasTask() {
        return !container.isEmpty();
    }

    public StrategyTaskRunner(Strategy strategy) {
        this.container = TaskContainerFactory.getInstance().createContainer(strategy);
    }
}
