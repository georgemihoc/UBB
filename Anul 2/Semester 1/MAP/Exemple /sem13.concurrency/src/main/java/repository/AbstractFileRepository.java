package repository;

import domain.HasID;
import domain.validator.Validator;

import java.io.*;
import java.util.Arrays;
import java.util.List;

public abstract class AbstractFileRepository<ID, E extends HasID<ID>> extends InMemoryRepository<ID,E> {
    String fileName;
    public AbstractFileRepository(String fileName, Validator<E> validator) {
        super(validator);
        this.fileName=fileName;
        loadData();

    }

    private void loadData() {
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String linie;
            while((linie=br.readLine())!=null){
                List<String> attr=Arrays.asList(linie.split("\\|"));
                E e=extractEntity(attr);
                super.save(e);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }


    }

    public abstract E extractEntity(List<String> attributes);

    @Override
    public E save(E entity){
        E e=super.save(entity);
        if (e==null)
        {
            writeToFile(entity);
        }
        return e;
    }

    @Override
    public E update(E entity){
        E e=super.update(entity);
        if (e==null)
        {
            writeData();
        }
        return e;
    }

    private void writeData() {
        try (BufferedWriter bW = new BufferedWriter(new FileWriter(fileName))) {
            findAll().forEach(x->{
                try {
                    bW.write(x.toString());
                    bW.newLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }

            });
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    protected void writeToFile(E entity){
        try (BufferedWriter bW = new BufferedWriter(new FileWriter(fileName,true))) {
            bW.write(entity.toString());
            bW.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
