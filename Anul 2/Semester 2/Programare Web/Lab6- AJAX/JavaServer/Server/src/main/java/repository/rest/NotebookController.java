package repository.rest;

import model.Notebook;
import model.Statie;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import repository.NotebookRepository;
import repository.StationRepository;

import java.util.ArrayList;
import java.util.List;


@RestController
@CrossOrigin
@RequestMapping("/notebook")
public class NotebookController {


    @Autowired
    private NotebookRepository notebookRepository;

    @RequestMapping( method=RequestMethod.GET)
    public Iterable<Notebook> getAll(){
        return notebookRepository.findAll();
    }


    //Get proba by id
    @RequestMapping(value = "/{string}", method = RequestMethod.GET)
    public List<Notebook> filter(@PathVariable String string){
        System.out.println(string);
        String[] parts = string.split(",");
        String producator = parts[0];
        String procesor = parts[1];
        String ram = parts[2];
        String capacitate = parts[3];
        String graphics = parts[4];
        List<Notebook> rez = new ArrayList<>();
        for (Notebook notebook : notebookRepository.findAll()){
            if(!((!producator.equals("blank") && !notebook.getProducator().equals(producator)) ||
                    (!procesor.equals("blank") && !notebook.getProcesor().equals(procesor)) ||
                    (!ram.equals("blank") && !notebook.getRam().equals(ram)) ||
                    (!capacitate.equals("blank") && !notebook.getCapacitate().equals(capacitate)) ||
                    (!graphics.equals("blank") && !notebook.getGraphics().equals(graphics)))){
                rez.add(notebook);
            }
        }
        return rez;
    }


    @ExceptionHandler(Exception.class)
    @ResponseStatus(HttpStatus.BAD_REQUEST)
    public String userError(Exception e) {
        return e.getMessage();
    }
}