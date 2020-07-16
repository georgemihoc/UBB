package repository.rest;

import model.Game;
import model.Person;
import model.Statie;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import repository.GameRepository;
import repository.PersonRepository;


@RestController
@CrossOrigin
@RequestMapping("/person")
public class PersonController {


    @Autowired
    private PersonRepository personRepository;

    //Get proba by id
    @RequestMapping(value = "/{id}", method = RequestMethod.GET)
    public Person getById(@PathVariable int id){
        System.out.println("CEAU FRATE");
        return personRepository.findOne(id);
    }

//    // Update proba
    @RequestMapping(value = "/{id}", method = RequestMethod.PUT)
    public Person update(@RequestBody Person person) {
            System.out.println("Updating person ...");
//        System.out.println(person);
             personRepository.update(person.getId(),person);
             return person;
//        return null;
    }


    @ExceptionHandler(Exception.class)
    @ResponseStatus(HttpStatus.BAD_REQUEST)
    public String userError(Exception e) {
        return e.getMessage();
    }
}
