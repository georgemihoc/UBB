#include<iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");
/*
DATE.IN
7 6
5 1
1 3
1 7
3 4
3 6
4 2*/
int fmin(int t[10],int n) {
    int gasit[10] = {0};
    for(int i = 1;i<=n;++i)
        gasit[t[i]]=1;
    for(int i=1;i<=n;++i)
        if(gasit[i]==0) {
            t[i] = i;
            return i;
        }
}

int caut(int k[10],int n) {
    int gasit[10] = {0};
    for(int i = 1;i<=n;++i)
        gasit[k[i]]=1;
    for(int i=1;i<=n;++i)
        if(gasit[i]==0) {

            return i;
        }
    return 0;
}

void trans(int k[10],int y,int n) {
    for(int i = 1;i < n; ++i )
        k[i] = k[i+1];
    k[n-1] = y;
}

int main() {
    int a,b,n,m,MA[10][10],t[10] = {0},t1[10] = {0};
    f>>n>>m;
    for(int i = 1; i <= m; ++i) {
        f>>a>>b;
        MA[a][b] = 1;
        MA[b][a] = 1;
        t[b]=a;
    }
    for(int i = 1;i <= n; ++i)
        t1[i] = t[i];

    ///Codare Prufer
    int l = 0,k[10]={0},v,w,c=n-1;
    while(c) {
        v = fmin(t,n);
        //cout<<v<<" ";
        w = t1[v];
        //cout<<w<<"\n";
        k[++l]=w;
        --c;
    }
    cout<<"Codarea Prufer:";
    for(int i = 1;i<=n-1;++i)
        cout<<k[i];
    cout<<'\n';

    ///Decodare Prufer
    cout<<"Muchiile:\n";
    int j=1,x,y,k1[10];
    for(int i = 1;i <= n; ++i)
        k1[i] = k[i];
    for(int i = 1;i<=n-1;++i) {
        x = k[1];
        y = caut(k,n);
        cout<<x<<" "<<y<<'\n';
        trans(k,y,n);
    }


    return 0;


}




