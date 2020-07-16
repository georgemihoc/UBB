package repository;


import model.Bug;
import model.Angajat;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.boot.MetadataSources;
import org.hibernate.boot.registry.StandardServiceRegistry;
import org.hibernate.boot.registry.StandardServiceRegistryBuilder;
import utils.JdbcUtils;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;


public class BugDbRepository implements IRepository<Integer, Bug> {
    private JdbcUtils dbUtils;

    public BugDbRepository(){
        dbUtils=new JdbcUtils(null);
    }

    static SessionFactory sessionFactory;
    static void initialize() {
        // A SessionFactory is set up once for an application!
        final StandardServiceRegistry registry = new StandardServiceRegistryBuilder()
                .configure() // configures settings from hibernate.cfg.xml
                .build();
        try {
            sessionFactory = new MetadataSources( registry ).buildMetadata().buildSessionFactory();
        }
        catch (Exception e) {
            StandardServiceRegistryBuilder.destroy( registry );
        }
    }

    static void close(){
        if ( sessionFactory != null ) {
            sessionFactory.close();
        }

    }

    @Override
    public int size() {
        initialize();
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();
                int size = session.createQuery("from Bug", Bug.class).list().size();
                System.out.println(size + " bug(s) found:");
                close();
                tx.commit();
                return size;
            } catch (RuntimeException ex) {
                if (tx != null)
                    tx.rollback();
            }
        }
        close();
        return 0;
    }

    @Override
    public void save(Bug entity) {

        initialize();
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();
                session.save(entity);
                tx.commit();
            } catch (RuntimeException ex) {
                if (tx != null)
                    tx.rollback();
            }
        }
        close();
    }

    @Override
    public void delete(Integer integer) {

        initialize();
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();
                Bug bug = findOne(integer);
                System.err.println("Delete bug " + bug.getDenumire());
                session.delete(bug);
                tx.commit();
            } catch (RuntimeException ex) {
                if (tx != null)
                    tx.rollback();
            }
        }
        close();
    }

    @Override
    public void update(Integer integer, Bug entity) {
        initialize();
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();
                session.update(entity);
                tx.commit();
            } catch (RuntimeException ex) {
                if (tx != null)
                    tx.rollback();
            }
        }
        close();    }

    @Override
    public Bug findOne(Integer integer) {

        initialize();
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();
                String queryString = "from Bug where idBug=" + integer;
                Bug bug = session.createQuery(queryString, Bug.class).getSingleResult();
                System.out.println(bug.getDenumire()+ " " + bug.getDescriere());
                tx.commit();
            } catch (RuntimeException ex) {
                if (tx != null)
                    tx.rollback();
            }
        }
        close();
        return null;
    }

    @Override
    public Iterable<Bug> findAll() {

        initialize();
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();
                List<Bug> bugs =
                        session.createQuery("from Bug ", Bug.class).getResultList();
                System.out.println(bugs.size() + " bugs found:");
                tx.commit();
                close();
                return bugs;
            } catch (RuntimeException ex) {
                if (tx != null)
                    tx.rollback();
            }
        }
        close();
        return null;
    }



}
