package repository;

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
public class StationRepository {
    private JdbcUtils dbUtils;


    public StationRepository() {
        dbUtils=new JdbcUtils();
    }


    public Iterable<Statie> findAll() {
        Connection con=dbUtils.getConnection();
        List<Statie> tasks=new ArrayList<>();
        try(PreparedStatement preStmt=con.prepareStatement("select * from Prima")) {
            try(ResultSet result=preStmt.executeQuery()) {
                while (result.next()) {
                    int id = result.getInt("id");
                    String start = result.getString("start");
                    String stop = result.getString("stop");
                    Statie statie = new Statie(id,start,stop);
                    tasks.add(statie);
                }
            }
        } catch (SQLException e) {
            System.out.println("Error DB "+e);
        }
        return tasks;
    }
}
