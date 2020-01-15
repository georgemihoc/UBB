// exersare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include "Header.h"
#include "iterator.h"

#pragma once

#include <assert.h>


void testAll() { //apelam fiecare functie sa vedem daca exista
    Dictionar d;
    assert(d.vid() == true);
    assert(d.dim() == 0); //adaug niste elemente
    assert(d.adauga(5, 5) == NULL_TVALOARE);
    assert(d.adauga(-3, -3) == NULL_TVALOARE);
    assert(d.adauga(7, 7) == NULL_TVALOARE);
    assert(d.adauga(1, 111) == NULL_TVALOARE);
    assert(d.adauga(10, 110) == NULL_TVALOARE);
    for (int i = 0; i < d.get_size(); i++) {
        printf("%d  %d\n", d.get_vector_cheie(i),d.get_vector_valoare(i));
    }

    assert(d.adauga(1, 1) == 111);
    assert(d.adauga(10, 10) == 110);

    assert(d.dim() == 5);
    assert(d.cauta(10) == 10);
    assert(d.cauta(16) == -1);
    assert(d.sterge(1) == 1);
    assert(d.sterge(6) == -1);
    assert(d.dim() == 4);

/*
    TElem e;
    IteratorDictionar id = d.iterator();
    id.prim();
    int s1 = 0, s2 = 0;
    while (id.valid()) {
        e = id.element();
        s1 += e.first;
        s2 += e.second;
        id.urmator();
    }
    assert(s1 == 19);
    assert(s2 == 19);
*/
}


int main(){

    /*Dictionar new_dict;
    new_dict.adauga(23, 32);
    printf("%d %d\n", new_dict.get_vector_cheie(0), new_dict.get_vector_valoare(0));
    new_dict.adauga(55, 55);
    printf("%d %d\n", new_dict.get_vector_cheie(1), new_dict.get_vector_valoare(1));
    TValoare val = new_dict.cauta(55);
    printf("%d\n", val);
    new_dict.adauga(55, 99);
    printf("%d %d\n", new_dict.get_vector_cheie(1), new_dict.get_vector_valoare(1));
    val = new_dict.cauta(55);
    printf("%d\n", val);
    val = new_dict.cauta(10);
    printf("%d\n", val);
    printf("\ninainte de stergere\n");
    for (int i = 0; i < new_dict.get_size(); i++) {
        printf("%d  %d\n", new_dict.get_vector_cheie(i), new_dict.get_vector_valoare(i));
    }
    new_dict.sterge(23);
    printf("dupa stergere");
    for (int i = 0; i < new_dict.get_size(); i++) {
        printf("\n%d  %d\n", new_dict.get_vector_cheie(i), new_dict.get_vector_valoare(i));
    }*/
    testAll();
    Dictionar D;
    IteratorDictionar id = D.iterator();
    while (id.valid()) {
        TElem e = id.element();
        // prelucrare element
        id.urmator();
    }
}
