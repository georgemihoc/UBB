#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
#define NMAX 9999
#define MMAX 9999999
using namespace std;

ifstream f("date.in");
/*DATE.IN
4 5
1 2
1 3
2 3
3 4
3 4
*/
ofstream g("date.out");

int n, m;
vector<int>Graf[NMAX];
vector<int> cycle;
stack<int> st;

void citire(int &n, int &m, vector<int>Graf[]){
    f >> n >> m;
    for(int i = 1; i<=m; i++){
        int x, y;
        f >> x >> y;
        Graf[x].push_back(y);
        Graf[y].push_back(x);
    }
}



int check_euler(vector<int>Graf[]){
    int start_node = 1, num_odd = 0;
    for(int i = 1; i<=n; i++){
        if(Graf[i].size() % 2 == 1){
            start_node = i;
            num_odd ++;
        }
    }
    if(num_odd > 0 && num_odd != 2){
        return -1;
    }
    return start_node;
}


vector<int> make_cycle(vector<int>Graf[]){
    vector<int>result;
    int start_node = check_euler(Graf);
    st.push(start_node);
    while(!st.empty()){
        int node = st.top();

        if(!Graf[node].empty()){
            int new_node = Graf[node].back();
            Graf[node].pop_back();
            Graf[new_node].erase(find(Graf[new_node].begin(), Graf[new_node].end(), node));
            st.push(new_node);
        }
        else{                      
            result.push_back(node);
            st.pop();          
        }
    }
    return result;
}


void solve(vector<int>Graf[]){
    if(check_euler(Graf) != -1){
        auto cycle = make_cycle(Graf);
        for(const auto& elem : cycle){
            g << elem << ' ';
        }
    }
    else{
        g << "Graful nu are ciclu/lant eulerian";
    }
}

int main(){
    citire(n, m, Graf);
    solve(Graf);
    return 0;
}
