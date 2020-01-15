package container;

import model.Task;

public class StackContainer extends AbstractContainer{
    @Override
    public Task remove() {
        return tasks[size--];
    }
}
