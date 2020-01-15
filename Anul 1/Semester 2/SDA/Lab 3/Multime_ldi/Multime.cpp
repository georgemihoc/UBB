//
// Created by george on 30/03/2019.
//

#include "Multime.h"
#include <iostream>
using namespace std;
typedef int TElem;
Multime::Multime(int capacity) {
    dimensiune=capacity;
    head= nullptr;
    tail=nullptr;
}

Multime::~Multime() {

}

int Multime::size() const { return dimensiune;}

bool Multime::search(TElem e) const {
    if(dimensiune==0)
        return false;
    NodeDL *temp = head;
    MultimeIterator it(*this);
    while (temp->next!=NULL && temp->value != e) {
        temp = temp->next;
        it.next();
    }
    if (temp->value == e)
        return true;
    return false;
}

bool Multime::add(TElem e) {
    if(!search(e)){
        ++dimensiune;
        NodeDL *neww = (NodeDL *)malloc(sizeof(NodeDL));
        neww->value= e;
        neww->next=nullptr;
        neww->prev= nullptr;
        if(head== nullptr) {
            head = neww;
            tail = neww;
            //cout<<neww->value;
            return true;
        }
        tail->next = neww;
        neww->prev = tail;
        tail = neww;
        return true;
    } else
        return false;

}
/*
bool Multime::remove(TElem e) {
    if(!search(e) || this->dimensiune==0)
        return false;
    NodeDL *temp = head;
    MultimeIterator it(*this);
    //while (temp->next!=NULL && temp->value != e) {
    while (temp->value != e) {
        temp = temp->next;
        it.next();
    }
    if(temp->value==e){
        //TElem aux = it.nod_curent->value;
        it.nod_curent->prev->next = it.nod_curent->next;
        it.nod_curent->next->prev = it.nod_curent->prev;
        free(it.nod_curent);
        it.next();
        dimensiune--;
        return true;
    }
    return false;
}*/
bool Multime::remove(TElem e)
{
    if (this->dimensiune == 0) {
        return false;
    }
    if (!search(e)) {
        return false;
    }
    else {
        --this->dimensiune;
        NodeDL* temp = head;
        NodeDL* aux;
        //std::cout << temp->elem;
        if (temp->value == e ) {
            head = temp->next;
            free(temp);
            if (this->dimensiune == 0) {
                head = nullptr;
                tail = nullptr;
            }
            return true;
        }
        else if(temp->value == e){
            if (this->dimensiune == 0) {
                head = nullptr;
                tail = nullptr;
            }
            return true;
        }
        while (temp->next->value != e) {
            //std::cout << temp->elem;
            temp = temp->next;
        }
        aux = temp->next;
        temp->next = temp->next->next;
        free(aux);
        //free(temp->urm);
        if (this->dimensiune == 0) {
            head = nullptr;
            tail = nullptr;
        }

        return true;
    }
}

bool Multime::isEmpty() const { return (dimensiune==0);}


MultimeIterator Multime::iterator() const {
    return MultimeIterator(*this);
}