package repository;

import model.Person;
import org.springframework.stereotype.Component;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

@Component
public class PersonRepository {

    private JdbcUtils dbUtils;

    public PersonRepository() {
        dbUtils=new JdbcUtils();
    }


    public void update(Integer integer, Person entity) {
        Connection con = dbUtils.getConnection();
        try (PreparedStatement preStmt = con.prepareStatement("update Person set  firstName = ?, lastName= ? where id=?")) {
            preStmt.setString(1, entity.getFirstName());
            preStmt.setString(2, entity.getLastName());
            preStmt.setInt(3, integer);

            int result = preStmt.executeUpdate();
        } catch (SQLException ex) {
            System.out.println("Error DB " + ex);
        }
    }

    public Person findOne(Integer integer) {
        Connection con=dbUtils.getConnection();

        try(PreparedStatement preStmt=con.prepareStatement("select * from Person where id=?")){
            preStmt.setInt(1,integer);
            try(ResultSet result=preStmt.executeQuery()) {
                if (result.next()) {
                    int idPerson = result.getInt("id");
                    String firstName = result.getString("firstName");
                    String lastName = result.getString("lastName");
                    Person person = new Person(idPerson,firstName,lastName);
                    return person;
                }
            }
        }catch (SQLException ex){
            System.out.println("Error DB "+ex);
        }

        return null;
    }
}
