//
// Created by george on 30/03/2019.
//

#include <exception>
#include "MultimeIterator.h"
class Multime;
MultimeIterator::MultimeIterator(const class Multime &l)
        :Multime(l)
{
    curent = l.primul;
}

TElem MultimeIterator::getCurrent() const {
    if (this->curent == -1)
        return -1;
        //throw std::exception();
    return this->Multime.elemente[this->curent];}

void MultimeIterator::next() {
    //if (curent == -1)
        //throw std::exception();
    curent = Multime.urmator[curent];}

void MultimeIterator::first() {
    curent = Multime.primul;

}

bool MultimeIterator::valid() const {
    return curent != -1;
}