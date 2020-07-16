package event.hbm;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.boot.MetadataSources;
import org.hibernate.boot.registry.StandardServiceRegistry;
import org.hibernate.boot.registry.StandardServiceRegistryBuilder;

import java.util.Date;
import java.util.List;

public class MainEvent {
    private static SessionFactory sessionFactory;

    static void initialize() {
        // A SessionFactory is set up once for an application!
        final StandardServiceRegistry registry = new StandardServiceRegistryBuilder()
                .configure() // configures settings from hibernate.cfg.xml
                .build();
        try {
            sessionFactory = new MetadataSources( registry ).buildMetadata().buildSessionFactory();
        }
        catch (Exception e) {
            System.out.println("Exceptie "+e);
            StandardServiceRegistryBuilder.destroy( registry );
        }
    }

    static void close() {
        if ( sessionFactory != null ) {
            sessionFactory.close();
        }
    }

    public static void main(String ... arg) {
        initialize();

        try(Session session = sessionFactory.openSession()) {
            session.beginTransaction();
            session.save(new Event("First Event 22", new Date()));
            session.save(new Event("Second Event 23", new Date()));
            session.getTransaction().commit();
        }


         try(Session  session = sessionFactory.openSession()){
            session.beginTransaction();
            List result = session.createQuery("from Event").list();
            for (Event event : (List<Event>) result) {
                System.out.println("EventAnnot (" + event.getDate() + ") : " + event.getTitle());
            }
            session.getTransaction().commit();
        }

        close();
    }

}
