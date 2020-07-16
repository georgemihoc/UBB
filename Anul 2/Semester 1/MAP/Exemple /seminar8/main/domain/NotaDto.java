package domain;

public class NotaDto {
    private String studentName;
    private String temaId;
    private double nota;
    private String profesor;
    private int grupa;

    public NotaDto(String studentName, String temaId, double nota, String profesor, int grupa){
        this.studentName = studentName;
        this.temaId = temaId;
        this.nota = nota;
        this.profesor=profesor;
        this.grupa = grupa;
    }

    public String getStudentName() {
        return studentName;
    }

    public void setStudentName(String studentName) {
        this.studentName = studentName;
    }

    public String getTemaId() {
        return temaId;
    }

    public void setTemaId(String temaId) {
        this.temaId = temaId;
    }

    public double getNota() {
        return nota;
    }

    public void setNota(double nota) {
        this.nota = nota;
    }

    public String getProfesor() {
        return profesor;
    }

    public void setProfesor(String profesor) {
        this.profesor = profesor;
    }

    public int getGrupa() {
        return grupa;
    }

    public void setGrupa(int grupa) {
        this.grupa = grupa;
    }

    @Override
    public String toString() {
        return "NotaDto{" +
                "studentName='" + studentName + '\'' +
                ", temaId='" + temaId + '\'' +
                ", nota=" + nota +
                ", profesor='" + profesor + '\'' +
                '}';
    }
}
