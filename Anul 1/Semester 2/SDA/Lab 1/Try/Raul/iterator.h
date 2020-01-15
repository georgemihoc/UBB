//
// Created by raul on 05.03.2019.
//

#ifndef COPIELAB1_ITERATOR_H
#define COPIELAB1_ITERATOR_H

#endif //COPIELAB1_ITERATOR_H

#include "Header.h"
#pragma once
class Dictionar;

class IteratorDictionar{
    friend class Dictionar;
private:
    const Dictionar& dict;
    int index;
    IteratorDictionar(const Dictionar* dict);
public:
    //metode
};
