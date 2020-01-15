#include "lista.h"
#include <iostream>
using namespace std;
int main()
{
    Lista l;
    l=creare();
    tipar(l);
    cout<<"\n";
    cout<<"Suma:";
    suma(l);
    distruge(l);
    cout<<"\n";

    Lista a;
    Lista b;
    cout<<"Lista a:\n";
    a=creare();
    cout<<"Lista b:\n";
    b=creare();

    parcurgere(a,b);

    distruge(a);
    distruge(b);
    return 0;
}