package start;

import chat.model.User;
import chat.services.rest.ServiceException;
import org.springframework.web.client.RestClientException;
import org.springframework.web.client.RestTemplate;
import rest.client.UsersClient;

/**
 * Created by grigo on 5/11/17.
 */
public class StartRestClient {
    private final static UsersClient usersClient=new UsersClient();
    public static void main(String[] args) {
        RestTemplate restTemplate=new RestTemplate();
        User userT=new User("test123","133","Test 1");
        try{
      //  User result= restTemplate.postForObject("http://localhost:8080/chat/users",userT, User.class);

      //  System.out.println("Result received "+result);
      /*  System.out.println("Updating  user ..."+userT);
        userT.setName("New name 2");
        restTemplate.put("http://localhost:8080/chat/users/test124", userT);

*/
           // System.out.println(restTemplate.postForObject("http://localhost:8080/chat/users",userT, User.class));
            //System.out.println( restTemplate.postForObject("http://localhost:8080/chat/users",userT, User.class));

        show(()-> System.out.println(usersClient.create(userT)));
        show(()->{
            User[] res=usersClient.getAll();
            for(User u:res){
                System.out.println(u.getId()+": "+u.getName());
            }
        });
        }catch(RestClientException ex){
            System.out.println("Exception ... "+ex.getMessage());
        }

    }



    private static void show(Runnable task) {
        try {
            task.run();
        } catch (ServiceException e) {
          //  LOG.error("Service exception", e);
            System.out.println("Service exception"+ e);
        }
    }
}
