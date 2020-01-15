package ro.ubbcluj.cs.questions.client.service;


import org.apache.http.HttpHost;
import org.springframework.web.client.RestTemplate;
import ro.ubbcluj.cs.questions.common.model.Question;
import ro.ubbcluj.cs.questions.common.model.User;


public class QuestionClient {
    private static final String URL = "http://localhost:8080/api/question";
    private final HttpHost host = new HttpHost("localhost", 8080, "http");
    private User user;
    private AuthHttpComponentsClientHttpRequestFactory requestFactory;
    private RestTemplate restTemplate;

    public Question[] getAll() {
        return restTemplate.getForObject(URL, Question[].class);
    }

    public int getNumber() {
        int id = 0;
        for (Question item: this.getAll()
             ) {
            id++;
        }
        return id;
    }
    public Question getOne(int id) {
        for (Question item: this.getAll()
             ) {
            if (item.getId() == id) {
                return item;
            }
        }
        Question a = new Question(0,"","");
        return a;
    }

    public void setUser(User user) {
        this.user = user;
        requestFactory = new AuthHttpComponentsClientHttpRequestFactory(host, user);
        restTemplate = new RestTemplate(requestFactory);
    }

    public Question add(Question question) {
        return restTemplate.postForObject(URL + "/add", question, Question.class);
    }



    public User getUser() {
        return user;
    }
}

