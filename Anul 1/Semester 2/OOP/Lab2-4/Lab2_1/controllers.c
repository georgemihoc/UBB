//
// Created by George on 2019-03-08.
//

#include "controllers.h"
#include "Validator.h"
#include <string.h>
#include "Materie.h"
#include "repository.h"
#include <stdio.h>
int adaugare(char nume[20],char producator[20], int cantitate)
{
    /*
     * Functie care apeleaza functia de adaugare din repository pentru a adauga un element nou
     * in lista de elemente si returneaza tipul de eroare(daca exista).
     * input- nume, producator, cantitate
     * preconditii- nume,producator-sir de caractere, cantitate-nr intreg
     * output- erori
     * postconditii- erori-nr intreg
     */
    int erori = valideaza_materie(nume,producator,cantitate);
    if (erori)
        return erori;
    else {
        adaugare_repo(nume, producator, cantitate);
        return 0;
    }
}
int modificare_controller(char nume_1[20],char producator_nou[20],int cantitate_nou)
{
    /*
     * Functie care apeleaza functia de modificare din repository pentru a modifica un element
     * din lista de elemente si returneaza tipul de eroare(daca exista)
     * input- nume_1, producator_nou, cantitate_nou
     * preconditii- nume_1,producator_nou-sir de caractere, cantitate_nou-nr intreg
     * output- erori
     * postconditii- erori sau ok-numere  intreg
     */
    int erori = valideaza_materie(nume_1,producator_nou,cantitate_nou);
    if(erori)
        return erori;
    int ok = modificare_repo(nume_1,producator_nou,cantitate_nou);
    return ok;
}
int stergere_controller(char nume_1[20])
{
    /*
     * Functie care apeleaza functia de stergere din repository pentru a  sterge un element
     * din lista de elemente si returneaza tipul de eroare(daca exista)
     * input- nume_1-numele elementului care trebuie sters
     * preconditii- nume_1-sir de caractere
     * output- ok- marcheaza daca a fost gasit si sters elementul
     * postconditii- ok-nr intreg
     */
    int ok = stergere_repo(nume_1);
    return ok;
}
int vizualizare_litera(Materie *a[100], char litera)
{
    /*
     * Functie care permite vizualizarea elementelor care incep cu o anumita litera
     * input- a,litera
     * preconditii- a-un vector de materii nou, unde stocam elementele care satisfac conditia, litera-un caracter(litera)
     * output- k- semnificand numarul de elemente din vectorul nou construit(nr elemente care satisfac conditia)
     * postconditii- k-nr natural
     */
    Materie *b[100];
    int i = getAll(b),k = 0;
    for (int j = 1;j<=i;j++)
    {
        //printf("%c",litera);
        if (b[j]->nume[0] == litera) {
            k++;
            a[k] = b[j];
        }
    }
    return k;
}
int vizualizare_numar(Materie *a[100],int nr)
{
    /*
     * Functie care permite vizualizarea elementelor care au cantitatea mai mica decat un numar dat
     * input- a,nr -> a vector unde vom stoca elementele gasite , nr numarul din cerinta
     * preconditii- a-un vector de materii nou, unde stocam elementele care satisfac conditia, nr-un numar natural
     * output- k- semnificand numarul de elemente din vectorul nou construit(nr elemente care satisfac conditia)
     * postconditii- k-nr natural
     */
    Materie *b[100];
    int i = getAll(b),k = 0;
    for (int j = 1;j<=i;j++)
    {
        //printf("%c",litera);
        if (b[j]->cantitate < nr) {
            k++;
            a[k] = b[j];
        }
    }
    return k;
}
void sortare_nume_controller(char ordine[20])
{
    /*
     * Functie care apeleaza functia din repository care sorteaza elementele
     * dupa numele lor(in mod crescator sau descrescator)
     * input- ordine
     * preconditii- ordine-> caracter care semnifica modul de sortare (C-crescator, D-descrescator)
     * output- Functie void
     * postconditii- Ø
     */
    sortare_nume_repo(ordine);
}
int sortare_cantitate_controller(char ordine[20])
{
    /*
     * Functie care apeleaza functia din repository care sorteaza elementele
     * dupa cantitatea lor(in mod crescator sau descrescator)
     * input- ordine
     * preconditii- ordine-> caracter care semnifica modul de sortare (C-crescator, D-descrescator)
     * output- Functie Void
     * postconditii- Ø
     */
    sortare_cantitate_repo(ordine);
}
int getAll(Materie *a[100])
{
    /*
     * Functie de getAll() care apeleaza functia getAll din repository care aduna
     * toate elementele din vectorul de elemente
     * input- a
     * preconditii-a-> vectorul de materii nou unde stocam elementele gasite
     * output- i-> numarul de elemente din vector
     * postconditii- i->numar natural pozitiv
     */
    int i = getAll_repo(a);
    return i;
}