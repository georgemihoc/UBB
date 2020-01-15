package container;

import model.Task;

public class QueueContainer extends AbstractContainer{
    @Override
    public Task remove() {
        Task task = tasks[1];

        for(int i = 2;i <= size;i++)
            tasks[i - 1] = tasks[i];

        size--;
        return task;
    }
}
