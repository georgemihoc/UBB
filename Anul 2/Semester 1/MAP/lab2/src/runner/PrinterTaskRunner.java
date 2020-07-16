package runner;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class PrinterTaskRunner extends AbstractTaskRunner {
    public PrinterTaskRunner(TaskRunner taskRunner) {
        super(taskRunner);
    }
    private static final DateTimeFormatter DATE_TIME_FORMATTER = DateTimeFormatter.ofPattern("hh:mm");

    @Override
    public void executeOneTask() {
        super.executeOneTask();
        System.out.println("Task executed at " + LocalDateTime.now().format(DATE_TIME_FORMATTER));
    }
}
