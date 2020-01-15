//
// Created by George on 2019-03-29.
//

//iterator unidirectional pe un Container
typedef int TElem;
class Multime;
class IteratorMultime {
    friend class Multime;
private:
    //constructorul primeste o referinta catre Container
    //iteratorul va referi primul element din container

    IteratorMultime(const Multime& c);

    //contine o referinta catre containerul pe care il itereaza
    const Multime& mult;
    int index_curent;


public:

    //reseteaza pozitia iteratorului la inceputul containerului
    void prim();

    //muta iteratorul in container
    // arunca exceptie daca iteratorul nu e valid
    void urmator();

    //verifica daca iteratorul e valid (indica un element al containerului)
    bool valid() const;

    //returneaza valoarea elementului din container referit de iterator
    //arunca exceptie daca iteratorul nu e valid
    TElem element() const;

};
