package ubb.scs.map.ir.seminar.taskrunner.container;


import ubb.scs.map.ir.seminar.taskrunner.model.Task;

public interface Container {
    Task remove();
    void add(Task task);
    int size();
    boolean isEmpty();
}



