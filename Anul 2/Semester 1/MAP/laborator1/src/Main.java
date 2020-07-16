import java.util.*;

public class Main {
    public static String citire()
    {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    public static void main(String[] args) {
        //String sir = "300+400*i + 2 + 4*i+2 + 20*i+2 + i";
        //String sir = "300+400*i / 20*i+2";
        String sir = String.join(" ",args);

        //String sir = "3+2*i * 1+4*i"; //Test pt inmultire
        String[] parts = sir.split("((?<= [+-/*] )|(?= [+-/*] ))");
        Character operator='+';

        int i=0,plus=0,minus=0,multiply=0,divide=0;
        int real = 0, imaginar = 0;
        boolean ok = true;
        for (String s : parts) {
            if (s.equals(" - ")) {
                operator = '-';
                minus++;
                if(plus!=0 || multiply!=0 || divide!=0)
                    ok=false;

            } else if (s.equals(" + ")) {
                operator = '+';
                plus++;
                if(minus!=0 || multiply!=0 || divide!=0)
                    ok=false;
            } else if (s.equals(" * ")) {
                operator = '*';
                multiply++;
                if(plus!=0 || minus!=0 || divide!=0)
                    ok=false;
            } else if (s.equals(" / ")) {
                operator = '/';
                divide++;
                if(plus!=0 || minus!=0 || multiply!=0)
                    ok=false;
            } else if (!s.contains(" ") && s.contains("i") || s.matches("[0-9]+")) {
                //Afisarea fiecarui numar
                System.out.println("Nr complex\t" + s);
                ExpressionParser ans = ExpressionParser.expression(s);
                //int[] ans = ExpressionParser.expression(s);
                if (ans.real == 0 && ans.imaginar == 0) {
                    ok = false;
                    break;
                }
                if (operator.equals('+')) {
                    real += ans.real;
                    imaginar += ans.imaginar;
                } else if (operator.equals('-')) {
                    real -= ans.real;
                    imaginar -= ans.imaginar;
                } else if (operator.equals('*')) {
                    if (real * imaginar == 0) {
                        real = 1;
                        imaginar = 1;
                    }
                    int realOld = real;
                    real = real * ans.real - imaginar * ans.imaginar;
                    imaginar = realOld * ans.imaginar + imaginar * ans.real;
                }
                else if (operator.equals('/')){
                    real = (real*ans.real + imaginar*ans.imaginar) / (ans.real*ans.real + ans.imaginar*ans.imaginar);
                    imaginar = (ans.real*imaginar - real*ans.imaginar) / (ans.real*ans.real + ans.imaginar*ans.imaginar);
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