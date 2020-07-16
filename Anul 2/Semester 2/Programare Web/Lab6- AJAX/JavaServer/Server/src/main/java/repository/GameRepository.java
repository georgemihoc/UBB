package repository;

import model.Game;
import org.springframework.stereotype.Component;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Properties;
import java.util.concurrent.ThreadLocalRandom;

@Component
public class GameRepository {
    private JdbcUtils dbUtils;

    public GameRepository() {
        dbUtils=new JdbcUtils();
    }

//    public int size() {
//        Connection con=dbUtils.getConnection();
//        try(PreparedStatement preStmt=con.prepareStatement("select count(*) as [SIZE] from Game")) {
//            try(ResultSet result = preStmt.executeQuery()) {
//                if (result.next()) {
//                    return result.getInt("SIZE");
//                }
//            }
//        }catch(SQLException ex){
//            System.out.println("Error DB "+ex);
//        }
//        return 0;
//    }

    public void save(Game entity) {
        Connection con=dbUtils.getConnection();
        try(PreparedStatement preStmt=con.prepareStatement("insert into Game values (?,?,?)")){
            preStmt.setInt(1,entity.getCell());
            preStmt.setInt(2,entity.getCell());
            preStmt.setString(3,entity.getPlayer());
            int result=preStmt.executeUpdate();
        }catch (SQLException ex){
            System.out.println("Error DB "+ex);
        }

    }

    public void delete(Integer integer) {
        Connection con=dbUtils.getConnection();
        try(PreparedStatement preStmt=con.prepareStatement("delete from Game where cell=?")){
            preStmt.setInt(1,integer);
            int result=preStmt.executeUpdate();
        }catch (SQLException ex){
            System.out.println("Error DB "+ex);
        }
    }

//    @Override
//    public void update(Integer integer, Proba entity) {
//        Connection con = dbUtils.getConnection();
//        try (PreparedStatement preStmt = con.prepareStatement("update Proba set idProba = ? , lungime = ?, stil = ?,nrParticipanti=? where idProba=?")) {
//            preStmt.setInt(1, integer);
//            preStmt.setInt(2, entity.getLungime());
//            preStmt.setString(3, entity.getStil());
//            preStmt.setInt(4, entity.getNrParticipanti());
//            preStmt.setInt(5, integer);
//            int result = preStmt.executeUpdate();
//        } catch (SQLException ex) {
//            System.out.println("Error DB " + ex);
//        }
//    }
    public String findOne(Integer integer) {
        Connection con=dbUtils.getConnection();

        try(PreparedStatement preStmt=con.prepareStatement("select * from Game where cell=?")){
            preStmt.setInt(1,integer);
            try(ResultSet result=preStmt.executeQuery()) {
                if (result.next()) {
                    String player = result.getString("player");
                    return player;
                }
            }
        }catch (SQLException ex){
            System.out.println("Error DB "+ex);
        }

        return null;
    }

    public Iterable<Game> findAll() {
        Connection con=dbUtils.getConnection();
        List<Game> tasks=new ArrayList<>();
        try(PreparedStatement preStmt=con.prepareStatement("select * from Game")) {
            try(ResultSet result=preStmt.executeQuery()) {
                while (result.next()) {
                    int idGame = result.getInt("id");
                    int cell = result.getInt("cell");
                    String player = result.getString("player");
                    Game game = new Game(idGame, cell,player);
                    tasks.add(game);
                }
            }
        } catch (SQLException e) {
            System.out.println("Error DB "+e);
        }
        return tasks;
    }

    public String getComputedMove(){
        List<Integer> cells = new ArrayList<>();
        for (Game game :
                findAll()) {
            cells.add(game.getCell());
        }
        while(true){
            int position = ThreadLocalRandom.current().nextInt(1,10);
            if(!cells.contains(position)){
                save(new Game(position,"O"));
                return String.valueOf(position);
            }
        }
    }

    public String checkWin() {
        String[] pozitii = {"","","","","","","","","",""};
        List<Game> games = (List<Game>) findAll();
        for (Game game :
                games) {
            pozitii[game.getCell()] = game.getPlayer();
        }
        // Prima linie
        if(pozitii[1].equals(pozitii[2]) && pozitii[2].equals(pozitii[3]) && !pozitii[2].equals("")){
            return pozitii[1];
        }
        // A doua linie
        if(pozitii[4].equals(pozitii[5]) && pozitii[5].equals(pozitii[6]) && !pozitii[5].equals("")){
            return pozitii[4];
        }
        // A treia linie
        if(pozitii[7].equals(pozitii[8]) && pozitii[8].equals(pozitii[9]) && !pozitii[8].equals("")){
            return pozitii[7];
        }


        // Prima coloana
        if(pozitii[1].equals(pozitii[4]) && pozitii[4].equals(pozitii[7]) && !pozitii[4].equals("")){
            return pozitii[1];
        }
        // A doua coloana
        if(pozitii[2].equals(pozitii[5]) && pozitii[5].equals(pozitii[8]) && !pozitii[5].equals("")){
            return pozitii[4];
        }
        // A treia coloana
        if(pozitii[3].equals(pozitii[6]) && pozitii[6].equals(pozitii[9]) && !pozitii[6].equals("")){
            return pozitii[7];
        }


        // Diagnoala 1
        if(pozitii[1].equals(pozitii[5]) && pozitii[5].equals(pozitii[9]) && !pozitii[5].equals("")){
            return pozitii[1];
        }
        // Diagonala 2
        if(pozitii[3].equals(pozitii[5]) && pozitii[5].equals(pozitii[7]) && !pozitii[5].equals("")){
            return pozitii[4];
        }
        return "nu";
    }
}
