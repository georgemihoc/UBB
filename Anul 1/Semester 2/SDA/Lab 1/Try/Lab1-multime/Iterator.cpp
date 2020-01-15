//
// Created by George on 2019-03-29.
//

#include "Iterator.h"
#include "Multime.h"

typedef int TElem;

IteratorMultime::IteratorMultime(const Multime &c) :mult(c){
    index_curent=0;
}

void IteratorMultime::prim(){
    index_curent=0;
}

TElem IteratorMultime::element() const {
    //return mult.multime[index_curent];
    return mult.multime[index_curent];
}
bool IteratorMultime::valid() const {
    return index_curent<mult.dim();
}
void IteratorMultime::urmator() {
    ++index_curent;
}