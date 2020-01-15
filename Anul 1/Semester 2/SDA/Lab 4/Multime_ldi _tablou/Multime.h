//
// Created by george on 30/03/2019.
//

#ifndef Multime_Multime_H
#define Multime_Multime_H

#pragma once

#include "MultimeIterator.h"
#include "Nod.h"

typedef int TElem;
class MultimeIterator;
class Multime {
    friend class MultimeIterator;
private:
    /* representation of Multime*/
    TElem *elemente;
    int *urmator;
    int *precedent;
    int capacitate;
    int dimensiune=0;
    int primul; // indexul primului element
    int prim_liber; // indexul primului loc disponibil
    int ultimul;

    void initializeaza_spatiu_liber();
    int aloca();
    void dealoca(int);
    int creeazaNod(TElem);

public:
    //implicit constructor
    Multime(int dimensiune=0);

    //adds an element to the  Multime
    //if the element was added, the operation returns true, otherwise (if the element was already in the Multime)
    //it returns false
    bool add(TElem e);

    MultimeIterator prim() const;


        //removes an element from the Multime
    //if the element was removed, it returns true, otherwise false
    bool remove(TElem e);



    //checks if an element is in the  Multime

    bool search(TElem elem) const;



    //returns the number of elements;

    int size() const;

    //checks if the Multime is empty
    bool isEmpty() const;

    //returns an iterator for the Multime
    MultimeIterator iterator() const;

    //destructor
    ~Multime();



};


#endif //Multime_Multime_H
