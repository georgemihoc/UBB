package repository;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class JdbcUtils {
    private Properties jdbcProps;
    public JdbcUtils(Properties props){
        jdbcProps=props;
    }
    public JdbcUtils() {
        Properties serverProps = new Properties();
        try {
            serverProps.load(JdbcUtils.class.getResourceAsStream("/server.properties"));
//            System.out.println("Server properties set. ");
//            serverProps.list(System.out);
            jdbcProps = serverProps;

        } catch (Exception e) {
            System.err.println("Cannot find chatserver.properties " + e);
            return;
        }
    }
    private Connection instance=null;
    private Connection getNewConnection(){
//        String driver=jdbcProps.getProperty("swim.jdbc.driver");
//        String url=jdbcProps.getProperty("swim.jdbc.url");
        String url="jdbc:sqlite:/Users/george/Documents/UBB/Anul 2/Semester 2/Programare Web/Lab6- AJAX/ajaxDb.db";
        String user=jdbcProps.getProperty("tasks.jdbc.user");
        String pass=jdbcProps.getProperty("tasks.jdbc.pass");
        Connection con=null;
        try {
          //  Class.forName(driver);
         //   logger.info("Loaded driver ...{}",driver);
            if (user!=null && pass!=null)
                con= DriverManager.getConnection(url,user,pass);
            else
                con= DriverManager.getConnection(url);
        } /*catch (ClassNotFoundException e) {
            logger.error(e);
            System.out.println("Error loading driver "+e);
        } */catch (SQLException e) {
            System.out.println("Error getting connection "+e);
        }
        return con;
    }

    public Connection getConnection(){
        try {
            if (instance==null || instance.isClosed())
                instance=getNewConnection();

        } catch (SQLException e) {
            System.out.println("Error DB "+e);
        }
        return instance;
    }
}
