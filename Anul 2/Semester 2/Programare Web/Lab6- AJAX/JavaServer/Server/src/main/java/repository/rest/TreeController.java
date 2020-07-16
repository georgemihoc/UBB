package repository.rest;

import model.FileTree;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.*;

import java.io.File;
import java.util.ArrayList;
import java.util.List;


@RestController
@CrossOrigin
@RequestMapping("/tree")
public class TreeController {



    @RequestMapping( method=RequestMethod.GET)
    public FileTree getAll(){
//        return notebookRepository.findAll();
//        String tree =printDirectoryTree(new File("/Users/george/Documents/UBB/Anul 2/Semester 2/Programare Web/Lab6- AJAX/JavaServer/Server/src/main/java"));
//        System.out.println(tree);
//        return tree;


//        List<FileTree> list = new ArrayList<>();
        FileTree rootDetails = new FileTree("java","/Users/george/Documents/UBB/Anul 2/Semester 2/Programare Web/Lab6- AJAX/JavaServer/Server/src/main/java");

//        rootDetails.AllChildren = WalkDirectoryTree(root, list);
//        counterId = 0;
        return rootDetails;

//        return new File("/Users/george/Documents/UBB/Anul 2/Semester 2/Programare Web/Lab6- AJAX/JavaServer/Server/src/main/java");
    }

    public static String printDirectoryTree(File folder) {
        if (!folder.isDirectory()) {
            throw new IllegalArgumentException("folder is not a Directory");
        }
        int indent = 0;
        StringBuilder sb = new StringBuilder();
        printDirectoryTree(folder, indent, sb);
        return sb.toString();
    }

    private static void printDirectoryTree(File folder, int indent,
                                           StringBuilder sb) {
        if (!folder.isDirectory()) {
            throw new IllegalArgumentException("folder is not a Directory");
        }
        sb.append(getIndentString(indent));
        sb.append("<br>");
        sb.append("+--");
        sb.append(folder.getName());
        sb.append("/");
        sb.append("<br>");
        sb.append("\n");
        for (File file : folder.listFiles()) {
            if (file.isDirectory()) {
                printDirectoryTree(file, indent + 1, sb);
            } else {
                printFile(file, indent + 1, sb);
            }
        }

    }

    private static void printFile(File file, int indent, StringBuilder sb) {
        sb.append(getIndentString(indent));
        sb.append("+--");
        sb.append(file.getName());
        sb.append("\n");
    }

    private static String getIndentString(int indent) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < indent; i++) {
            sb.append("|  ");
        }
        return sb.toString();
    }
    //Get proba by id
//    @RequestMapping(value = "/{string}", method = RequestMethod.GET)
//    public List<Notebook> filter(@PathVariable String string){
//        System.out.println(string);
//        String[] parts = string.split(",");
//        String producator = parts[0];
//        String procesor = parts[1];
//        String ram = parts[2];
//        String capacitate = parts[3];
//        String graphics = parts[4];
//        List<Notebook> rez = new ArrayList<>();
//        for (Notebook notebook : notebookRepository.findAll()){
//            if(!((!producator.equals("blank") && !notebook.getProducator().equals(producator)) ||
//                    (!procesor.equals("blank") && !notebook.getProcesor().equals(procesor)) ||
//                    (!ram.equals("blank") && !notebook.getRam().equals(ram)) ||
//                    (!capacitate.equals("blank") && !notebook.getCapacitate().equals(capacitate)) ||
//                    (!graphics.equals("blank") && !notebook.getGraphics().equals(graphics)))){
//                rez.add(notebook);
//            }
//        }
//        return rez;
//    }


    @ExceptionHandler(Exception.class)
    @ResponseStatus(HttpStatus.BAD_REQUEST)
    public String userError(Exception e) {
        return e.getMessage();
    }
}