//
// Created by tudor on 21/05/2019.
//

#include <exception>
#include "Iterator.h"


bool Iterator::valid() const {
    //theta(1)=AC=BC=WC
    if(current<sizeOf)return true;
    return false;
}

void Iterator::next() {
    //theta(1)=AC=WC=BC
    if (!valid())
        throw std::exception();
    current++;
}

TElem Iterator::getCurrent() {
    //theta(1)=AC=WC=BC
    if (!valid())
        throw std::exception();
    return elems[current];
}

void Iterator::first() {
    //theta(1)=AC=WC=BC
    current=0;
}

