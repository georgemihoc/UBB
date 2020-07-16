package container;

import model.Task;

public abstract class AbstractContainer implements Container {
    protected int size;
    protected Task tasks[];
    protected int capacity;


    AbstractContainer() {
        size = 0;
        capacity = 100;
        tasks = new Task[capacity];
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public int size() {
        return size;
    }

    private void resizeTaskArray(Task[] auxiliaryArray)
    {
        tasks = new Task[capacity];
        for(int i = 0;i < size;i++)
            tasks[i] = auxiliaryArray[i];
    }

    protected void checkCapacity() {
        if(capacity == size) {
            capacity += capacity / 2;
            resizeTaskArray(tasks);
        }
    }

    @Override
    public void add(Task t) {
        checkCapacity();
        tasks[++size] = t;
    }
}