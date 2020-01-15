// C++ program for implementation of Ford Fulkerson algorithm 
#include <iostream> 
#include <fstream>
#include <limits.h>
#include <string.h> 
#include <queue> 
using namespace std;
ifstream f("date.in");
/*
DATE.IN
0 1 16
0 2 13
1 2 10
1 3 12
2 1 3
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4
*/
#define V 6

bool bfs(int rGraph[V][V], int s, int t, int parent[]) 
{ 
	bool visited[V];
	memset(visited, 0, sizeof(visited));
	queue <int> q; 
	q.push(s); 
	visited[s] = true; 
	parent[s] = -1; 

	while (!q.empty())
	{ 
		int u = q.front(); 
		q.pop(); 
		for (int v=0; v<V; v++) 
		{ 
			if (visited[v]==false && rGraph[u][v] > 0) 
			{ 
				q.push(v); 
				parent[v] = u; 
				visited[v] = true; 
			} 
		} 
	} 

	return (visited[t] == true);
} 

int fordFulkerson(int graph[V][V], int s, int t)
{ 
	int u, v; 

	int rGraph[V][V];

	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++) 
			rGraph[u][v] = graph[u][v]; 

	int parent[V]; 

	int max_flow = 0; 

	while (bfs(rGraph, s, t, parent))
	{
		int path_flow = INT_MAX; 
		for (v=t; v!=s; v=parent[v]) 
		{ 
			u = parent[v]; 
			path_flow = min(path_flow, rGraph[u][v]); 
		}
		for (v=t; v != s; v=parent[v]) 
		{ 
			u = parent[v]; 
			rGraph[u][v] -= path_flow; 
			rGraph[v][u] += path_flow; 
		} 

		max_flow += path_flow;
	}
	return max_flow;
} 

int main()
{
    int graph[V][V],x,y,cost;
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            graph[i][j]=0;
    while(!f.eof())
    {
        f>>x>>y>>cost;
        graph[x][y]=cost;
    }




    cout << endl<<"The maximum possible flow is " << fordFulkerson(graph, 0, 5)<<endl;

	return 0; 
} 

