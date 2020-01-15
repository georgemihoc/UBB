package map.seminar6;

import java.util.Arrays;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        List<String > list  = Arrays.asList("mno", "bcd", "asd", "clf");
        list.stream()
//                .sorted((x1,x2)->
//                {
//                    System.out.println("sorted:" + x1 + " " + x2);
//                    return x1.compareTo(x2);
//                })
                .filter(x->{
                    System.out.println("\nfilter: " + x);
                    return x.startsWith("m");
                })
                .map(x ->{
                    System.out.println("map: " + x);
                    return x.toUpperCase();
                })
                .sorted((x1,x2)->
                {
                    System.out.println("sorted:" + x1 + " " + x2);
                    return x1.compareTo(x2);
                })
                .forEach(s->{
                    System.out.print("forEach: ");
                    System.out.println(s);;
                });


    }
}
