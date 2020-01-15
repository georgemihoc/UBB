//
// Created by George on 2019-03-13.
//

#include "Teste.h"
#include "Domain.h"
#include "Service.h"
#include "Validator.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_creeaza()
{
    /*
	Functie care testeaza functia de creare a unui obiect de tipul Materie
    */
    Materie m;
    char nume[] = "tun", producator[] = "tun";

    m = creeaza(nume, producator, 1);
    assert(get_cantitate(&m) == 1);
    assert(strcmp(get_nume(&m), nume) == 0);
    assert(strcmp(get_producator(&m), producator) == 0);
    distruge_materie(&m);

    assert(m.nume == NULL);
    assert(m.producator == NULL);
    assert(m.cantitate == -1);
    //assert(m.concentratie == 0);

}

void test_adauga()
{
    /*
	Functie care testeaza adaugarea unui obiect de tip Materie in lista
    */
    char nume[] = "tun", producator[] = "tun";
    VectorDinamic *v;
    v = creeaza_vector();
    adauga(v, nume, producator, 2);
    assert(get_cantitate(&v->elems[0]) == 2);
    assert(strcmp(get_nume(&v->elems[0]), nume) == 0);
    assert(strcmp(get_producator(&v->elems[0]), producator) == 0);
    assert(v->lg == 1);
    assert(adauga(v, nume, producator, 2) == -1);
    nume[0] = '1'; //nume[1] = NULL;
    ///assert(adauga(v, nume, producator, 2) == -2);
    distruge(v);

}

void test_modificare()
{
    /*
	Functie care testeaza modificarea producatorului  si a cantitatii unui obiect de tip Materie
    */
    char nume[] = "tun", producator[] = "tun", nume2[] = "boss";
    VectorDinamic *v;
    v = creeaza_vector();
    adauga(v, nume, producator, 2);
    char producator2[] = "boss";
    modificare(v, nume, producator2, 2);
    assert(strcmp(get_producator(&v->elems[0]), producator2) == 0);
    assert(modificare(v, nume2, producator2, 2) == -1);
    distruge(v);

}

void test_sterge()
{
    /*
	Functie care testeaza stergerea din lista a unui obiect de tip Materie
    */
    char nume[] = "tun", producator[] = "tun";
    VectorDinamic *v;
    v = creeaza_vector();
    adauga(v, nume, producator, 2);
    char nume2[] = "boss", producator2[] = "boss", nume3[] = "george";
    adauga(v, nume2, producator2, 2);
    assert(v->lg == 2);
    sterge(v, nume);
    assert(v->lg == 1);
    assert(sterge(v, nume3) == -1);
    distruge(v);

}

void test_exista()
{
    /*
	Functie care testeaza functia care verifica daca exista un anumit obiect in lista
    */
    char nume[] = "tun", producator[] = "tun", nume2[] = "boss";
    VectorDinamic *v;
    v = creeaza_vector();
    adauga(v, nume, producator, 2);

    assert(exista(v, nume) == 0);
    assert(exista(v, nume2) == -1);
    distruge(v);

}

void test_resize()
{
    /*
	Functie care testeaza functia de resize
    */
    VectorDinamic *v;
    v = creeaza_vector();
    assert(v->capacitate == 100);
    char nume[] = "tun", producator[] = "tun";
    adauga(v, nume, producator, 2);
    resize(v);
    assert(v->capacitate == 200);
    assert(strcmp(get_nume(&v->elems[0]), nume) == 0);
    distruge(v);
}

void test_copy()
{
    /*
	Functie care testeaza functia de copiere
    */
    VectorDinamic *v, *c;
    v = creeaza_vector();
    char nume[] = "tun", producator[] = "tun";
    adauga(v, nume, producator, 2);
    char nume2[] = "boss", producator2[] = "boss";
    adauga(v, nume2, producator2, 2);
    c = copy(v);

    assert(strcmp(get_nume(&c->elems[0]), nume) == 0);
    assert(strcmp(get_producator(&c->elems[0]), producator) == 0);
    assert(get_cantitate(&c->elems[0]) == 2);

    assert(strcmp(get_nume(&c->elems[1]), nume2) == 0);
    assert(strcmp(get_producator(&c->elems[1]), producator2) == 0);
    assert(get_cantitate(&c->elems[1]) == 2);

    distruge(c);
    distruge(v);
}

