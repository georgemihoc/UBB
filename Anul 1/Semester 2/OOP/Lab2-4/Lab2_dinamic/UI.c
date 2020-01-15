//
// Created by George on 2019-03-13.
//

#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include "Service.h"
#include <string.h>
#include "Vector.h"

void citire_int(int *pnr)
{
    *pnr = -1;
    char cuvant[20];
    while (*pnr < 0)
    {
        scanf("%s", cuvant);
        if (atoi(cuvant) != 0)
        {
            *pnr = (int)(atof(cuvant));
        }
        else if(cuvant[0] == '0')
        {
            *pnr = 0;
        }
        else
        {
            printf("Introduceti un intreg!\n");
        }
    }
}

void citire_float(float *pnr)
{
    *pnr = -1;
    char cuvant[20];
    while (*pnr < 0)
    {
        scanf("%s", cuvant);
        if (atof(cuvant) != 0)
        {
            *pnr = (float)(atof(cuvant));
        }
        else if (cuvant[0] == '0')
        {
            *pnr = 0;
        }
        else
        {
            printf("Introduceti un numar real!\n");
        }
    }
}

void afisare_Materie(Materie* m)
{
    printf("%s ", get_nume(m));
    printf("%s ", get_producator(m));
    printf("%f\n", get_cantitate(m));
}

void afisare(VectorDinamic* v)
{
    int i, ok = 0;
    printf("\nMATERII\n");
    for (i = 0; i < v->lg; i++)
    {
        afisare_Materie(&v->elems[i]);
        ok = 1;
    }
    //printf("\n");
    if (ok == 0)
        printf("EMPTY LIST\n");
}


void adaugare(VectorDinamic * v)
{
    char nume[20], producator[20];
    float cantitate = -1;
    printf("Nume: ");
    scanf("%s", nume);
    printf("Producator: ");
    scanf("%s", producator);
    printf("Cantitatea: ");
    citire_float(&cantitate);

    if (adauga(v, nume, producator, cantitate) == 1 )
    {
        printf("Adaugarea a fost efectuata cu succes!\n");
    }
    else if (adauga(v,nume, producator,cantitate) == -2)
    {
        printf("Materie prima invalida!\n");
    }
    else
    {
        printf("Materie prima modificata\n");
    }
}

void modifica(VectorDinamic* v)
{
    char nume[20], producator[20];
    float cantitate = 0;
    printf("Nume: ");
    scanf("%s", nume);
    printf("Introduceti numele : ");
    scanf("%s", producator);
    printf("Cantitate: ");
    citire_float(&cantitate);

    if (modificare(v, nume, producator, cantitate) == 1)
    {
        printf("Modificare realizata cu succes!\n");
    }
    else if (modificare(v, nume, producator, cantitate) == -2)
    {
        printf("Materie prima invalida\n");
    }
    else
    {
        printf("Materie prima inexistenta\n");
    }
}

void stergere(VectorDinamic*v)
{
    char cod[20];

    printf("Introduceti numele: ");
    scanf("%s", cod);
    if (sterge(v, cod) != -1)
    {
        printf("Stergerea a fost efectuata cu succes!\n");
    }
    else
    {
        printf("Materie prima invalida\n");
    }
}

void vizualizare_dupa_cantitate(VectorDinamic *v)
{
    VectorDinamic *c;
    float cantitate = -1;
    printf("Introduceti cantitatea dorita: ");
    citire_float(&cantitate);
    c = vizualizare_cantitate(v, cantitate);
    afisare(c);
    distruge(c);
}

void vizualizare_ordonata(VectorDinamic *v)
{
    VectorDinamic* ordonate = copy(v);
    int ordine;
    printf("1.Crescator\n2.Descrescator\n");
    printf("Introduceti ordine: ");
    citire_int(&ordine);

    ordonare(ordonate, comparare, ordine);
    //ordonare(ordonate, ordine);

    afisare(ordonate);

    distruge(ordonate);
}

void vizualizare_ordonata_nume(VectorDinamic *v)
{
    VectorDinamic* ordonate = copy(v);
    int ordine;
    printf("1.Crescator\n2.Descrescator\n");
    printf("Introduceti ordine: ");
    citire_int(&ordine);

    ordonare(ordonate, comparareNume, ordine);
    //ordonare(ordonate, ordine);

    afisare(ordonate);

    distruge(ordonate);
}

void vizualizare_litera_ui(VectorDinamic *v)
{

    char litera[2];
    printf("Introduceti litera: ");
    scanf("%s", litera);

    VectorDinamic *p;
    char lit = litera[0];
    p = vizualizare_litera(v, lit);
    afisare(p);
    distruge(p);
}


int afisare_meniu(VectorDinamic *v)
{
    //printf("TUN");
    int comanda = -1;
    while (comanda != 0)
    {
        printf("\nMENIU\n");
        printf("0.Exit\n");
        printf("1.Adaugare materie prima\n");
        printf("2.Modificare materie prima\n");
        printf("3.Stergere materie prima\n");
        printf("4.Vizualizare materii care incep cu o litera data\n");
        printf("5.Vizualizare materii prime cu o cantitate mai mica decat una citita\n");
        printf("6.Vizualizare ordonata dupa nume\n");
        printf("7.Vizualizare ordonat dupa cantitate\n");
        printf("8.Afisare\n");
        citire_int(&comanda);
        switch (comanda)
        {
            case 1:
                adaugare(v);
                break;
            case 2:
                modifica(v);
                break;
            case 3:
                stergere(v);
                break;
            case 4:
                vizualizare_litera_ui(v);
                //vizualizare_dupa_cantitate(v);
                break;
            case 5:
                vizualizare_dupa_cantitate(v);
                //vizualizare_ordonata(v);
                break;
            case 6:
                vizualizare_ordonata_nume(v);
                break;
            case 7:
                vizualizare_ordonata(v);
                break;
            case 8:
                afisare(v);
                break;
            case 0:
                printf("EXIT!\n");
                return 1;
            default:
                printf("Comanda invalida!\n");
                break;
        }

        comanda = -1;
    }
    return 0;
}
