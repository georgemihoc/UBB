//
// Created by george on 30/03/2019.
//

#include <exception>
#include "MultimeIterator.h"

TElem MultimeIterator::getCurrent() const {
    if(!valid())throw std::exception();
    else return Multime.elements[current];
}

void MultimeIterator::next() {
    if(!valid())throw std::exception();
    else current++;
}

void MultimeIterator::first() {
    current=0;
}

bool MultimeIterator::valid() const {
    return (current<Multime.size());
}