package repository;

import model.Statie;
import model.User;
import org.springframework.stereotype.Component;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;


@Component
public class UserRepository {
    private JdbcUtils dbUtils;


    public UserRepository() {
        dbUtils=new JdbcUtils();
    }


    public Iterable<User> findAll() {
        Connection con=dbUtils.getConnection();
        List<User> tasks=new ArrayList<>();
        try(PreparedStatement preStmt=con.prepareStatement("select * from User")) {
            try(ResultSet result=preStmt.executeQuery()) {
                while (result.next()) {
                    int id = result.getInt("id");
                    String nume = result.getString("nume");
                    String prenume = result.getString("prenume");
                    int telefon = result.getInt("telefon");
                    String email = result.getString("email");

                    User user = new User(id,nume,prenume,telefon,email);
                    tasks.add(user);
                }
            }
        } catch (SQLException e) {
            System.out.println("Error DB "+e);
        }
        return tasks;
    }
}
