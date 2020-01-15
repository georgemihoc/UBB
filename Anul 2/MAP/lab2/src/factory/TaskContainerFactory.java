package factory;

import container.Container;
import container.Strategy;
import container.StackContainer;
import container.QueueContainer;

///SINGLETON

public class TaskContainerFactory implements Factory{
    private static TaskContainerFactory instance = null;
    // TODO: Diff instance = null vs new TaskContainerFactory()
    // public static final TaskContainerFactory INSTANCE = new TaskContainerFactory();

    public Container createContainer(Strategy strategy){
        if(strategy == Strategy.LIFO)
            return new StackContainer();
        else
            return new QueueContainer();
    }

    private TaskContainerFactory() {

    }
    public static TaskContainerFactory getInstance(){
        if(instance == null)
            instance = new TaskContainerFactory();
        return instance;
    }
}
