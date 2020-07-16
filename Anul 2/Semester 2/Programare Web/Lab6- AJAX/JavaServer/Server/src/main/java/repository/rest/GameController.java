package repository.rest;

import model.Game;
import model.Statie;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import repository.GameRepository;
import repository.StationRepository;

import java.util.ArrayList;
import java.util.List;


@RestController
@CrossOrigin
@RequestMapping("/game")
public class GameController {


    @Autowired
    private GameRepository gameRepository;

    @RequestMapping( method=RequestMethod.GET)
    public Iterable<Game> getAll(){
        return gameRepository.findAll();
    }

    //Get proba by id
//    @RequestMapping(value = "/{start}", method = RequestMethod.GET)
//    public List<String> getById(@PathVariable String start){
//        List<String> rez = new ArrayList<>();
//        for (Statie statie : gameRepository.findAll()){
//            if(statie.getStart().equals(start)) {
//                rez.add(statie.getStop());
//            }
//        }
//        return rez;
//    }
//
    // Create and save
    @RequestMapping(method = RequestMethod.POST)
    public String create(@RequestBody String string){
        gameRepository.save(new Game(Integer.parseInt(string),"X"));
        String computedPosition = gameRepository.getComputedMove();
        String winningStatus = gameRepository.checkWin();
        System.out.println(winningStatus);
        if(!winningStatus.equals("nu")){
            if(winningStatus.equals("X"))
                computedPosition="10";
            else
                computedPosition="11";
        }
        return computedPosition;
    }

    @RequestMapping(value = "/{string}", method = RequestMethod.GET)
    public String createComputer(@PathVariable String string){
        System.out.println(string);
        return gameRepository.getComputedMove();
    }

    //Delete proba
    @RequestMapping(method= RequestMethod.DELETE)
    public void delete(){
        try {
            for(int i=1;i<10;i++){
                if(gameRepository.findOne(i)!= null){
                    gameRepository.delete(i);
                }
            }
        }catch (Exception ex){
            System.out.println("Delete proba exception");
        }
    }



    @ExceptionHandler(Exception.class)
    @ResponseStatus(HttpStatus.BAD_REQUEST)
    public String userError(Exception e) {
        return e.getMessage();
    }
}
