#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.txt");
int n,m,a[10][10];
void citire() {
    int x,y;
    f>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            f >> a[i][j];
            //a[x][y] = 1;
        }
    }
}
void tranzitiva() {
    int i, j, k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i!=j)
                    if(a[i][j]==0)
                        a[i][j]=a[i][k]*a[k][j];
}
void afisare()
{
    for(int i=1;i<=n;i++)
    {
        cout<<endl;
        cout<<i<<"->";
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" "; }
}
int main() {
    citire();
    tranzitiva();
    afisare();
    int b[10][10];
}