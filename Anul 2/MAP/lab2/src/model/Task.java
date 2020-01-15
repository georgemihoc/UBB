package model;

        import java.util.Objects;

public abstract class Task {
    private String taskId;
    private String descriere;

    Task(String taskId, String descriere) {
        this.taskId = taskId;
        this.descriere = descriere;
    }

    protected Task() {
    }

    public String getTaskId() {
        return taskId;
    }

    public void setTaskId(String taskId) {
        this.taskId = taskId;
    }

    public String getDescriere() {
        return descriere;
    }

    public void setDescriere(String descriere) {
        this.descriere = descriere;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Task task = (Task) o;
        return Objects.equals(taskId, task.taskId) &&
                Objects.equals(descriere, task.descriere);
    }

    @Override
    public int hashCode() {
        return Objects.hash(taskId, descriere);
    }

    @Override
    public String toString() {
        return "id=" + taskId + "|" +
                "description=" + descriere + "|";
    }

    public void execute(){
        System.out.print(toString());
    };
}
