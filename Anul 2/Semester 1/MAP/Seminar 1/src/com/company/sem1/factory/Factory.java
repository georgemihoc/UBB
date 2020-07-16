package com.company.sem1.factory;

import com.company.sem1.container.Container;
import com.company.sem1.container.Strategy;

public interface Factory {
    Container createContainer(Strategy strategy);
}
