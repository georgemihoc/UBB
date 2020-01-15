//
// Created by George on 2019-03-07.
//

#include "repository.h"
#include "Materie.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//Materie v[100];
//int i=0;

Materie elems[100];
//Materie *elems = (Materie *)malloc(sizeof(Materie));

//Materie *elems = malloc(sizeof(Materie));
int i=0;
/*
Materie * creazaVectorDinamic() {
    Materie *v =malloc(sizeof(Materie));
    v->nume = malloc(sizeof(char));
    v->producator = malloc(sizeof(char));
    v->cantitate = 0;
    return v;
}*/
Materie creeaza(char nume[20], char producator[20], int cantitate)
{

    Materie m;
    strcpy(m.nume, nume);
    strcpy(m.producator, producator);
    m.cantitate = cantitate;
    return m;

}

int adaugare_repo(char nume[20], char producator[20], int cantitate)
{
    /*
     * Functie Void care adauga un element nou in lista de elemente
     * input- nume, producator, cantitate
     * preconditii- nume,producator-sir de caractere, cantitate-nr intreg
     * output- Functie Void
     * postconditii- Ø
     */
    int ok = 0;
    for (int j = 1;j<=i;j++)
    {
        if(strcmp(elems[i].nume,nume)==0) {
            strcpy(elems[i].producator, producator);
            elems[i].cantitate = cantitate;
            ok = 1;
        }
    }
    if (ok==0)
    {
        i++;
        strcpy(elems[i].nume, nume);
        strcpy(elems[i].producator, producator);
        elems[i].cantitate=cantitate;
    }
    return ok;
}
int modificare_repo(char nume_1[20],char producator_nou[20],int cantitate_nou)
{
    /*
     * Functie care modifica un element din lista de elemente si returneaza un ok pentru a sti daca a fost modificat
     * elementul cu succes sau nu.
     * input- nume_1, producator_nou, cantitate_nou
     * preconditii- nume_1,producator_nou-sir de caractere, cantitate_nou-nr intreg
     * output- ok -> -1 daca nu a fost gasit elementul sau 10 daca a fost gasit si modificat
     * postconditii- ok->numere  intreg
     */
    int ok = -1;
    for (int j = 1;j<=i;j++)
    {
        if(strcmp(elems[j].nume,nume_1)==0)
        {
            strcpy(elems[j].producator, producator_nou);
            elems[j].cantitate =  cantitate_nou;
            ok = 10;
        }
    }
    return ok;
}
int stergere_repo(char nume_1[20])
{
    /*
     * Functie care sterge un element din lista de elemente si returneaza un ok pentru a sti daca a fost sters
     * input- nume_1-numele elementului care trebuie sters
     * preconditii- nume_1-sir de caractere
     * output- ok- marcheaza daca a fost gasit si sters elementul
     * postconditii- ok-nr intreg
     */
    Materie elems_2[100];
    int ok = -1,k=0;
    for(int j=1;j<=i;j++)
    {
        if (strcmp(elems[j].nume,nume_1)== 0)
            ok = 1;
        else
        {
            k++;
            elems_2[k]= elems[j];
        }
    }
    //for (int j = 1;j <= i;j++)
        //elems[j] = NULL;
    i = k;
    for (int j = 1;j <= i;j++)
        elems[j] = elems_2[j];
    return ok;
}
void sortare_nume_repo(char ordine[20])
{
    /*
     * Functie care sorteaza elementele dupa numele lor(in mod crescator sau descrescator)
     * input- ordine
     * preconditii- ordine-> caracter care semnifica modul de sortare (C-crescator, D-descrescator)
     * output- Functie void
     * postconditii- Ø
     */
    for (int j = 1; j < i; j++) {
        for (int k = j + 1; k <= i; k++) {
            if (strcmp(ordine, "c") == 0 && strcmp(elems[k].nume, elems[j].nume) < 0) {
                //printf("boss");
                Materie aux;
                aux = elems[j];
                elems[j] = elems[k];
                elems[k] = aux;
            } else if (strcmp(ordine, "d") == 0 && strcmp(elems[k].nume, elems[j].nume) > 0) {
                Materie aux;
                aux = elems[j];
                elems[j] = elems[k];
                elems[k] = aux;
            }
        }
    }
}
void sortare_cantitate_repo(char ordine[20])
{
    /*
     * Functie care sorteaza elementele dupa cantitatea lor(in mod crescator sau descrescator)
     * input- ordine
     * preconditii- ordine-> caracter care semnifica modul de sortare (C-crescator, D-descrescator)
     * output- Functie Void
     * postconditii- Ø
     */
    for (int j = 1; j < i; j++) {
        for (int k = j + 1; k <= i; k++) {
            if (strcmp(ordine, "c") == 0 && elems[k].cantitate < elems[j].cantitate) {
                //printf("boss");
                Materie aux;
                aux = elems[j];
                elems[j] = elems[k];
                elems[k] = aux;
            } else if (strcmp(ordine, "d") == 0 && elems[k].cantitate > elems[j].cantitate) {
                Materie aux;
                aux = elems[j];
                elems[j] = elems[k];
                elems[k] = aux;
            }
        }
    }
}
int getAll_repo(Materie *a[100])
{
    /*
     * Functie de getAll() care aduna toate elementele din vectorul de elemente
     * input- a
     * preconditii-a-> vectorul de materii nou unde stocam elementele gasite
     * output- i-> numarul de elemente din vector
     * postconditii- i->numar natural pozitiv
     */
    //return elems;
    for (int j = 1;j<=i;j++) {
        a[j] = &elems[j];
        //printf("%d", a[j]->cantitate);
    }
    return i;
}

