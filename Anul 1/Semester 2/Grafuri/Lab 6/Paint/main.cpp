#include<vector>
#include<fstream>
#include<iostream>
using namespace std;
ifstream f("date.in");

int n,e,i,j;
vector<vector<int> > graph;
vector<int> color;
bool vis[100011];

void greedyColoring()
{
    color[0]  = 0;
    for (i=1;i<n;i++)
        color[i] = -1;

    bool unused[n];

    for (i=0;i<n;i++)
        unused[i]=0;


    for (i = 1; i < n; i++)
    {
        for (j=0;j<graph[i].size();j++)
            if (color[graph[i][j]] != -1)
                unused[color[graph[i][j]]] = true;
        int cr;
        for (cr=0;cr<n;cr++)
            if (unused[cr] == false)
                break;

        color[i] = cr;

        for (j=0;j<graph[i].size();j++)
            if (color[graph[i][j]] != -1)
                unused[color[graph[i][j]]] = false;
    }
}

int main()
{
    int x,y;
    f>>n>>e;
    graph.resize(n);
    color.resize(n);
    memset(vis,0,sizeof(vis));
    for(i=0;i<e;i++)
    {
        f>>x>>y;
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    greedyColoring();
    for(i=0;i<n;i++)
    {
        cout<<"Nodul "<<i+1<<" se coloreaza cu  "<<color[i]+1<<"\n";
    }
    return 0;
}