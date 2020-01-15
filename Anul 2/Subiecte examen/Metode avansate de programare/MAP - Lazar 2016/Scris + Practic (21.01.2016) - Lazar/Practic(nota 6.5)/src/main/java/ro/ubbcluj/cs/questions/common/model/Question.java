package ro.ubbcluj.cs.questions.common.model;

public class Question {
    private int id;
    private String text;
    private String correctAnswer;

    public Question(){

    }

    public Question(String text, String a){
        this.id = 14;
        this.text = text;
    }

    public Question(int id, String text, String correctAnswer) {
        this.id = id;
        this.text = text;
        this.correctAnswer = correctAnswer;
    }

    public int getId() {
        return id;
    }

    public String getText() {
        return text;
    }

    public String getCorrectAnswer() {
        return correctAnswer;
    }

    @Override
    public String toString(){
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }
}