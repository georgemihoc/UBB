//
// Created by George on 2019-03-13.
//

#ifndef LAB2_D_SERVICE_H
#define LAB2_D_SERVICE_H
#pragma once

#include "Vector.h"

int adauga(VectorDinamic*, char*, char*, float);

int modificare(VectorDinamic *, char *, char *, float);

int sterge(VectorDinamic*, char*);

VectorDinamic *vizualizare_cantitate(VectorDinamic*, int );

VectorDinamic* vizualizare_litera(VectorDinamic*v, char);

void ordonare(VectorDinamic*, int(*func_sortare)(Materie* x, Materie* y), int ordine);

int comparare(Materie*, Materie*);

int comparareNume(Materie*, Materie*);
#endif //LAB2_D_SERVICE_H
