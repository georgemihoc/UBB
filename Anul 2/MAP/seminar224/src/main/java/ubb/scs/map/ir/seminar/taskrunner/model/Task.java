package ubb.scs.map.ir.seminar.taskrunner.model;

import java.util.Objects;

public abstract class Task {

    private String taskId;
    private String description;

    public Task(String taskId, String description) {
        this.taskId = taskId;
        this.description = description;
    }

    //public Task(){}

    public String getTaskId() {
        return taskId;
    }

    public String getDescription() {
        return description;
    }

    public void setTaskId(String taskId) {
        this.taskId = taskId;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    @Override
    public String toString() {
        return taskId + " " + description;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Task)) return false;
        Task task = (Task) o;
        return Objects.equals(getTaskId(), task.getTaskId()) &&
                Objects.equals(getDescription(), task.getDescription());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getTaskId(), getDescription());
    }

    public abstract void execute();
}
