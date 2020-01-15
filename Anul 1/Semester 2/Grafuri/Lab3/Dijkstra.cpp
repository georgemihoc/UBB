#include    <iostream>
#include    <fstream>
#include    <queue>
#include    <vector>
#define INF 99999999

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

const int NMax = 99999;

int N, M;
int D[NMax];
bool in_queue[NMax];

vector < pair <int,int> > Graf[NMax];

struct compara
{
    bool operator()(int x, int y)
    {
        return D[x] > D[y];
    }
};

priority_queue<int, vector<int>, compara> Coada;

void Citeste()
{
    fin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
        int x, y, c;
        fin >> x >> y >> c;
        Graf[x].push_back(make_pair(y,c));
    }
}

void Dijkstra(int start)
{
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
        for(size_t i = 0; i < Graf[nod_curent].size(); i++)
        {
            int vecin = Graf[nod_curent][i].first;
            int cost = Graf[nod_curent][i].second;
            if(D[nod_curent] + cost < D[vecin])
            {
                D[vecin] = D[nod_curent] + cost;
                if(in_queue[vecin] == false)
                {
                    Coada.push(vecin);
                    in_queue[vecin] = true;
                }
            }
        }
    }
}
void Afiseaza()
{
    for(int i = 2; i <= N; i++)
    {
        if(D[i] != INF)
            cout << D[i] << " ";
        else
            cout << "0 ";
    }
}

int main()
{
    Citeste();
    Dijkstra(1);
    Afiseaza();
}