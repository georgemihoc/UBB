#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define INF 99999999
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int n,m;
vector< pair<int, int> >graf[99999];
vector <int> v;
queue <int> coada;

int a[99999];
int viz[99999];
int is_queue[99999];
bool bellmanford(int s)
{
    for(int i=1;i<=n;i++)
    {
        viz[i]=0;
        is_queue[i]=0;
        a[i]=INF;
    }
    a[s] = 0;
    coada.push(s);
    is_queue[s] = 1;

    while(!coada.empty())
    {
        int nod_curent = coada.front();
        viz[nod_curent]++;
        if(viz[nod_curent] >= n)
            return false;
        coada.pop();
        is_queue[nod_curent] = 0;

        for(int  i=0;i<graf[nod_curent].size();i++)
        {
            int vecin = graf[nod_curent][i].first;
            int cost = graf[nod_curent][i].second;
            if(a[nod_curent]+cost < a[vecin])
            {
                a[vecin] = a[nod_curent]+cost;
                if(!is_queue[vecin])
                    coada.push(vecin);
            }
        }
    }
    return true;
}
int main()
{
    in>>n>>m;///nr de noduri si muchii
    for(int i=1;i<=m;i++)
    {
        int x,y,c;
        in>>x>>y>>c;///muchia si costul sau
        graf[x].push_back(make_pair(y,c));
    }
    if(bellmanford(1))
    {
        for(int i=2;i<=n;i++)
            cout<<a[i]<<" ";
    }
    else
        cout<<"Ciclu negativ!";
    return 0;
}