//
// Created by george on 30/03/2019.
//

#include <exception>
#include "MultimeIterator.h"
class Multime;
MultimeIterator::MultimeIterator(const class Multime &l)
        :Multime(l)
{
    nod_curent = l.head;
}

TElem MultimeIterator::getCurrent() const {
    return nod_curent->value;
}

void MultimeIterator::next() {
    nod_curent = nod_curent->next;
}

void MultimeIterator::first() {
    nod_curent = Multime.head;
}

bool MultimeIterator::valid() const {
    return nod_curent != nullptr;
}