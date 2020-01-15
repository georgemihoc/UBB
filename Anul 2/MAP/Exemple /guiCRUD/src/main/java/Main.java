import domain.MessageTask;
import domain.validators.MessageTaskValidator;
import repository.CrudRepository;
import repository.InFileMessageTaskRepository;
import services.MessageTaskService;

public class Main {
    public static void main(String[] args) {
//        CrudRepository<String, MessageTask> messageTaskRepository;
//        MessageTaskService messageTaskService;
//
//        messageTaskRepository = new InFileMessageTaskRepository
//                ("./data/Messages", new MessageTaskValidator());
//        messageTaskService=new MessageTaskService(messageTaskRepository);
//        messageTaskService.getAll().forEach(System.out::println);
       MainApp.main(args);
    }
}
