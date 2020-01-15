//
// Created by george on 30/03/2019.
//

#include "Multime.h"

Multime::Multime(int capacity) {
    this->Size=0;
    this->capacity=capacity;
    this->elements= new TElem[capacity];
}

bool Multime::add(TElem e) {
    if(search(e))return false;
    else
    {
        if(Size==capacity){
            capacity*=2;
            TElem* newArray=new TElem[capacity];
            for(int i=0;i<Size;i++)newArray[i]=elements[i];
            delete[] elements;
            elements=newArray;
            elements[Size++]=e;
            return true;
        }
        else{
            elements[Size++]=e;
            return true;
        }
    }
}

bool Multime::remove(TElem e) {
    if(!search(e))return false;
    int positionToDelete=0;
    for(int i=0; i<Size;i++)if(elements[i]==e)positionToDelete=i;

    for(int i=positionToDelete;i<Size-1;i++){
        elements[i]=elements[i+1];
    }
    Size--;
    return true;
}

int Multime::size() const { return Size;}

bool Multime::search(TElem elem) const {
    for(int i=0;i<Size;i++)if(elements[i]==elem)return true;
    return false;
}

bool Multime::isEmpty() const { return (Size==0);}

Multime::~Multime() {
    delete[] elements;
}

MultimeIterator Multime::iterator() const {
    return MultimeIterator(*this);
}