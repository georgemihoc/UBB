package model;

public class Notebook {
    int id;
    String producator;
    String procesor;
    String ram;
    String capacitate;
    String graphics;

    public Notebook(int id, String producator, String procesor, String ram, String capacitate, String graphics) {
        this.id = id;
        this.producator = producator;
        this.procesor = procesor;
        this.ram = ram;
        this.capacitate = capacitate;
        this.graphics = graphics;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getProducator() {
        return producator;
    }

    public void setProducator(String producator) {
        this.producator = producator;
    }

    public String getProcesor() {
        return procesor;
    }

    public void setProcesor(String procesor) {
        this.procesor = procesor;
    }

    public String getRam() {
        return ram;
    }

    public void setRam(String ram) {
        this.ram = ram;
    }

    public String getCapacitate() {
        return capacitate;
    }

    public void setCapacitate(String capacitate) {
        this.capacitate = capacitate;
    }

    public String getGraphics() {
        return graphics;
    }

    public void setGraphics(String graphics) {
        this.graphics = graphics;
    }

    @Override
    public String toString() {
        return id + " " + producator + " " + procesor +  " " + ram + " " + capacitate + " " + graphics;
    }
}
