package repository;


import model.Angajat;
import model.Bug;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.boot.MetadataSources;
import org.hibernate.boot.registry.StandardServiceRegistry;
import org.hibernate.boot.registry.StandardServiceRegistryBuilder;
import org.hibernate.cfg.Configuration;
import org.hibernate.service.ServiceRegistry;
import utils.JdbcUtils;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;


public class AngajatDbRepository implements IRepository<Integer, Angajat> {
    private JdbcUtils dbUtils;

    public AngajatDbRepository(){
        dbUtils=new JdbcUtils(null);
    }

    static SessionFactory sessionFactory;
    static void initialize() {
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
                int size = session.createQuery("from Angajat", Angajat.class).list().size();
                System.out.println(size + " angajat(s) found:");
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
    public void save(Angajat entity) {

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
                Angajat participant = findOne(integer);
                System.err.println("Delete angajat " + participant.getIdAngajat());
                session.delete(participant);
                tx.commit();
            } catch (RuntimeException ex) {
                if (tx != null)
                    tx.rollback();
            }
        }
        close();
    }

    @Override
    public void update(Integer integer, Angajat entity) {
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
    public Angajat findOne(Integer integer) {

        initialize();
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();
                String queryString = "from Angajat where idAngajat=" + integer;
                Angajat angajat = session.createQuery(queryString, Angajat.class).getSingleResult();
                tx.commit();
                return angajat;
            } catch (RuntimeException ex) {
                if (tx != null)
                    tx.rollback();
            }
        }
        close();
        return null;
    }

    @Override
    public Iterable<Angajat> findAll() {

        initialize();
        try(Session session = sessionFactory.openSession()) {
            Transaction tx = null;
            try {
                tx = session.beginTransaction();

                List<Angajat> angajati =
                        session.createQuery("from Angajat", Angajat.class).getResultList();
                System.out.println(angajati.size() + " angajati found:");
                tx.commit();
                close();
                return angajati;
            } catch (RuntimeException ex) {
                if (tx != null)
                    tx.rollback();
            }
        }
        close();
        return null;
    }



}
