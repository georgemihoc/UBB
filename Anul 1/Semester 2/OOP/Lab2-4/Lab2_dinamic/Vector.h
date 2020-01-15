//
// Created by George on 2019-03-13.
//

#ifndef LAB2_D_LIST_H
#define LAB2_D_LIST_H
#pragma once
#include "Domain.h"

typedef struct {

    Materie* elems;
    int lg;
    int capacitate;

}VectorDinamic;


VectorDinamic * creeaza_vector();

void distruge(VectorDinamic*);

void resize(VectorDinamic *v);

int exista(VectorDinamic *v, char* numar);

VectorDinamic* copy(VectorDinamic* v);

#endif //LAB2_D_LIST_H
