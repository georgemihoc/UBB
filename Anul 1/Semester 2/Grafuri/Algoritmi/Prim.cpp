#include<iostream>
#include<fstream>
#include<list>
#include<queue>
using namespace std;
# define INF 99999999
ifstream f("date.in");
/*
 DATE.IN
6 9
0 1 1
0 2 3
0 3 4
1 2 2
1 3 4
2 3 4
2 4 4
2 5 7
4 5 5
 */
typedef pair<int, int> iPair;


class Graph
{
    int V;

    list< pair<int, int> > *adj;

public:
    Graph(int V); // Constructor

    void addEdge(int u, int v, int w);

    void primMST();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::primMST()
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    int src = 0;

    vector<int> key(V, INF);

    vector<int> parent(V, -1);

    vector<bool> inMST(V, false);

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true; // Include vertex in MST

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < V; ++i)
        cout<<parent[i]<<"->"<<i<<"\n";
}

int main()
{
    int V,muchii,x,y,cost;
    f>>V>>muchii;
    Graph g(V);
    for(int i=1;i<=muchii;i++) {
        f >> x >> y >> cost;
        g.addEdge(x,y,cost);
    }
    cout<<"Minimum spanning tree:\n";
    g.primMST();
    return 0;
} 