void test_comparare()
{
    /*
	Functie care testeaza functia de comparare dupa cantitate
    */
    Materie m;
    char nume[] = "tun", producator[] = "tun";

    m = creeaza(nume, producator, 1);
    Materie m1;
    char nume2[] = "boss", producator2[] = "boss";

    m1 = creeaza(nume2, producator2, 3);
    assert(comparare(&m1, &m) == 0);
    assert(comparare(&m, &m1) == 1);
    distruge_materie(&m);
    distruge_materie(&m1);
}

void test_comparareNume()
{
    /*
	Functie care testeaza functia de comparare dupa nume
    */
    Materie m;
    char nume[] = "tun", producator[] = "tun";

    m = creeaza(nume, producator, 1);
    Materie m1;
    char nume2[] = "tun", producator2[] = "boss";

    m1 = creeaza(nume2, producator2, 3);
    assert(comparareNume(&m1, &m) == 0);
    //assert(comparareNume(&m, &m1) == 0);
    distruge_materie(&m);
    distruge_materie(&m1);
}


void test_ordonare()
{
    /*
	Functie care testeaza functia de ordonare
    */
    VectorDinamic *v, *c;
    v = creeaza_vector();
    char nume[] = "tun", producator[] = "tun";
    adauga(v, nume, producator, 2);
    char nume2[] = "boss", producator2[] = "boss";
    adauga(v, nume2, producator2, 1);

    c = copy(v);
    ordonare(c, comparare, 2);
    //ordonare(c, 2);

    assert(strcmp(get_nume(&c->elems[0]), nume) == 0);
    assert(strcmp(get_nume(&c->elems[1]), nume2) == 0);
    assert(get_cantitate(&c->elems[0]) == 2);
    assert(get_cantitate(&c->elems[1]) == 1);


    ordonare(c, comparare, 1);
    //ordonare(c, 1);
    assert(strcmp(get_nume(&c->elems[0]), nume2) == 0);
    assert(strcmp(get_nume(&c->elems[1]), nume) == 0);
    assert(get_cantitate(&c->elems[0]) == 1);
    assert(get_cantitate(&c->elems[1]) == 2);

    distruge(c);
    distruge(v);

}



void test_vizualizare_cantitate()
{
    /*
	Functie care testeaza functia de vizualizare dupa cantitate
    */
    VectorDinamic *v, *c;
    v = creeaza_vector();
    char nume[] = "tun", producator[] = "tun";
    adauga(v, nume, producator, 2);
    char nume2[] = "boss", producator2[] = "boss";
    adauga(v, nume2, producator2, 1);

    c = vizualizare_cantitate(v, 2);

    assert(strcmp(get_nume(&c->elems[0]), nume2) == 0);
    distruge(v);
    distruge(c);
}

void test_vizualizare_litera()
{
    /*
	Functie care t esteaza functia de vizualizare dupa litera
    */
    VectorDinamic *v, *p;
    v = creeaza_vector();
    char nume[] = "tanc", producator[] = "tun";
    adauga(v, nume, producator, 2);
    char nume2[] = "boss", producator2[] = "boss";
    adauga(v, nume2, producator2, 1);
    char nume3[] = "tun", producator3[] = "tun";
    adauga(v, nume3, producator3, 1);

    p = vizualizare_litera(v, 't');

    assert(strcmp(get_nume(&p->elems[0]), nume) == 0);
    assert(strcmp(get_nume(&p->elems[1]), nume3) == 0);
    assert(strcmp(get_nume(&p->elems[0]), nume2) !=0);

    assert(v->lg == 3);
    distruge(v);
    distruge(p);

}

void test_validator()
{
    /*
     * Functie care testeaza validatorul, corectitudinea functiei de validare de element
     */
    assert(valideazaMaterie("tun", "tun", 3) == 1);
    assert(valideazaMaterie("", "tun", -1) == -1);
    assert(valideazaMaterie("boss", "bo", -3) == -1);
    assert(valideazaMaterie("t", "tun", 3) == 1);
}

void ruleaza_teste()
{
    test_creeaza();
    test_adauga();
    test_modificare();
    test_sterge();
    test_exista();
    test_resize();
    test_copy();
    test_ordonare();
    test_vizualizare_cantitate();
    test_vizualizare_litera();
    test_comparare();
    test_comparareNume();
    test_validator();
}