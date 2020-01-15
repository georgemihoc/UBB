package ro.ubbcluj.cs.questions.server.repository;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;
import org.springframework.web.bind.annotation.RequestMapping;
import ro.ubbcluj.cs.questions.common.model.Question;

import java.util.List;

@Repository
public class QuestionRepository {

    @Autowired
    private JdbcTemplate jdbcTemplate;


    @RequestMapping("/api/question")
    public List<Question> findByUsername(String username) {
        return jdbcTemplate.query("select id, text, correctAnswer from questions ",
                (rs, lineNumber) -> new Question(rs.getInt("id"), rs.getString("text"), rs.getString("correctAnswer")));
    }

    @RequestMapping("/api/question/add")
    public void addPost(Question question) {
        jdbcTemplate.update("insert into questions (text, correctAnswer) values (?, ?)", question.getCorrectAnswer(), question.getText());
    }
}
