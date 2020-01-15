//
// Created by George on 2019-03-27.
//
#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "Lista.h"
#include "service.h"
#include <assert.h>
#include "Console.h"
/*
*Valideaza o posibila oferta
*int: tip,dest - char*, int zi,luna,an,p
*ies: 1 - daca oferta este valida, 0 - daca oferta nu este valida
*/
int validOferta(char* tip, char* dest, int zi, int luna, int an, int p)
{
    int ok = 1;
    if ((strcmp(tip, "Mountain") != 0) && (strcmp(tip, "City Break") != 0) && (strcmp(tip, "Beach") != 0))
    {
        ok = 0;
        //printf("Tipul poate sa fie:munte, citybreak ,mare\n");
    }
    if (strcmp(dest, " ") == 0)
    {
        ok = 0;
        printf("Invalid Destination\n");
    }
    if (zi > 31)
    {
        ok = 0;
        printf("Invalid day\n");
    }
    if (luna > 31)
    {
        ok = 0;
        printf("Invalid month\n");
    }
    if (an < 2000 && an>3000)
    {
        ok = 0;
        printf("Invalid year\n");
    }
    if (p < 0)
    {
        ok = 0;
        printf("Invalid price\n");
    }
    return ok;
}

void test_validare() {
    assert(validOferta("Beach", "dest", 12, 3, 2021, 444) == 1);
    assert(validOferta("dsds", "fdfd", 22, 2, 2012, 4343) == 0);
    assert(validOferta("Mountain", "roma", 12, 13, 2012, 2222) == 1);
}

/*
* Se citesc componentele unei oferte si se apeleaza validarea si adaugarea
* int: agent
* post: daca oferta este valida se adauga, altfel se afis mesaj
*/
void adaugaOferta(Agentie* agent) {

    int ok = 1;
    while (ok) {
        printf("Type:");
        char tip[30];
        tip[0] = '\0';
        scanf("%s", tip);
        printf("Destination:");
        char dest[30];
        dest[0] = '\0';
        scanf("%s", dest);
        printf("Day:");
        int zi;
        scanf("%d", &zi);
        printf("Month:");
        int luna;
        scanf("%d", &luna);
        printf("Year:");
        int an;
        scanf("%d", &an);

        int p;
        printf("Price:");
        scanf("%d", &p);

        if (validOferta(tip, dest, zi, luna, an, p))
        {
            ok = 0;
            adaugOferta(agent, tip, dest, zi, luna, an, p);
            printf("Package added\n");
        }
        else
            printf("Invalid package\n");
    }
}

/*
*Verifica validitatea pozitiei si apeleaza stergerea
*int:agent , poz
*post:daca pozitia este valida se sterge elem, altfel se afis mesaj
*/

void stergereOferta(Agentie* agent, int poz)
{
    Lista *to_undo = copieLista(agent->Oferte, copyOferta);

    if (poz < 0 || poz >= lung(agent->Oferte))
        printf("Pozitie invalida\n");
    else
    {
        stergeOferta(agent->Oferte, poz);
        printf("Package deleted!\n");
        adaug(agent->undolist, to_undo);
    }
}

/*
*Verifica validitatea pozitiei si apeleaza modificarea
*int:agent , poz
*post:daca pozitia este valida se modifica elem, altfel se afis mesaj
*/
void modificareOferta(Agentie* agent, int poz)
{
    Lista *to_undo = copieLista(agent->Oferte, copyOferta);
    if (poz < 0 || poz >= lung(agent->Oferte))
        printf("Pozitie invalida\n");
    else
    {
        stergeOferta(agent->Oferte, poz);
        adaugaOferta(agent);
        adaug(agent->undolist, to_undo);
    }
}

/*
*Afiseaza elem din lista
*int: l - Lista
*post:se afis. elem din lista
*/
void printOferte(Lista* l) {
    printf("Packages:\n");
    if(lung(l)== 0)
        printf("No packages available\n");
    else {
        for (int i = 0; i < lung(l); i++) {
            Oferta *o = elem(l, i);
            printf("Type: %s |Dest: %s |Day: %d |Month: %d |Year: %d |Price: %d\n", o->tip, o->dest, o->data.zi,
                   o->data.luna, o->data.an, o->pret);
        }
    }
}
/*
*Afiseaza ofertele din agentie
*int:agent - Agentie
*post:se afis ofertele din agentie si dealocarea memoriei
*/
void afisOferte(Agentie* agent) {
    Lista *Oferte = FiltOferteTip(agent, NULL);
    printOferte(Oferte);
    destroyList(Oferte);
}

/*
*Sortare oferte dupa pret, chemare afisare si dealocarea memoriei
*int:agent - Agentie
*post:se afiseaza lista sortata dupa pret
*/
void sortarePret(Agentie* agent) {
    Lista *Oferte = sortPret(agent);
    printOferte(Oferte);
    destroyList(Oferte);
}

/*
*Sortare oferte dupa dest, chemare afisare si dealocarea memoriei
*int:agent - Agentie
*post:se afiseaza lista sortata dupa dest
*/
void sortareDest(Agentie* agent) {
    Lista* Oferte = sortDest(agent);
    printOferte(Oferte);
    destroyList(Oferte);
}

