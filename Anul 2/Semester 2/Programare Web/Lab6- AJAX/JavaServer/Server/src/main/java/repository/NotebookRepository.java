package repository;

import model.Notebook;
import model.Statie;
import org.springframework.stereotype.Component;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Properties;

@Component
public class NotebookRepository {
    private JdbcUtils dbUtils;


    public NotebookRepository() {
        dbUtils=new JdbcUtils();
    }


    public Iterable<Notebook> findAll() {
        Connection con=dbUtils.getConnection();
        List<Notebook> tasks=new ArrayList<>();
        try(PreparedStatement preStmt=con.prepareStatement("select * from Notebook")) {
            try(ResultSet result=preStmt.executeQuery()) {
                while (result.next()) {
                    int id = result.getInt("id");
                    String producator = result.getString("producator");
                    String procesor = result.getString("procesor");
                    String ram = result.getString("ram");
                    String capacitate = result.getString("capacitate");
                    String graphics = result.getString("graphics");
                    Notebook notebook = new Notebook(id,producator,procesor,ram,capacitate,graphics);
                    tasks.add(notebook);
                }
            }
        } catch (SQLException e) {
            System.out.println("Error DB "+e);
        }
        return tasks;
    }
}
