//
// Created by George on 2019-03-10.
//

#include "Teste.h"
#include "controllers.h"
#include "repository.h"
#include "Validator.h"
#include <assert.h>
#include <stdio.h>
#include "Materie.h"

/////////////////////////////////////////////////////////////////////////////
/////////TESTELE PENTRU REPOSITORY SE AFLA IN MODULUL REPOSITORY/////////////
/////////////////////////////////////////////////////////////////////////////

void teste_controller()
{
    /*
     * Functie de TESTE care testeaza functiile de adaugare, modificare si stergere din controller
     * input-Ø
     * output-Ø
     */
    ///TESTE ADAUGARE, MODIFICARE SI  STERGERE///
    char nume_1[20] = "abc";
    char producator_1[20] = "abc";
    int cantitate_1 = 1;
    assert(adaugare(nume_1,producator_1,cantitate_1)==0);//verificam ca se adauga elementul

    char nume_3[20] = "abc";
    char producator_3[20] = "abc";
    int cantitate_3 = 1;
    char nume_4[20] = "George";
    assert(modificare_controller(nume_1,producator_3,cantitate_3)==10);// verificam daca modifica
    assert(modificare_controller(nume_4,producator_3,cantitate_3)==-1); //verificam modificarea unui element inexistent

    assert(stergere_controller(nume_1));//verificam ca se sterge elementul tocmai adaugat

    char nume_2[20] = "a";
    char producator_2[20] = "a";
    int cantitate_2 = 0;
    assert(adaugare(nume_2,producator_2,cantitate_2)==3); //verificam ca nu se adauga elementul

}

void teste_validator()
{
    /*
     * Functie de TESTE care testeaza validatorul, corectitudinea functiei de validare de elemente
     * input-Ø
     * output-Ø
     */
    char nume_1[20] = "abc";
    char producator_1[20] = "abc";
    int cantitate_1 = 1;
    assert(valideaza_materie(nume_1,producator_1,cantitate_1) ==0); //verificam adaugarea cand toate sunt ok

    char nume_2[20] = "";
    char producator_2[20] = "abc";
    int cantitate_2 = 1;
    assert(valideaza_materie(nume_2,producator_2,cantitate_2) ==1);//verificam adaugarea cand nume e invalid

    char nume_3[20] = "a";
    char producator_3[20] = "";
    int cantitate_3 = 1;
    assert(valideaza_materie(nume_3,producator_3,cantitate_3) ==2); //verificam validarea cand producator e invalid

    char nume_4[20] = "a";
    char producator_4[20] = "a";
    int cantitate_4 = 0;
    assert(valideaza_materie(nume_4,producator_4,cantitate_4) ==3); //verificam validarea cand cantitatea  e invalida
}
void teste_vizualizare()
{
    /*
     * Functie de TESTE care testeaza cerinta d) de vizualizare dupa anumite criterii
     * input-Ø
     * output-Ø
     */
    Materie *a[100];
    char nume_1[20] = "abc";
    char producator_1[20] = "abc";
    int cantitate_1 = 100;
    adaugare_repo(nume_1,producator_1,cantitate_1); //adaugam elementul in lista
    //printf("%d",vizualizare_litera(a,'a'));
    assert(vizualizare_litera(a,'a')==1);///verificam daca functia de vizualizare_litera este corecta
    assert(vizualizare_litera(a,'b')==0);///verificam daca functia de vizualizare_litera este corecta

    assert(vizualizare_numar(a,5)==0);///verificam daca functia de vizualizare_numar este corecta
    assert(vizualizare_numar(a,101));///verificam daca functia de vizualizare_numar este corecta

    stergere_repo(nume_1);// stergem elementul adaugat
}