/*
*Filtrare agentie dupa un tip citit de la tastatura
*int:agent - Agentie
*post:se afis elem din lista care au tipul egal cu cel dat
*/
void filtrareTip(Agentie* agent) {
    printf("Type:\n");
    char tip[30];
    scanf("%s", tip);
    Lista *rez = FiltOferteTip(agent, tip);
    printOferte(rez);
    destroyList(rez);
}

/*
*Filtrare agentie dupa o dest citit de la tastatura
*int:agent - Agentie
*post:se afis elem din lista care au dest egala cu cea data
*/
void filtrareDest(Agentie* agent) {
    printf("Destination\n");
    char dest[30];
    scanf("%s", dest);
    Lista *rez = FiltOferteDest(agent, dest);
    printOferte(rez);
    destroyList(rez);
}

/*
*Filtrare agentie dupa pret citit de la tastatura
*int:agent - Agentie
*post:se afis elem din lista care au pretul mai mic decat cel dat
*/
void filtrarePret(Agentie* agent) {
    printf("Price:\n");
    int pret;
    scanf("%d", &pret);
    Lista *rez = FiltOfertePret(agent, pret);
    printOferte(rez);
    destroyList(rez);
}


void filtrareData(Agentie* agent) {
    printf("Year:\n");
    int year;
    scanf("%d", &year);
    Lista *rez = FiltOferteYear(agent, year);
    printOferte(rez);
    destroyList(rez);
}

void menu()
{
    printf("------------------------------------\n");
    printf("-          TravelAgency            -\n");
    printf("------------------------------------\n");
    printf("- 1. Add a travel package          -\n");
    printf("- 2. Update a travel package       -\n");
    printf("- 3. Remove a travel package       -\n");
    printf("- 4. Sort (By price/By destination)-\n");
    printf("- 5. Filter(Type/Dest/Price/year)  -\n");
    printf("- 6. Show all offers               -\n");
    printf("- 7. UNDO                          -\n");
    printf("- 8. REDO                          -\n");
    printf("- 0. EXIT                          -\n");
    printf("------------------------------------\n");
}


void test()
{
    testAdaug();
    testSort();
    testCreeazaElimin();
    testCreeare();
    testIterator();
    testCopie();
    testLung();
    test_undo();
    test_validare();
}

void run() {
    int ruleaza = 1,poz,cmd2,cmd3;
    Agentie agent = creeazaAgent();
    adaugOferta(&agent,"Mountain","asd",12,7,2010,45);
    adaugOferta(&agent,"Beach","asd",12,7,2015,45);
    /*
    adaugOferta(&agent,"City Break","asd",12,7,2000,50);
    adaugOferta(&agent,"Beach","asd",12,7,2014,45);
    adaugOferta(&agent,"Mountain","asd",12,7,2010,60);
    adaugOferta(&agent,"Mountain","asd",12,7,2013,45);
    adaugOferta(&agent,"City Break","asd",12,7,2017,20);
    adaugOferta(&agent,"Beach","asd",12,7,2010,100);
    adaugOferta(&agent,"City Break","asd",12,7,2010,45);
    adaugOferta(&agent,"Mountain","asd",12,7,2010,45);
    adaugOferta(&agent,"Beach","asd",12,7,2010,45);
    adaugOferta(&agent,"Mountain","asd",12,7,2010,45);*/
    while (ruleaza) {
        menu();
        printf("Please choose a command:\n");
        int cmd = 0;
        scanf("%d", &cmd);
        switch (cmd) {
            case 1:
            {
                adaugaOferta(&agent);
                break;
            }
            case 3:
            {
                printf("Dati pozitie:\n");
                scanf("%d", &poz);
                stergereOferta(&agent,poz);
                break;
            }
            case 2:
            {
                printf("Dati pozitie:\n");
                scanf("%d", &poz);
                modificareOferta(&agent, poz);
                break;
            }
            case 4:
            {
                printf("1 - Ordonare cresc dupa pret\n");
                printf("2 - Ordonare descresc dupa destinatie\n");
                scanf("%d", &cmd2);
                if (cmd2 == 1)
                    sortarePret(&agent);
                else if (cmd2 == 2)
                    sortareDest(&agent);
                else
                    printf("Comanda invalida\n");
                break;
            }
            case 5:
            {
                printf("1 - Filter by type\n");
                printf("2 - Filter by destination\n");
                printf("3 - Filter by price\n");
                printf("4 - Filter by year");
                scanf("%d", &cmd3);
                if (cmd3 == 1)
                    filtrareTip(&agent);
                else if (cmd3 == 2)
                    filtrareDest(&agent);
                else if (cmd3 == 3)
                    filtrarePret(&agent);
                else if (cmd3 == 4) {
                    filtrareData(&agent);
                }
                else
                    printf("Comanda invalida\n");
                break;
            }
            case 6:
            {
                afisOferte(&agent);
                break;
            }
            case 7:
            {
                if (undo(&agent))
                    printf("No more undo!\n");
                break;
            }
            case 8:
            {
                if(redo(&agent))
                    printf("No more redo!\n");
                break;
            }
            case 0:
                ruleaza = 0;
                distrugeAgent(&agent);
                break;
            default:
                printf("Comanda invalida!\n");
        }
    }
}
