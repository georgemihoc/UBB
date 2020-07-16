package com.company.sem1.container;

import com.company.sem1.model.Task;

public interface Container {

    void remove();

    boolean isEmpty();
    
    void execute();

    void add(Task t);
}
