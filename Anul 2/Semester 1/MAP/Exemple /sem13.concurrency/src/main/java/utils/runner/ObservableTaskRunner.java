package utils.runner;

import domain.Task;
import domain.TaskExecutionException;
import utils.events.TaskExecutionStatus;
import utils.events.TaskStatusEvent;
import utils.observer.Observable;
import utils.observer.Observer;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.*;

public class ObservableTaskRunner implements TaskRunner, Observable<TaskStatusEvent> {
    protected List<Task> container;

    ExecutorService executor;

    public ObservableTaskRunner(List<Task> container) {
        this.container = container;
    }

    protected List<Observer<TaskStatusEvent>> observers=new ArrayList<>();

    @Override
    public void addObserver(Observer<TaskStatusEvent> e) {
        observers.add(e);
    }

    @Override
    public void removeObserver(Observer<TaskStatusEvent> e) {
        observers.remove(e);
    }

    @Override
    public  void notifyObservers(TaskStatusEvent t) {
        for(Observer<TaskStatusEvent> obs:observers)
            obs.update(t);
    }

    @Override
    public void executeOneTask() {
        if (container.size()!=0) {
            Task task = container.remove(0);
            notifyObservers(new TaskStatusEvent(TaskExecutionStatus.Running, task));
            task.execute();
            notifyObservers(new TaskStatusEvent(TaskExecutionStatus.Completed, task));
        }
    }

    @Override
    public void executeAll() {
       executor= Executors.newFixedThreadPool(container.size());
        List<Future<Void>> results=new ArrayList<>();
       container.forEach(t->{
           Callable<Void> callable=()-> {
               try {
                   notifyObservers(new TaskStatusEvent(TaskExecutionStatus.Running, t));
                   t.execute();
                   notifyObservers(new TaskStatusEvent(TaskExecutionStatus.Completed, t));
               } catch (TaskExecutionException te) {
                   notifyObservers(new TaskStatusEvent(TaskExecutionStatus.Cancelled, t));
               }
               return null;
           };
           results.add(executor.submit(callable));
       });

//       results.forEach(x-> {
//           try {
//               x.get();
//           } catch (InterruptedException e) {
//               e.printStackTrace();
//           } catch (ExecutionException e) {
//               e.printStackTrace();
//           }
//       });

        executor.shutdown();
    }

    @Override
    public void addTask(Task t) {
        container.add(t);
    }

    public void cancel(){
        if ((executor!=null)&& (!executor.isTerminated())){
            executor.shutdown();
        }
    }
    public void close(){
        if ((executor!=null)&&(!executor.isTerminated())){
            System.out.println("Shutting down executor ...");
            executor.shutdownNow();
        }
    }
}
