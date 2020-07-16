package repository.rest;

import model.Statie;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import repository.StationRepository;

import java.util.ArrayList;
import java.util.List;


@RestController
@CrossOrigin
@RequestMapping("/statii/all")
public class StatiiController {


    @Autowired
    private StationRepository stationRepository;

    //Show all probe
    @RequestMapping( method=RequestMethod.GET)
    public Iterable<Statie> getAll(){
        return stationRepository.findAll();
    }

    //Get proba by id
    @RequestMapping(value = "/{start}", method = RequestMethod.GET)
    public List<String> getById(@PathVariable String start){
//        Proba proba=probaRepository.findOne(idProba);

//        if (proba==null)
//            return new ResponseEntity<String>("Proba not found",HttpStatus.NOT_FOUND);
//        else
//            return new ResponseEntity<String>(proba, HttpStatus.OK);
        List<String> rez = new ArrayList<>();
        for (Statie statie : stationRepository.findAll()){
            if(statie.getStart().equals(start)) {
                rez.add(statie.getStop());
            }
        }
        return rez;
    }
//
//    // Create and save
//    @RequestMapping(method = RequestMethod.POST)
//    public Proba create(@RequestBody Proba proba){
//            probaRepository.save(proba);
//            return proba;
//
//    }
//
//    // Update proba
//    @RequestMapping(value = "/{idProba}", method = RequestMethod.PUT)
//    public Proba update(@RequestBody Proba proba) {
//            System.out.println("Updating proba ...");
//             probaRepository.update(proba.getIdProba(),proba);
//             return proba;
//    }
//
//    //Delete proba
//    @RequestMapping(value="/{index}", method= RequestMethod.DELETE)
//    public ResponseEntity<?> delete(@PathVariable int index){
//        System.out.println("Deleting proba ... "+ probaRepository.findOne(index));
//        try {
//            probaRepository.delete(index);
//            return new ResponseEntity<Proba>(HttpStatus.OK);
//        }catch (Exception ex){
//            System.out.println("Delete proba exception");
//            return new ResponseEntity<String>(ex.getMessage(),HttpStatus.BAD_REQUEST);
//        }
//    }



    @ExceptionHandler(Exception.class)
    @ResponseStatus(HttpStatus.BAD_REQUEST)
    public String userError(Exception e) {
        return e.getMessage();
    }
}
