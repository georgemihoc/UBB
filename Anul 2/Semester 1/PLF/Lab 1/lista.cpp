#include "lista.h"
#include <iostream>

using namespace std;


PNod creare_rec(){
    TElem x;
    cout<<"x=";
    cin>>x;
    if (x==0)
        return NULL;
    else{
        PNod p=new Nod();
        p->e=x;
        p->urm=creare_rec();
        return p;
    }
}

Lista creare(){
    Lista l;
    l._prim=creare_rec();
    return l;
}

void tipar_rec(PNod p){
    if (p!=NULL){
        cout<<p->e<<" ";
        tipar_rec(p->urm);
    }
}

void tipar(Lista l){
    tipar_rec(l._prim);
}
int suma_rec(PNod p, int poz){
    if(p!=NULL){
        //suma+=p->e;
        if(poz %2==0)
            return (p->e)+suma_rec(p->urm,poz+1);
        else
            return suma_rec(p->urm,poz+1)-(p->e);
    } else return 0;
}
int suma(Lista l){
    cout<<suma_rec(l._prim,1);
}
bool parcurgere_rec_b(PNod p, int x){
    if (p!=NULL){
        if(p->e==x)
            return true;
        parcurgere_rec_b(p->urm,x);
    }
    return false;
}
void parcurgere_rec_a(PNod p, Lista b){
    if (p!=NULL){
        if(!parcurgere_rec_b(b._prim,p->e))
            cout<<p->e<<" ";
        parcurgere_rec_a(p->urm, b);
    }
}

void parcurgere(Lista a, Lista b){
    parcurgere_rec_a(a._prim, b);
}
void distruge_rec(PNod p){
    if (p!=NULL){
        distruge_rec(p->urm);
        delete p;
    }
}

void distruge(Lista l) {
    //se elibereaza memoria alocata nodurilor listei
    distruge_rec(l._prim);
}
