#include<iostream>
#include <list>
#include<fstream>
using namespace std; 
ifstream f("date.in");
/*
DATE.IN
5
0 1
2 3
3 4
 */
class Graph
{ 
    int V;
  
    list<int> *adj;
  
    void DFS(int v, bool visited[]);
public: 
    Graph(int V);
    void addEdge(int v, int w); 
    int connectedComponents();
}; 
  
int Graph::connectedComponents()
{ 
    bool *visited = new bool[V];
    int nr=0;
    for(int v = 0; v < V; v++) 
        visited[v] = false; 
  
    for (int v=0; v<V; v++) 
    { 
        if (visited[v] == false) 
        { 
            DFS(v, visited);

            cout << "\n";
            nr++;
        } 
    }
    return nr;
} 
  
void Graph::DFS(int v, bool visited[])
{ 
    visited[v] = true;
    cout << v << " "; 
  
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFS(*i, visited);
} 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w)
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 
  
int main()
{
    int noduri;
    f>>noduri;
    Graph g(noduri);
    while(!f.eof())
    {
        int x,y;
        f>>x;
        f>>y;
        g.addEdge(x,y);
    }

    cout << "Following are connected components \n"; 
    auto nr=g.connectedComponents();
    if(nr==1)
        cout<<"Connected graph";
    else
        cout<<"The graph is not connected";
    return 0;
} 