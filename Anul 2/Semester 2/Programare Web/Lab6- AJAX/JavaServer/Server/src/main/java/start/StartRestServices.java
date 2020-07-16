package start;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.ComponentScan;


@ComponentScan("repository")
@SpringBootApplication
public class StartRestServices {
    public static void main(String[] args) {
//        LINK FOR TESTING:
//        http://localhost:8080/statii/all
        SpringApplication.run(StartRestServices.class, args);
    }
}

