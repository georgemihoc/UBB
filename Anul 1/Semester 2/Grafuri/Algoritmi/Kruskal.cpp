#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#define NMAX 200005
using namespace std;

ifstream f("date.in");
/*DATE.IN
6 9
1 2 1
1 3 3
1 4 4
2 3 2
2 4 4
3 4 4
3 5 4
3 6 7
5 6 5
*/
ofstream g("date.out");
vector<int> answer;
int x[NMAX], y[NMAX], parinte[NMAX], cost[NMAX], ind[NMAX];
int n, m;
int cost_sol = 0;

int find(int x){
    if(parinte[x] == x) return x;
    parinte[x] = find(parinte[x]);
    return parinte[x];
}

void unite(int x, int y){
    parinte[find(y)] = find(x);
}

void citire(int& n, int& m, int x[], int y[], int cost[], int ind[]){
    f>>n>>m;
    for(int i = 1; i<=m; i++){
        f>>x[i]>>y[i]>>cost[i];
        ind[i] = i;
    }
}


void solve(int& cost_sol, vector<int>& answer){
    sort(ind + 1, ind + m + 1, [&](int i, int j){
        return cost[i] < cost[j];
    });

    for(int i = 1; i<=n; i++){
        parinte[i] = i;
    }
    for(int i = 1; i<=m; i++){
        if(find(x[ind[i]]) != find(y[ind[i]])){
            cost_sol += cost[ind[i]];
            answer.push_back(ind[i]);
            unite(x[ind[i]], y[ind[i]]);
        }
    }
}


void afisare(int cost_sol, vector<int> answer){
    g<<cost_sol<<endl;
    g<<answer.size()<<endl;
    for(unsigned i = 0; i<answer.size(); i++){
        g<<x[answer[i]]<<" "<<y[answer[i]]<<endl;
    }
}

int main(){
    citire(n, m, x, y, cost, ind);
    solve(cost_sol, answer);
    afisare(cost_sol, answer);
    return 0;
}