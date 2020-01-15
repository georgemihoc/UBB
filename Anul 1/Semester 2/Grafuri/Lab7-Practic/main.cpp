#include <iostream>
#include <fstream>
#include <queue>
#define inf 9999
using namespace std;
ifstream f("date.in");
/*
 Algoritm de determinarea Fluxului maxim
 Folosim algoritmul lui Ford-Fulkerson pt rezolvare
 Folosind retelele de flux se pot gasi solutii pt diverse probleme : curentul dintr-o retea electrica, traficul de masini.
 Algoritmul Ford-Fulkerson determina fluxul maxim care poate traversa de la nodul sursa dintr-un graf pana la nodul destinatie
 Un astfel de algoritm este de exemplu necesar pt determina cantitatea maxima de materiale/ produse care poate fi transportata
 de la sursa la destinatie, tinand cont de diverse impedimente ( un traseu pe care poate incapea doar o masina de tonaj mai mic fata
 de pana la nodul respectiv etc.).
 */

/*
 * Algoritm BFS de parcurgere a grafului
 */
bool bfs(int Graf2[100][100], int start, int end, int parent[])
{
    bool visited[100];
    for(int i=0;i<=100;i++)
        visited[i]=false;
    queue <int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while (!q.empty())
    {
        int i = q.front();
        q.pop();

        for (int j=0; j<100; j++)
        {
            if (!visited[j] && Graf2[i][j] > 0)
            {
                q.push(j);
                parent[j] = i;
                visited[j] = true;
            }
        }
    }
    return visited[end];
}
/*
 * Algoritm Ford Fulkerson pt determinarea fluxului maxim din graf
 * input: Graful, n (dimensiunea), start(nodul de pornire), end(nodul destinatie)
 * output:maxim(fluxul maxim determinat
 */
int fordFulkerson(int Graf[100][100], int n,int start, int end)
{
    int i, j,Graf2[100][100];

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            Graf2[i][j] = Graf[i][j];

    int parent[100];
    int maxim = 0;

    while (bfs(Graf2, start, end, parent))
    {
        int maxi = inf;
        for (j=end; j!=start; j=parent[j])
        {
            i = parent[j];
            maxi = min(maxi, Graf2[i][j]);
        }
        for (j=end; j != start; j=parent[j])
        {
            i = parent[j];
            Graf2[i][j] -= maxi;
            Graf2[j][i] += maxi;
        }
        maxim += maxi;
    }
    return maxim;
}

int main()
{
    int n,start,end;
    f>>n;
    f>>start>>end;
    int Graf[100][100],x,y,cost;
    //initializam matricea grafului cu 0
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            Graf[i][j]=0;
    //Citim si construim matricea de adiacenta (unde pe pozitia (i,j) se afla costul de la i la j
    while(!f.eof())
    {
        f>>x>>y>>cost;
        Graf[x][y]=cost;
    }

    cout <<"\nFluxul maxim: " << fordFulkerson(Graf,n, start, end)<<"\n";

    return 0;
} 

