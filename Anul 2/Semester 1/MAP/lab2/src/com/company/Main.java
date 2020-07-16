package com.company;
import container.QueueContainer;
import container.StackContainer;
import container.Strategy;
import model.MessageTask;
import model.SortingStrategy;
import model.SortingTask;
import model.Task;
import runner.*;

import java.time.LocalDateTime;

import static model.SortingStrategy.BubbleSort;
import static model.SortingStrategy.QuickSort;

public class Main {

    public static void main(String[] args) {
        int[] array = {1,5,2,1,10,6,8,5,2};
        System.out.println("Bubble Sort");
        SortingTask sort1 = new SortingTask(BubbleSort,array, 8);
        sort1.execute();
        System.out.println("Quick Sort");
        SortingTask sort2 = new SortingTask(QuickSort,array, 8);
        sort2.execute();

        Task[] listTaskMessage = new MessageTask[5];
        listTaskMessage[0] = new MessageTask("1","mesaj", "Salut", "Mike", "Alex", LocalDateTime.now());
        listTaskMessage[1] = new MessageTask("2","mesaj", "Salut", "Stefan", "Mihai", LocalDateTime.now());
        listTaskMessage[2] = new MessageTask("3","mesaj", "Salut", "Vlad", "Raul", LocalDateTime.now());
        listTaskMessage[3] = new MessageTask("4","mesaj", "Salut", "Dani", "Filip", LocalDateTime.now());
        listTaskMessage[4] = new MessageTask("5","mesaj", "Salut", "Cristian", "Tudor", LocalDateTime.now());

        for(Task t:listTaskMessage)
            t.execute();
        System.out.print("Queue Container size:");
        QueueContainer c1 = new QueueContainer();
        c1.add(listTaskMessage[0]);
        System.out.println(c1.size());

        System.out.print("Stack Container size:");
        StackContainer c2 = new StackContainer();
        c2.add(listTaskMessage[0]);
        System.out.println(c2.size());

        //10

        Strategy strategy = null;
        if (args.length == 0) {
            System.out.println("Strategy undefined");
            return;
        }

        if (args[0].compareTo("LIFO") == 0)
            strategy = Strategy.LIFO;
        else if (args[0].compareTo("FIFO") == 0)
            strategy = Strategy.FIFO;

        if (strategy == null) {
            System.out.println("Strategy undefined");
            return;
        }
        System.out.println("10. Tasks using "+strategy+ " Strategy"); //from args parameters

        TaskRunner taskRunner = new StrategyTaskRunner(strategy);
        for(int i=0;i<5;i++)
            taskRunner.addTask(listTaskMessage[i]);
        taskRunner.executeAll();

        System.out.println("13. Tasks using "+strategy+ " Strategy and PrinterTaskRunner"); //from args parameters
        AbstractTaskRunner printerTaskRunner = new PrinterTaskRunner(taskRunner);
        for(int i=0;i<5;i++)
            printerTaskRunner.addTask(listTaskMessage[i]);
        printerTaskRunner.executeAll();

        System.out.println("14. Tasks using "+strategy+ " Strategy and DelayTask Runner 1 second delay"); //from args parameters

        AbstractTaskRunner delayTaskRunner = new DelayTaskRunner(taskRunner);
        for(int i=0;i<5;i++)
            delayTaskRunner.addTask(listTaskMessage[i]);
        AbstractTaskRunner printerTaskRunner2 = new PrinterTaskRunner(delayTaskRunner);
        printerTaskRunner2.executeAll();
    }
}