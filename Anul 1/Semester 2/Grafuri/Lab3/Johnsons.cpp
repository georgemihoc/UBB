//
// Created by George on 2019-04-02.
//

#include<iostream>
#include <fstream>


using namespace std;

ifstream f ("date.in");
ofstream g ("date.out");

int min(int a, int b);
int cost[10][10], a[10][10], i, j, k, c;

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    int n, m;
    f >> n; ///nr varfuri
    f >> m; ///nr muchii
    for (k = 1; k <= m; k++)
    {
        f >> i >> j >> c; ///muchia si costul
        a[i][j] = cost[i][j] = c;
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            if (a[i][j] == 0 && i != j)
                a[i][j] = 99999;
        }

    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);

    ///AFISARE
    /*
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (a[i][j] != 99999)
                cout << a[i][j] << " ";
        }
        cout << "\n";
    }*/
    for (j = 2; j <= n; j++)
    {
        if (a[1][j] != 99999)
            cout << a[1][j] << " ";
    }
    return 0;
}