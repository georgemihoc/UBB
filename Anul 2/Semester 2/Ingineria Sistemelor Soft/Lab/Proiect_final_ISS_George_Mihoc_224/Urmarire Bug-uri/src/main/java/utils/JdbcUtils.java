package utils;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class JdbcUtils {
    private Properties jdbcProps;
    public JdbcUtils(Properties props){
        jdbcProps=props;
    }
    private Connection instance=null;
    private Connection getNewConnection(){
//        String driver=jdbcProps.getProperty("swim.jdbc.driver");
        String url="jdbc:sqlite:db/Bug";
        Connection con=null;
        try {
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
