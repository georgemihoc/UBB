//
// Created by George on 2019-03-08.
//

#include "UI.h"
#include <stdio.h>
#include <assert.h>
#include "repository.h"
#include "Teste.h"
#include <stdlib.h>
#include <string.h>
/*
 * 6. Cofetarie
Creati o aplicatie care permite gestiunea stocului de materii prime folosite intr-o cofetarie.
Fiecare materie prima din stoc are un nume unic, un producator si cantitate.
Aplicatia permite:
a) adaugare de materie prima (daca exista deza in stoc se actualizeaza cantitatea)
b) modificare materie prima
c) stergere  materie prima
d) Vizualizare materii prime care satisfac un criteriu (nume incepe cu o litera data, cantitatea disponibila e mai mica decat un numar dat)
e) Vizualizare materii prime din stoc ordonat dupa nume sau cantitate disponibila (crescator/descrescator)
*/
void teste()
{
    //teste Repo
    teste_repo();

    //teste modul de teste
    teste_controller();
    teste_validator();
    teste_vizualizare();
}
/*
int main() {
    //teste();
    //run();
    //printf("boss");
    //Materie *a;
    Materie *a = (Materie *)malloc(sizeof(Materie));
    strcpy(a[0].nume,"george");
    strcpy(a[2].nume,"boss");

    //elems->cantitate=5;
    printf("%s ",a[0].nume);
    printf("%s",a[2].nume);

}
*/

int main()
{
    teste();
    run();
}