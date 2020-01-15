//
// Created by George on 2019-03-13.
//

#ifndef LAB2_D_DOMAIN_H
#define LAB2_D_DOMAIN_H
#pragma once

typedef struct {

    char * nume;
    char * producator;
    float cantitate;

}Materie;


Materie creeaza(char*, char*, float);

char* get_nume(Materie*);

char* get_producator(Materie*);

float get_cantitate(Materie*);

void set_cantitate(Materie*, float);

void set_nume(Materie*, char*);

void set_producator(Materie* m, char* producator);

void distruge_materie(Materie*m);

#endif //LAB2_D_DOMAIN_H
