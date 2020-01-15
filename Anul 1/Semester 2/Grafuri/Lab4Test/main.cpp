#include    <iostream>
#include    <fstream>
#include    <queue>
#include    <vector>
#define INF 99999999

using namespace std;

ifstream f("date.in");

const int MAX = 99999;

int N, M,ei,ef,ct,k=0;
int D[MAX];
bool in_queue[MAX];

vector < pair <int,int> > Graf[MAX];

struct compara
{
    bool operator()(int x, int y)
    {
        return D[x] > D[y];
    }
};

priority_queue<int, vector<int>, compara> Coada;

void citire()
{
    f >> N >> M;//citim dimensiunile grafului
    f >> ei >> ef >> ct; // citim extremitatile si costul pe care trebuie sa il gasim
    for(int i = 1; i <= M; i++)
    {
        int x, y, c;
        f >> x >> y >> c;
        Graf[x].push_back(make_pair(y,c));
    }
}
int print_route(vector<int> const &prev, int i)
{
    if (i < 0)
        return 0;
    print_route(prev, prev[i]);
    cout << i << " ";
}

void Dijkstra(int start)
{
    vector<int> prev(N, -1);

    for(int i = 1; i <= N; i++)
        D[i] = INF;

    D[start]=0;

    Coada.push(start);
    in_queue[start] = true;

    while(!Coada.empty())
    {
        int nod_curent = Coada.top();
        Coada.pop();

        in_queue[nod_curent] = false;
        for(int i = 0; i < Graf[nod_curent].size(); i++)
        {
            int vecin = Graf[nod_curent][i].first;
            int cost = Graf[nod_curent][i].second;
            if(D[nod_curent] + cost < D[vecin])
            {
                D[vecin] = D[nod_curent] + cost;
                prev[vecin] = nod_curent;
                if(!in_queue[vecin])
                {
                    Coada.push(vecin);
                    in_queue[vecin] = true;
                }
            }
            else if(D[nod_curent] + cost == D[vecin])
            {
                prev[vecin]=nod_curent;
            }
        }
    }
    //afisam drumul de la nodul sursa la nodul destinatie
    cout<<"DRUMUL:";
    print_route(prev, ef);
    //print_route(prev2, ef);
    cout<<"\nCOSTUL:";
    cout<<D[ef]; //costul intre extremitatile citite este egal cu ct
}

int main()
{
    citire(); //citim extremitatile si costul necesar
    Dijkstra(ei); //pornim din extremitatea citita
    return 0;
}