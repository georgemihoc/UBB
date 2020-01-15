#include<iostream>
#include<string>
#include<vector>
#include <time.h>
#include <exception>
using std::string;
using std::vector;
using std::cout;
using std::iterator;
using namespace std;
/*
class Fruct {
public:
    virtual void tipareste() = 0;
    virtual bool cuSamburi() {
        return false;
    };
};

class Pepene : public Fruct {
private:
    float kg;
public:

    Pepene(float kg) :kg{ kg } {}

    virtual void tipareste() override {
        cout << kg << " pepene";
    }
};

class PepeneRosu : public Pepene {
public:

    PepeneRosu(int kg) :Pepene(kg) {};

    virtual void tipareste() override {
        Pepene::tipareste();
        cout << "rosu";
    }
};

class PepeneGalben : public Pepene {
public:

    PepeneGalben(int kg) :Pepene(kg) {};

    virtual void tipareste() override {
        Pepene::tipareste();
        cout << "galben";
    }
};

class CuSamburi : public Fruct {
private:
    Fruct* fruct;
public:

    CuSamburi(Fruct* fruct) :fruct{ fruct } {}

    virtual void tipareste() override {
        fruct->tipareste();
        cout << "cu samburi";
    }
    virtual bool cuSamburi() override {
        return true;
    }
};

class Cos {
private:
    vector<Fruct*> all;
public:

    void add(Fruct* f) {
        all.push_back(f);
    }

    vector<Fruct*> getAll(int tip) {
        vector<Fruct*> rez;

        for (auto& f : all)
            if (tip == 1 && f->cuSamburi())
                rez.push_back(f);
            else
            if (!f->cuSamburi())
                rez.push_back(f);
        return rez;
    }

};

int main() {
    Cos c;
    auto pr1 = new PepeneRosu(10);
    auto pg1 = new PepeneGalben(1);
    auto pgs = new CuSamburi(pg1);
    auto pg2 = new PepeneGalben(2);
    auto pr2 = new PepeneRosu(7);
    auto prs = new CuSamburi(pr2);

    c.add(pr1);
    c.add(pgs);
    c.add(pg2);
    c.add(prs);

    auto rez1 = c.getAll(1);
    cout << "Cu samburi:\n";

    for (auto f : rez1) {
        f->tipareste();
        cout << '\n';
    }

    cout << '\n';

    auto rez2 = c.getAll(0);
    cout << "Fara samburi:\n";

    for (auto f : rez2) {
        f->tipareste();
        cout << '\n';
    }

    return 0;

}

*/
/*
template <class T>
class Expresie{
private:
    //friend class Iterator;
    vector<T> v;
    int l;
public:
    Expresie(int nr):v{nr}{};
    Expresie& operator+(int nota){
        v.push_back(nota);
        l++;
        return *this;
    }
    Expresie& operator-(int nota){
       v.push_back(-nota);
        return *this;
    }
    Expresie& undo()
    {
        v.pop_back();
        return *this;
    }

    auto begin()
    {
        return v.begin();
    }
    auto end()
    {
        return v.end();
    }
};

void operatii()
{
    Expresie<int> exp{3};
    exp+5;
    exp+8;
    for(auto v:exp)
    {
        cout<<v<<" ";
    }
}
int main()
{
    operatii();
}
*/
#include<iostream>
using namespace std;
class A {
public:
    A() {
        cout << "A" << '\n';
    }
    virtual void print() {
        cout << "printA" << '\n';
    }
    ~A() { cout << "~A" << '\n'; }
};

class B : public A {
public:
    B() {
        cout << "B" << '\n';
    }
    void print()  {
        cout << "printB" << '\n';
    };
    virtual ~B() {
        cout << "~B" <<  '\n';
    }
};

int main() {
    auto o1 = new A();
    auto o2 = new B();
    o1->print();
    o2->print();
    delete o1;
    delete o2;
    return 0;
}