package utils.events;


import domain.Task;

public class TaskStatusEvent implements Event {
    private TaskExecutionStatus taskExecutionStatus;
    private Task task;
    public TaskStatusEvent(TaskExecutionStatus type, Task task) {
        this.task=task;
        this.taskExecutionStatus =type;
    }

    public Task getTask() {
        return task;
    }

    public void setTask(Task task) {
        this.task = task;
    }

    public TaskExecutionStatus getTaskExecutionStatus() {
        return taskExecutionStatus;
    }

    public void setTaskExecutionStatus(TaskExecutionStatus taskExecutionStatus) {
        this.taskExecutionStatus = taskExecutionStatus;
    }
}
