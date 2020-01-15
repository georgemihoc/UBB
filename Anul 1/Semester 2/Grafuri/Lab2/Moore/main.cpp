#include<iostream>
#include<fstream>
using namespace std;

ifstream f("graf.txt");

int pop(int coada[10],int &lcoada)
{
    int elem = coada[1];
    for(int i=1;i<=lcoada-1;++i)
        coada[i] = coada[i+1];
    --lcoada;
    return elem;
}

void push(int coada[10],int &lcoada,int elem)
{
    ++lcoada;
    coada[lcoada] = elem;
}

void Moore(int MA[10][10],int n,int s,int l[10],int p[10])
{
    int x;
    l[s] = 0;
    p[s] = 0;
    for(int i=1;i<=n;++i)
        if(i != s)
            l[i] = 9999;
    int coada[10],lcoada=1;
    coada[1] = s;
    while(lcoada!=0)
    {
        x = pop(coada,lcoada);
        for(int j=1;j<=n;++j)
        {
            if(MA[x][j] == 1)
            {
                if(l[j] == 9999)
                {
                    p[j] = x;
                    l[j] = l[x] + 1;
                    push(coada,lcoada,j);
                }
            }
        }
    }
}

void MooreDrum(int p[10],int l[10],int dest)
{
    int k,u;
    k = l[dest];
    u = dest;
    cout<<dest<<"->";
    while(k)
    {
        cout<<u<<' ';
        u = p[u];
        --k;
    }
    cout<<u;
    cout<<"\n";
}

void afisMoore(int p[10],int l[10],int n)
{
    cout<<"Distante:\n";
    for(int i = 1; i <= n; ++i)
        cout<<l[i]<<' ';
    cout<<'\n';
    cout<<"Parinti:\n";
    for(int i = 1; i <= n; ++i)
        cout<<p[i]<<' ';
    cout<<"\n\n\n";
}
int main()
{
    int MA[10][10] = {0},m,n=0,a,b,s,p[10],l[10];
    ///Citire graf
    f>>m;
    for(int i=1;i<=m;++i)
    {
        f>>a>>b;
        MA[a][b] = 1;
        if(a>n)
            n = a;
        if(b>n)
            n = b;
    }
    cin>>s;
    Moore(MA,n,s,l,p);
    //afisMoore(p,l,n);
    cout<<"DRUMURI MINIME:"<<endl;
    for(int i=1;i<=n;++i)
        MooreDrum(p,l,i);

    f.close();
    return 0;

}

