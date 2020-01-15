package com.company.sem1.runner;

public class PrinterTaskRunner extends AbstractTaskRunner{
    public PrinterTaskRunner(TaskRunner runner) {
        super(runner);
    }

    @Override
    public void executeOneTask() {
        super.executeOneTask();
        System.out.println("ora actuala");
    }
}
