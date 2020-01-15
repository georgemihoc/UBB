package ro.ubbcluj.cs.questions.server.controller;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.context.SecurityContextHolder;


import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import ro.ubbcluj.cs.questions.common.model.Question;
import org.springframework.security.core.userdetails.UserDetails;
import ro.ubbcluj.cs.questions.server.repository.QuestionRepository;

import java.util.ArrayList;
import java.util.List;

@RestController
public class QuestAppController {

    @Autowired
    private QuestionRepository questionRepository;


    @RequestMapping("/api/question")
    public List<Question>getAll(){
        UserDetails userDetails = (UserDetails) SecurityContextHolder.getContext().getAuthentication().getPrincipal();
        List<Question> questions = new ArrayList<Question>();

        questions.addAll(questionRepository.findByUsername(userDetails.getUsername()));
        return questions;
    }

    @RequestMapping("/api/question/add")
    public void addPost(@RequestBody Question question){
        questionRepository.addPost(question);

    }
}
