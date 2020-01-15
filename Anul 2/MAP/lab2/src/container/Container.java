package container;

import model.Task;

public interface Container {
    boolean isEmpty();
    Task remove();
    int size();
    void add(Task t);
}
