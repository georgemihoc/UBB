//
// Created by tudor on 21/05/2019.
//

#ifndef BAGOPENADRESSING_BAGITERATOR_H
#define BAGOPENADRESSING_BAGITERATOR_H

#include "Colectie.h"

class Colectie;

class Iterator {
    friend class Colectie;
private:
    Iterator(const Colectie& Bag): bag(Bag){
        current=0;
        sizeOf=bag.size();
        elems=new TElem[sizeOf];
        int k=0;
        for(int i=0;i<bag.capacity;i++){
            if(bag.elems[i]!=NULL_TElem)elems[k++]=bag.elems[i];
        }
    }
    const Colectie& bag;
    TElem* elems;
    int current;
    int sizeOf;

public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent();


};


#endif //BAGOPENADRESSING_BAGITERATOR_H
