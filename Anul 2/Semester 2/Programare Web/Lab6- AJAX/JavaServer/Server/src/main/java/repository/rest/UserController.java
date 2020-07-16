package repository.rest;

import model.Statie;
import model.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import repository.StationRepository;
import repository.UserRepository;

import java.util.ArrayList;
import java.util.List;


@RestController
@CrossOrigin
@RequestMapping("/users/all")
public class UserController {


    @Autowired
    private UserRepository userRepository;

    @RequestMapping( method=RequestMethod.GET)
    public Iterable<User> getAll(){
        return userRepository.findAll();
    }

    @RequestMapping(value = "/{section}", method = RequestMethod.GET)
    public Iterable<User> getBySection(@PathVariable int section){
        List<User> rez = new ArrayList<>();
        int index = 0;
        for (User user : userRepository.findAll()){
            if((index / 3) + 1 == section){
                rez.add(user);
            }
            index++;
        }
        return rez;
    }


    @ExceptionHandler(Exception.class)
    @ResponseStatus(HttpStatus.BAD_REQUEST)
    public String userError(Exception e) {
        return e.getMessage();
    }
}