////////////////////////////////////////////////////
//////////////// TESTE  REPOSITORY ////////////////////
////////////////////////////////////////////////////

void teste_adaugare()
{
    /*
     * Functie de TESTE care testeaza adaugarea unui element
     * input-Ø
     * output-Ø
     */
    char nume_1[20] = "abc";
    char producator_1[20] ="abc";
    int cantitate_1= 1;
    assert(adaugare_repo(nume_1,producator_1,cantitate_1)==0); //verificam adaugarea

    assert(strcmp(elems[i].nume ,nume_1)==0);
    assert(strcmp(elems[i].producator,producator_1)==0);
    assert(elems[i].cantitate == cantitate_1);

    char nume_2[20] = "abc";
    char producator_2[20] ="bbbb";
    int cantitate_2= 5;
    assert(adaugare_repo(nume_2,producator_2,cantitate_2) == 1); // verificam adaugarea unui element cu acelasi nume

    assert(strcmp(elems[i].nume ,nume_1)==0);
    assert(strcmp(elems[i].producator,producator_2)==0);
    assert(elems[i].cantitate == cantitate_2);
}
void teste_stergere()
{
    /*
     * Functie de TESTE care testeaza stergerea unui element
     * input-Ø
     * output-Ø
     */
    char nume[20] = "abc";
    char nume_2[20] = "George";

    assert(stergere_repo(nume_2)); // verificam stergerea cand numele nu exista

    assert(stergere_repo(nume));//sterge un element

    assert(stergere_repo(nume) == -1);// verificam stergerea cand lista este goala
}
void teste_modificare()
{
    /*
     * Functie de TESTE care testeaza modificarea unui element
     * input-Ø
     * output-Ø
     */
    char nume_1[20] = "abc";
    char producator_1[20] ="abc";
    int cantitate_1= 1;
    assert(adaugare_repo(nume_1,producator_1,cantitate_1)==0);//adaugam un element

    char producator_2[20] ="bbbbb";
    int cantitate_2= 5;
    char nume_2[20] = "aaa";
    assert(modificare_repo(nume_1,producator_2,cantitate_2)==10); // verificam modificarea elementului
    assert(modificare_repo(nume_2,producator_2,cantitate_2)==-1);// verificam modificarea unui element inexistent

    assert(stergere_repo(nume_1)); //stergem elementul adaugat anterior
}
void teste_sortare()
{
    /*
     * Functie de TESTE care testeaza toate sortarile cerute de problema
     * input-Ø
     * output-Ø
     */
    char nume_1[20] = "a";
    char producator_1[20] ="a";
    int cantitate_1= 1;
    adaugare_repo(nume_1,producator_1,cantitate_1); //adaugam primul element

    char nume_2[20] = "b";
    char producator_2[20] ="b";
    int cantitate_2= 2;
    adaugare_repo(nume_2,producator_2,cantitate_2);//adaugam al doilea element
    sortare_nume_repo("d"); ///testam sortarea in functie de nume in mod descrescator
    assert(strcmp(elems[1].nume,nume_2)==0);
    sortare_nume_repo("c"); ///testam sortarea in functie de nume in mod crescator
    assert(strcmp(elems[1].nume,nume_1)==0);

    sortare_cantitate_repo("c");///testam sortarea in functie de cantitate in mod crescator
    assert(strcmp(elems[1].nume,nume_1)==0);
    sortare_cantitate_repo("d");///testam sortarea in functie de cantitate in mod descrescator
    assert(strcmp(elems[1].nume,nume_2)==0);


    stergere_repo(nume_1);//eliminam elementele
    stergere_repo(nume_2);

}
void teste_repo()
{
    /*
     * Functie care apeleaza toate functiile de teste
     * input-Ø
     * output-Ø
     */
    teste_adaugare();//verificam adaugarea unui element
    //printf("%d",i);
    teste_stergere(); //verificam stergearea unui element
    //printf("%d",i);
    teste_stergere(); // verificam stergerea cand vectorul este gol

    teste_modificare(); // verificam modificarea

    teste_sortare(); // verificam  corectitudinea functiilor de sortare
}