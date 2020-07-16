package model;

public class Game {
    int idGame;
    int cell;
    String player;

    public Game(int cell, String player) {
        this.cell = cell;
        this.player = player;
    }

    public Game(int idGame, int cell, String player) {
        this.idGame = idGame;
        this.cell = cell;
        this.player = player;
    }

    public int getIdGame() {
        return idGame;
    }

    public void setIdGame(int idGame) {
        this.idGame = idGame;
    }

    public int getCell() {
        return cell;
    }

    public void setCell(int cell) {
        this.cell = cell;
    }

    public String getPlayer() {
        return player;
    }

    public void setPlayer(String player) {
        this.player = player;
    }
}
