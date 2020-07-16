import java.sql.*;
import java.util.Calendar;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Main {
    public static void main(String[] args) {

//        RUN THE JAR:         java -jar JAR-NAME
        System.out.println("boss");

        try {
            String url = "jdbc:mysql://localhost:3306/JJJJ?characterEncoding=latin1";
            Connection conn = DriverManager.getConnection(url,"root","pass");
            Statement st = conn.createStatement();
            st.executeUpdate("INSERT INTO table_name " +
                    "VALUES (1)");

            conn.close();
        } catch (Exception e) {
            System.err.println("Got an exception! ");
            System.err.println(e.getMessage());
        }
    }
}
