//
// Created by George on 2019-03-29.
//

#include "Multime.h"
#include <stdlib.h>
typedef int TElem;

Multime::Multime() {
    multime = (TElem*)malloc(sizeof(TElem)*capacitate);
}

int Multime::dim() const {
    return size;
}
bool Multime::vida() const {
    return !size;
}
bool Multime::cauta(TElem elem) const {
    for (int i=0;i<size;i++){
        if(multime[i]==elem)
            return true;
    }
    return false;
}
bool Multime::adauga(TElem e) {
    if(cauta(e))
    {
        return false;
    }
    else{
        if (!size) {
            multime[size++] = e;
            return true;
        }
        if(size < capacitate){
            multime[size] = e;
            ++size;
        }
        else{
            //TElem vect;
            TElem* aux = (TElem*)malloc(sizeof(TElem)*capacitate*2);
            for(int i=0;i<size;i++)
            {
                aux[i] = multime[i];
            }
            free(multime);
            aux[capacitate]=e;
            capacitate*=2;
            multime=aux;
            ++size;
        }
    }
    return true;

}
bool Multime::sterge(TElem e) {
    int poz_sters=-1;
    for (int i=0;i<size;i++)
    {
        if(multime[i]==e) {
            poz_sters = i;
            break;
        }
    }
    if(poz_sters>=0)
    {
        for(int i=poz_sters;i<size-1;i++)
        {
            multime[i]=multime[i+1];
        }
        --size;
        return true;
    }
    return false;
}
IteratorMultime Multime::iterator() const {
    return IteratorMultime(*this);
}