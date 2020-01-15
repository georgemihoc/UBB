#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream f("date.txt");
    int a,matrice[10][10];
    ///Citim matricea de adiacenta a unui graf
    f>>a;
    for (int i=1;i<=a;i++)
        for(int j=1;j<=a;j++)
            matrice[i][j]=0;

    for (int i=1;i<=a;i++)
    {
        for(int j=1;j<=a;j++)
            f>>matrice[i][j];
    }
    cout<<"Matricea de adiacenta: \n";
    for (int i=1;i<=a;i++)
    {
        for(int j=1;j<=a;j++)
            cout<<matrice[i][j]<<" ";
        cout<<"\n";
    }

    ///Nodurile izolate
    cout<<"Noduri izolate:";
    int ok =0;
    for (int i=1;i<=a;i++)
    {
        int s=0;
        for(int j=1;j<=a;j++)
        {
            if(matrice[i][j]==1)
                s+=1;
        }
        matrice[i][a+1] = s;// marcam gradele fiecarui nod pe ultima coloana din matricea de adiacenta
        if (s==0) {
            ok = 1;
            cout << "nodul " << i << "\n";
        }
    }
    if (ok == 0)
        cout<<"Nu exista noduri izolate\n";

    ///REGULAR
    int grad = matrice[1][a+1], ok1 =1;
    for (int i=1;i<=a;i++)
    {
        if (matrice[i][a+1]!=grad)
            ok1 = 0;
    }
    if(ok1)
        cout<<"Graful  este regular\n";
    else
        cout<<"Graful nu este regular\n";

    ///Matricea Drumurilor
    cout<<"Matricea distantelor(drumurilor):\n";
    // D este matricea de adiacență
    int D[10][10];
    for (int i=1;i<=a;i++)
        for(int j=1;j<=a;j++)
            if (matrice[i][j]==1)
                D[i][j] = 1;
            else
                D[i][j] = 9999;

    /*for(int k = 1 ; k <= a ; k++)
        for(int i = 1 ; i <= a ; i++)
            for(int j = 1 ; j <= a ; j++)
                if(D[i][j] != 1)
                    D[i][j] = D[i][k] * D[k][j];*/

    ///Algoritm Roy Floyd pentru a determina matricea drumurilor
    for(int k=1;k<=a;k++)
        for(int i=1;i<=a;i++)
            for(int j=1;j<=a;j++)
                if(D[i][j]>D[i][k]+D[k][j])
                {
                    D[i][j]=D[i][k]+D[k][j];
                }
    //Aranjam putin matricea drumurilor obtinuta
    for (int i=1;i<=a;i++) {
        for (int j = 1; j <= a; j++) {
            if (i == j)
                D[i][j] = 0;
            if (D[i][j] == 9999)
                D[i][j] = -1;
        }
    }
    //Afisarea matricei drumurilor
    for (int i=1;i<=a;i++)
    {
        for(int j=1;j<=a;j++)
            cout<<D[i][j]<<" ";
        cout<<"\n";
    }
    ///Verificam daca un graf e conex sau nu folosind matricea drumurilor
    int ok2=1;
    for(int i=1;i<=a;i++) {
        for (int j = 1; j <= a; j++) {
            if (D[i][j] == -1)
                ok2 = 0;
        }
    }
    if (ok2==1)
        cout<<"Graful este conex";
    else
        cout<<"Graful nu e conex";
    return 0;
}