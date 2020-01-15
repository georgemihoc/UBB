//
// Created by George on 2019-03-29.
//
//Multime.h
typedef int TElem;

//typedef bool (*Relatie)(TElem, TElem);
//#include "Iterator.h"
//bool rel(TElem, TElem);
class IteratorMultime;
class Multime {
    friend class IteratorMultime;
private:
    TElem* multime;
    int size= 0;
    int capacitate=2;
public:
    Multime();


    bool adauga(TElem e);

    bool sterge(TElem e);

    bool cauta(TElem elem) const;


    int dim() const;

    bool vida() const;

    IteratorMultime iterator() const;

    ~Multime();

};



