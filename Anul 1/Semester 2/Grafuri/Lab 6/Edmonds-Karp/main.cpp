/*
 * C++ Program to Implement The Edmonds-Karp Algorithm
 */
#include<cstdio>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<iostream>
#include<fstream>

using namespace std;
ifstream f("date.in");
/*
 * DATE.IN
 6 10
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

int capacities[10][10];
int flowPassed[10][10];
vector<int> graph[10];
int parentsList[10];
int currentPathCapacity[10];

int bfs(int startNode, int endNode)
{
    for(int i=0;i<10;i++) {
        parentsList[i] = -1;
        currentPathCapacity[i] = 0;
    }

    queue<int> q;
    q.push(startNode);

    parentsList[startNode] = -2;
    currentPathCapacity[startNode] = 999;

    while(!q.empty())
    {
        int currentNode = q.front();
        q.pop();

        for(int i=0; i<graph[currentNode].size(); i++)
        {
            int y = graph[currentNode][i];
            if(parentsList[y] == -1)
            {
                if(capacities[currentNode][y] - flowPassed[currentNode][y] > 0)
                {
                    parentsList[y] = currentNode;
                    currentPathCapacity[y] = min(currentPathCapacity[currentNode],capacities[currentNode][y] - flowPassed[currentNode][y]);
                    if(y == endNode)
                    {
                        return currentPathCapacity[endNode];
                    }
                    q.push(y);
                }
            }
        }
    }
    return 0;
}

int edmondsKarp(int startNode, int endNode)
{
    int maxFlow = 0;
    while(true)
    {
        int flow = bfs(startNode, endNode);
        if (flow == 0)
        {
            break;
        }
        maxFlow += flow;
        int currentNode = endNode;
        while(currentNode != startNode)
        {
            int previousNode = parentsList[currentNode];
            flowPassed[previousNode][currentNode] += flow;
            flowPassed[currentNode][previousNode] -= flow;
            currentNode = previousNode;
        }
    }
    return maxFlow;
}
int main()
{
    int nodesCount, edgesCount;

    f>>nodesCount>>edgesCount;//nr noduri , nr muchii

    int source=0, end=nodesCount-1;

    for(int edge = 0; edge < edgesCount; edge++)
    {
        int x, y, cost;
        f>>x>>y>>cost;

        capacities[x][y] = cost;
        graph[x].push_back(y);

        graph[y].push_back(x);
    }

    int maxFlow = edmondsKarp(source, end);

    cout<<"Maximum Flow is:"<<maxFlow<<endl;

return 0;
}