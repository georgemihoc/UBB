package service;

import domain.MessageTask;
import repository.CrudRepository;
import utils.events.ChangeEvent;
import utils.events.MessageTaskChangeEvent;
import utils.observer.Observable;
import utils.observer.Observer;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;

public class MessageTaskService implements Observable<MessageTaskChangeEvent> {
    private CrudRepository<String, MessageTask> repo;
    //private ObservableTaskRunner runner;

    public MessageTaskService(CrudRepository<String, MessageTask> repo) {
        this.repo = repo;
    }

    private <T> Iterable <T> filter(Iterable <T> list, Predicate<T> cond)
    {
        List<T> rez=new ArrayList<>();
        list.forEach((T x)->{if (cond.test(x)) rez.add(x);});
        return rez;
    }

    public Iterable<MessageTask> bySubject(String subject) {
        return filter(repo.findAll(), messageTask -> messageTask.getDescription().contains(subject));
    }



    public MessageTask addMessageTaskTask(MessageTask messageTask) {
        MessageTask task = repo.save(messageTask);
        if(task == null) {
            notifyObservers(new MessageTaskChangeEvent(ChangeEvent.ADD,task));
        }
        return task;
    }

    public MessageTask deleteMessageTask(MessageTask t){
        MessageTask task=repo.delete(t.getID());
        if(task!=null) {
            notifyObservers(new MessageTaskChangeEvent(ChangeEvent.DELETE, task));
        }
        return task;
    }

    public MessageTask updateMessageTask(MessageTask newTask) {
        MessageTask oldTask=repo.findOne(newTask.getID());
        if(oldTask!=null) {
            MessageTask res=repo.update(newTask);
            notifyObservers(new MessageTaskChangeEvent(ChangeEvent.UPDATE, newTask, oldTask));
            return res;
        }
        return oldTask;
    }

    public Iterable<MessageTask> getAll(){
        return repo.findAll();
    }

    private List<Observer<MessageTaskChangeEvent>> observers=new ArrayList<>();

    @Override
    public void addObserver(Observer<MessageTaskChangeEvent> e) {
        observers.add(e);

    }

    @Override
    public void removeObserver(Observer<MessageTaskChangeEvent> e) {
        //observers.remove(e);
    }

    @Override
    public void notifyObservers(MessageTaskChangeEvent t) {
        observers.stream().forEach(x->x.update(t));
    }
//
//    public void setTaskRunner(ObservableTaskRunner runner)
//    {
//        this.runner=runner;
//    }
//    public void addTaskToRunner(MessageTask task){
//        runner.addTask(task);
//    }
//    public void executeOneTask(){
//        runner.executeOneTask();
//    }
//
//    public void executeAll(){
//        runner.executeAll();
//    }
//
//    public void close(){
//        runner.close();
//    }
//
//    public void cancelRunner(){
//        runner.cancel();
//    }

}
