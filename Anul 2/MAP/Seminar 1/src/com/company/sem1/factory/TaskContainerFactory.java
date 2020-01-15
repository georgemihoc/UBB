package com.company.sem1.factory;

import com.company.sem1.container.Container;
import com.company.sem1.container.QueueContainer;
import com.company.sem1.container.StackContainer;
import com.company.sem1.container.Strategy;

public class TaskContainerFactory implements Factory{
    private static TaskContainerFactory instance= null;
    //public static final TaskContainerFactory INSTANCE = new TaskContainerFactory();

    @Override
    public Container createContainer(Strategy strategy) {
        if(strategy == Strategy.LIFO)
            return new StackContainer();
        else
            return new QueueContainer();
    }
    private TaskContainerFactory(){

    }
    public static TaskContainerFactory getInstance(){
        if(instance==null)
            instance= new TaskContainerFactory();
        return instance;
    }
}
