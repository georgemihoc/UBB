import java.util.*;

public class Main {
    public static String citire()
    {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }
    public static void main(String[] args) {
        String sir = "300+400*i + 2 + 4*i+2 + 20*i+2 + i";
        //String sir = citire();

        //String sir = "3+2*i * 1+4*i"; //Test pt inmultire
        String[] parts = sir.split("((?<= [+-/*] )|(?= [+-/*] ))");
        Character operator='+';
        int i=0,plus=0,minus=0,multiply=0;
        int real = 0, imaginar = 0;
        boolean ok = true;
        for (String s : parts) {
            if (s.equals(" - ")) {
                operator = '-';
                minus++;
                if(plus!=0 || multiply!=0)
                    ok=false;

            } else if (s.equals(" + ")) {
                operator = '+';
                plus++;
                if(minus!=0 || multiply!=0)
                    ok=false;
            } else if (s.equals(" * ")) {
                operator = '*';
                multiply++;
                if(plus!=0 || minus!=0)
                    ok=false;
            } else if (s.equals(" / ")) {
                operator = '/';
            } else if (!s.contains(" ") && s.contains("i") || s.matches("[0-9]+")) {
                    //Afisarea fiecarui numar
                    System.out.println("Nr complex\t" + s);
                    int[] ans = ExpressionParser.expression(s);
                    if (ans[0] == 0 && ans[1] == 0) {
                        ok = false;
                        break;
                    }
                    if (operator.equals('+')) {
                        real += ans[0];
                        imaginar += ans[1];
                    } else if (operator.equals('-')) {
                        real -= ans[0];
                        imaginar -= ans[1];
                    } else if (operator.equals('*')) {
                        if (real * imaginar == 0) {
                            real = 1;
                            imaginar = 1;
                        }
                        int realOld = real;
                        real = real * ans[0] - imaginar * ans[1];
                        imaginar = realOld * ans[1] + imaginar * ans[0];
                    }
            } else ok = false;
        }
        if (ok) {
            System.out.println("\nExpresia este corecta");
            System.out.println("\nResult: " + real + " + " + imaginar + "*i");
        } else {
            System.out.println("\nExpresia este incorecta");
        }
    }
}