#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
/*
DATE.IN
 6
1 2
3 4
5 6
 */
int main() {
    int a,matrice[10][10];
    ///Citim lista adiacentei unui graf
    f>>a;
    for (int i=1;i<=a;i++)
        for(int j=1;j<=a;j++)
            matrice[i][j]=0;

    while(!f.eof())
    {
        int x,y;
        f>>x>>y;
        matrice[x][y]=1;

    }
    cout<<"Matricea de adiacenta: \n";
    for (int i=1;i<=a;i++)
    {
        for(int j=1;j<=a;j++)
            cout<<matrice[i][j]<<" ";
        cout<<"\n";
    }

    ///Nodurile izolate
    cout<<"Noduri izolate:\n";
    int ok =0;
    for (int i=1;i<=a;i++)
    {
        int s=0;
        for(int j=1;j<=a;j++)
        {
            if(matrice[i][j]==1 || matrice[j][i]==1)
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
    return 0;
}