//
// Created by george on 30/03/2019.
//

#ifndef Multime_MultimeITERATOR_H
#define Multime_MultimeITERATOR_H

#pragma once

#include "Multime.h"

typedef int TElem;
class Multime;
class MultimeIterator {
    friend class Multime;
private:
    //Constructor receives a reference of the container.

    //after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty
    MultimeIterator(const Multime  &s): Multime(s) {current=0;};
    const Multime& Multime;
    int current;
    //contains a reference of the container it iterates over
    /* representation specific for the iterator*/

public:
    //Multimes the iterator to the first element of the container
    void first();

    //moves the iterator to the next element
    //throws exception if the iterator is not valid
    void next();

    //checks if the iterator is valid
    bool valid() const;

    //returns the value of the current element from the iterator
    // throws exception if the iterator is not valid
    TElem getCurrent() const;
};

#endif //Multime_MultimeITERATOR_H
