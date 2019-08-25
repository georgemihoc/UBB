#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> 
#include <vector>
using namespace std;

class Quackable {
private:
public:

	Quackable() {};
	virtual void quack() = 0;
	virtual ~Quackable() {};
};

class Duck : public Quackable{
private:
public:
	virtual void quack() override {
		cout << "quack\n";
	}
	~Duck() override { cout << "~Duck()\n"; }
};

class Flock : public Quackable {
private:
	vector<Quackable*> stol;
public:
	void add(Quackable* q) {
		stol.push_back(q);
	}
	virtual void quack() override {
		for (auto q : stol) {
			q->quack();
		}
	}
	~Flock() override {
		for (auto q : stol) {
			delete q;
		}
		cout << "~Flock()\n";
	}
};

class Goose {
private:
public:
	void honk() {
		cout << "honk\n";
	}
	~Goose() {
		cout << "~G()\n";
	}
};

class GooseAdapter: public Quackable {
private:
	Goose& g;
public: 
	GooseAdapter(Goose& g) : g{ g } {}
	virtual void quack() override {
		g.honk();
	}
	~GooseAdapter() override {
		cout << "~GA()\n";
	}
};

class Simulator{
private:
public:
	void simulate(Quackable* q) {
		q->quack();
	}
};

int main() {
	{
	Simulator s;
	s.simulate(new Duck);
	cout << "-----------\n";
	Flock* f = new Flock;
	f->add(new Duck);
	f->add(new Duck);
	s.simulate(f);
	cout << "-----------\n";
	Flock* f2 = new Flock;
	f2->add(new Duck);
	Goose g;
	GooseAdapter* ga = new GooseAdapter{ g };
	f2->add(ga);
	s.simulate(f2);
	cout << "-----------\n";
	delete f;
	delete f2;
	}
	_CrtDumpMemoryLeaks();
	system("PAUSE");
	return 0;
}