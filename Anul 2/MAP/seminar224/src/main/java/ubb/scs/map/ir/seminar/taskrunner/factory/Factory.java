package ubb.scs.map.ir.seminar.taskrunner.factory;


import ubb.scs.map.ir.seminar.taskrunner.container.Container;
import ubb.scs.map.ir.seminar.taskrunner.container.Strategy;

public interface Factory {
    Container createContainer(Strategy startegy);
}

