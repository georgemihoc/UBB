//
// Created by raul on 03.03.2019.
//

#ifndef LAB1_HEADER_H
#define LAB1_HEADER_H

#endif //LAB1_HEADER_H

#pragma once
//#include "pch.h"
#include <iostream>
//#include "iterator.h"

#define len(array) (sizeof(array) / sizeof(array[0]))
typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

#define NULL_TVALOARE -1

/*
class Dictionar;


class IteratorDictionar{
    friend class Dictionar;
private:
    Dictionar *dict;
    int index;
public:
    IteratorDictionar(Dictionar *d){
        dict = d;
        index = -1;
    }
};

*/

class IteratorDictionar;

class Dictionar {
    friend class IteratorDictionar;

private:

    /* aici e reprezentarea */
    TElem **vector;
    int size = 0;
    int capacitate = 4;
public:

    // constructorul implicit al dictionarului
    Dictionar() {
        vector = (TElem **) malloc(sizeof(TElem *)*capacitate);
    }

    // adauga o pereche (cheie, valoare) in dictionar
    //daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
    // daca nu exista cheia, adauga perechea si returneaza null
    TValoare adauga(TCheie c, TValoare v) {
        TElem *e = (TElem *) malloc(sizeof(TElem));
        e->first = c;
        e->second = v;
        if (!size) {
            *vector = e;
            ++size;
            return NULL_TVALOARE;
        }
        if (cauta(c) == -1) {
            //nu mai exista cheia
            if(size < capacitate){
                vector[size] = e;
                ++size;
            } else {
                //redimensionare
                TElem *vect;
                TElem *aux;
                TElem **vect_aux = (TElem **) malloc(sizeof(TElem*)*capacitate*2);
                for (int i = 0; i < size; i++) {
                    vect = vector[i];
                    vect_aux[i] = vector[i];
                    aux = vect_aux[i];
                }
                vect_aux[capacitate] = e;
                TElem *capa = vect_aux[capacitate];
                /*for(int i=0;i<capacitate;i++){
                    free(vector[i]);
                }*/
                free(vector);
                vector = vect_aux;
                capacitate *= 2;
                ++size;
            }

            return NULL_TVALOARE;
        } else {
            //duplicat
            int pos = get_pos_cheie(c);
            if (pos != -1) {
                int aux = vector[pos]->second;
                vector[pos]->second = v;
                return aux;
            } else {
                printf("eroare la duplicat");
            }
        }
    }

    TCheie get_vector_cheie(int i) {
        return vector[i]->first;
    }

    TValoare get_vector_valoare(int i) {
        return vector[i]->second;
    }

    int get_pos_cheie(TCheie c){
        for(int i = 0;i<size;i++){
            if (vector[i]->first == c){
                return i;
            }
        }
        return -1;
    }

    //cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
    TValoare cauta(TCheie c) const {
        for (int i = 0; i < size; i++) {
            TElem *b = vector[i];
            int a = vector[i]->first;
            if (vector[i]->first == c) {

                return vector[i]->second;
            }
        }
        return NULL_TVALOARE;
    }

    //sterge o cheie si returneaza valoarea asociata (daca exista) sau null
    TValoare sterge(TCheie c) {
        if(cauta(c) != -1){
            int index = get_pos_cheie(c);
            TElem *to_delete = vector[index];
            int aux = vector[index]->second;
            for (int j = index; j < size-1; j++) {
                vector[j] = vector[j + 1];
            }
            free(to_delete);
            --size;
            TElem *cur;
            for (int j = 0; j < size; j++) {
                cur = vector[j];
            }
            return aux;
        }
        else return NULL_TVALOARE;
    }

    //returneaza numarul de perechi (cheie, valoare) din dictionar
    int dim() const {
        return size;
    }

    //verifica daca dictionarul e vid
    bool vid() const {
        return size == 0;
    }

    /*TElem get_first_pair() {
        return *vector;
    }*/

    int get_size() {
        return size;
    }

    // se returneaza iterator pe dictionar
    IteratorDictionar iterator() const{
        return IteratorDictionar(*this);
    }

    // destructorul dictionarului

    ~Dictionar() {};

};

//402 13:30
