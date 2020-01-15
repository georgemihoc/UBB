package ubb.scs.map.ir.seminar.taskrunner;


import ubb.scs.map.ir.seminar.taskrunner.container.Strategy;
import ubb.scs.map.ir.seminar.taskrunner.model.MessageTask;
import ubb.scs.map.ir.seminar.taskrunner.runner.StrategyTaskRunner;
import ubb.scs.map.ir.seminar.taskrunner.runner.PrinterTaskRunner;

import java.time.LocalDateTime;

public class TestRunner {

    public static MessageTask[] createMessageTaskArray(){
        MessageTask t1=new MessageTask("1","Feedback lab1",
                "Ai obtinut 9.60","Gigi", "Ana", LocalDateTime.now());
        MessageTask t2=new MessageTask("2","Feedback lab1",
                "Ai obtinut 5.60","Gigi", "Ana", LocalDateTime.now());
        MessageTask t3=new MessageTask("3","Feedback lab3",
                "Ai obtinut 10","Gigi", "Ana", LocalDateTime.now());
        return new MessageTask[]{t1,t2,t3};
    }
    public static void main(String[] args) {
        MessageTask[] l=createMessageTaskArray();
        StrategyTaskRunner runner = new StrategyTaskRunner(Strategy.LIFO);
        runner.addTask(l[0]);
        runner.addTask(l[1]);
        runner.addTask(l[2]);
        //runner.executeAll();

        PrinterTaskRunner decorator = new PrinterTaskRunner(runner);
        decorator.executeAll();


    }

}


