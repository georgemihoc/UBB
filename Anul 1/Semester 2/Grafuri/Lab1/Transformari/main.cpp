#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream f;
    f.open("date.txt");
    int nr,a,b,muchii=0;
    int matrice[10][10];
    f>>nr;
    while(!f.eof()) {
        f >> a >> b;
        matrice[a][b] = 1;
        matrice[b][a] = 1;
        muchii++;
    }
    cout<<"Matricea adiacenta:\n";
    for(int i=1;i<=nr;i++){
        for(int j=1;j<=nr;j++)
            cout<<matrice[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Matricea incidenta:\n";
    int incidenta[10][10],m=0;
    for(int i=1;i<=nr;i++) //initializare cu 0
        for(int j=1;j<=nr;j++)
            incidenta[i][j]=0;

    for(int i=1;i<=nr;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(matrice[i][j]==1)
            {
                m++;
                incidenta[i][m]=1;
                incidenta[j][m]=1;

            }

        }
    }
    for(int i=1;i<=nr;i++)
    {
        for(int j=1;j<=nr;j++)
            cout<<incidenta[i][j]<<" ";
        cout<<endl;
    }
    for(int i=1;i<=nr;i++) //initializare cu 0
        for(int j=1;j<=nr;j++)
            matrice[i][j]=0;

    cout<<"Matricea adiacenta \n";
    for (int j=1;j<=nr;j++)
    {
        int a=0,b=0;
        for(int i=1;i<=nr;i++)
        {
            if (a==0 && incidenta[i][j]==1)
                a=i;
            else if(incidenta[i][j]==1)
                b=i;
        }
        matrice[a][b]=1;
        matrice[b][a]=1;
    }
    for(int i=1;i<=nr;i++){
        for(int j=1;j<=nr;j++)
            cout<<matrice[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Lista\n";
    cout<<nr<<"\n";
    for(int i=1;i<=nr;i++){
        for(int j=1;j<i;j++)
        {
            if(matrice[i][j]==1)
                cout<<i<<" "<<j<<"\n";
        }
    }
    return 0;
}