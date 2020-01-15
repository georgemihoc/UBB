//
//  main.c
//  lab1
//
//  Created by George_ on 28/02/2019.
//  Copyright © 2019 George_. All rights reserved.
//

/*
 * ENUNTURI LAB 1:

 * 12. Determina valoarea x^n (x este un numar real dat, n este un numar natural
    dat), utilizand operatii de inmultire si de ridicare la patrat.

    17. Determina primele 10 numere naturale strict mai mari ca 2, care au
    proprietatea ca toate numerele naturale strict mai mici decat ele
    si care sunt prime cu ele sunt numere prime.

    16. Determina toate numerele naturale mai mici decat un numar natural
    nenul dat n si care sunt relativ prime cu n.

    1. Genereaza numere prime mai mici decat un numar natural dat.
 */
#include <stdio.h>

int cmmdc(int a, int b)
{
    /*
     * Functie care determina cel mai mare divizor comun a 2 numere date(cmmdc)
     * input- a,b
     * preconditii- a,b numere intregi
     * output- a(unde va fi valoarea cmmdc-ului
     * postconditii- a numar intreg
     */
    while(a!=b)
    {
        if(a > b)
            a -= b;
        else
            b-=a;
    }
    return a;
}
int prim(int x)
{
    /*
     * Functie care verifica daca un numar este prim
     * input- x
     * preconditii- x numar intreg
     * output- !nr(1/0)
     * postconditii-
     */
    int i = 2,nr = 0;
    if (x<2)
        return 0;
    while (i <= (x/2))
    {
        if (x%i == 0)
            nr ++;
        i++;
    }
    return !nr;
    //if (nr)
      //  return 0;
    //return 1;
}
int prime_intre_ele(int a, int b)
{
    /*
     * Functie care verifica daca 2 numere sunt prime intre ele(relativ prime)
     * input-a,b
     * preconditii- a,b numare naturale
     * output- 1/0
     * postconditii-
     */
    if (cmmdc(a,b) == 1)
        return 1;
    return 0;
}
void functie()
{
    /*
     * Functie care gaseste primele numere care au proprietatea ca orice numar
     * care e strict mai mic decat ele si cu care sunt prime intre ele e numar prim
     * input-
     * preconditii-
     * output- afisare
     * postconditii-
     */
    printf("Nu exista mai mult de 8 numere cu aceasta proprietate \n");
    int n = 2, nr = 8,i;
    while (nr!=0)
    {
        n++;
        int s=1;
        for (i= 2;i < n;i++)
        {
            if (prime_intre_ele(n,i) && prim(i)==0) {
                    s = 0;
                    break;
            }
        }
        if (s == 1) {
            printf("%d ", n);
            nr--;
        }
    }
    printf("\n");
}
float patrat(float x, int n)
{
    /*
     * Functie care returneaza numarul x ridicat la puterea n, x-real n-natural
     * input- x,n
     * preconditii- x real, n natural
     * output- p
     * postconditii- p real
     */
    float p = 1;
    for (int i = 1; i <= n; i++ )
    {
        p *= x;
    }
    return p;
}
void functie_16(int n)
{
    /*
     * Functie care gaseste toate numerele mai mici decat un n dat care sunt relativ prime cu n
     * input- n
     * preconditii- n numar intreg
     * output- afisare
     * postconditii-
     */
    int i;
    for (i=1;i<=n;i++)
    {
        if(prime_intre_ele(n,i))
            printf("%d ",i);
    }
    printf("\n");
}
void functie_1(int n)
{
    /*
     * Functie care gaseste toate numerele prime mai mici decat un n dat
     * input- n
     * preconditii- n numar intreg
     * output- afisare
     * postconditii-
     */
    for (int i=1;i<n;i++)
    {
        if(prim(i))
            printf("%d ",i);
    }
}

int main() {
    int problema;
    while (1) {
        printf("\nMENIU: \n0.EXIT \n12.Problema 12 \n17.Problema 17 \n16.Problema 16 \n1.Problema 1 \n");
        scanf("%d", &problema);
        if (problema == 0) {
            printf("EXIT");
            break;
        }
        else
            if (problema == 12)
            {
                int n;
                float x;
                printf("Introduceti valoarea lui x:");
                scanf("%f",&x);
                printf("Introduceti valoarea lui n:");
                scanf("%d",&n);
                printf("%f \n",patrat(x,n));
            }
            else
                if(problema == 17)
                {
                    functie();
                }
                else
                    if(problema == 16)
                    {
                        int n;
                        printf("Dati numarul n:");
                        scanf("%d",&n);
                        functie_16(n);
                    }
                    else if (problema == 1)
                    {
                        int n;
                        printf("Dati numarul n:");
                        scanf("%d",&n);
                        functie_1(n);
                    }
                    else
                        printf("Comanda introdusa nu exista");

    }

    return 0;
}