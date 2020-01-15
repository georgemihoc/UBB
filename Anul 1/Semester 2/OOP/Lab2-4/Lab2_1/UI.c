//
// Created by George on 2019-03-08.
//

#include "UI.h"
#include "Materie.h"
#include "controllers.h"
//#include "repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int citire()
{
    char nume[20],producator[20],c[20];
    int cantitate;
    printf("Nume:");
    scanf("%s",&nume);

    printf("Producator:");
    scanf("%s",&producator);

    printf("Cantitate:");
    scanf("%s",&c);
    cantitate= atoi(c);
    //printf("%f",cantitate);

    int erori = adaugare(nume,producator,cantitate);
    if (erori==1)
        printf("Nume invald\n");
    else if(erori ==2)
        printf("Producator invalid\n");
    else if(erori == 3)
        printf("Cantitate invalida\n");
    else
        printf("Materie prima adaugata cu succes\n");
    return 0;
}
void afisare()
{
    Materie *a[100];
    int i =getAll(a);
    if (i == 0)
        printf("EMPTY LIST\n");
    else{
        printf("LISTA MATERII PRIME:\n");
        for(int j= 1;j<=i;j++)
            printf("%s,%s,%d\n", a[j]->nume, a[j]->producator, a[j]->cantitate);
    }
}
void modificare()
{
    char nume_1[20],producator_nou[20];
    int cantitate_nou;
    printf("Nume:");
    scanf("%s",&nume_1);

    printf("Producator nou:");
    scanf("%s",&producator_nou);

    printf("Cantitate nou:");
    scanf("%d",&cantitate_nou);

    int ok = modificare_controller(nume_1,producator_nou,cantitate_nou);
    if (ok==1)
        printf("Nume invald\n");
    else if(ok ==2)
        printf("Producator invalid\n");
    else if(ok == 3)
        printf("Cantitate invalida\n");
    else if (ok == -1)
        printf("Materie prima inexistenta \n");
    else
        printf("Materie prima actualizata cu succes \n");
}
void stergere()
{
    char nume_1[20];
    printf("Nume:");
    scanf("%s",&nume_1);
    int ok = stergere_controller(nume_1);
    if (ok == -1)
        printf("Materie prima inexistenta \n");
    else
        printf("Materia prima stearsa \n");
}
void vizualizare()
{
    char comanda[20];
    Materie *a[100];
    printf("Nume incepe cu o litera data (L) / Cantitatea disponibila e mai mica decat un nr dat (N):");
    scanf("%s",&comanda);
    //printf("%s",comanda);
    if(strcmp(comanda,"l") == 0) {
        char litera;
        printf("Introduceti litera:");
        scanf("%s",&litera);
        int k = vizualizare_litera(a,litera);
        //printf("%d",k);
        if (k==0)
            printf("Nu exista nicio materie cu aceasta litera\n");
        else
            for (int i =1;i<=k;i++)
                printf("%s,%s,%d\n", a[i]->nume, a[i]->producator, a[i]->cantitate);
    }
    else if(strcmp(comanda,"n")==0) {
        int nr;
        printf("Introduceti numarul:");
        scanf("%d",&nr);
        int k = vizualizare_numar(a,nr);
        if (k==0)
            printf("Nu exista nicio materie cu astfel de cantitate\n");
        else
            for (int i =1;i<=k;i++)
                printf("%s,%s,%d\n", a[i]->nume, a[i]->producator, a[i]->cantitate);
    }
    else
        printf("Input invalid\n");
}
void sortare()
{
    char comanda[20];
    printf("Ordonare dupa nume(N)/cantitate disponibila(C):");
    scanf("%s",&comanda);
    if (strcmp(comanda, "n")==0 || strcmp(comanda, "N")==0)
    {
        char ordine[20];
        printf("Introduceti ordinea, crescator (C) /descrescator (D):");
        scanf("%s",&ordine);
        sortare_nume_controller(ordine);
    }
    else if (strcmp(comanda, "c")==0 || strcmp(comanda, "C")==0)
    {
        char ordine[20];
        printf("Introduceti ordinea, crescator (C) /descrescator (D):");
        scanf("%s",&ordine);
        sortare_cantitate_controller(ordine);
    }
    else
        printf("Input invalid\n");

}
int run()
{
    while(1){
        printf("\nMENIU\n");
        printf("0.EXIT\n");
        printf("1.Adaugati materie prima noua\n");
        printf("2.Modificati materia prima\n");
        printf("3.Stergeti materia prima\n");
        printf("4.Vizualizati materiile prime care incep cu o litera data/cantitatea < un nr dat\n");
        printf("5.Vizualizare materii prime ordonate dupa nume sau cantitate disponibila (crescator/descrescator)\n");
        printf("6.Printati lista de materii prime\n");
        char comanda[20];
        scanf("%s",&comanda);

        if(strcmp(comanda,"0")==0)
        {
            printf("EXIT");
            break;
        }
        else if(strcmp(comanda,"1")==0)
            citire();
        else if(strcmp(comanda,"2")==0)
            modificare();
        else if(strcmp(comanda,"3")==0)
            stergere();
        else if(strcmp(comanda,"4")==0)
            vizualizare();
        else if(strcmp(comanda,"5")==0)
            sortare();
        else if(strcmp(comanda,"6")==0)
            afisare();
        else
            printf("Comanda invalida\n");
    }
    return 0;
}