#include"IteratorColectie.h"
#include"Colectie.h"
#include<stack>
using namespace std;




IteratorColectie::IteratorColectie(const Colectie& c) : c{ c }
{
	prim();
}


void IteratorColectie::prim()
{
	if (c.rad != nullptr)
	{
		st.push(c.rad);
		pozElem = c.rad;
		frecvElem = 1;
	}
}


void IteratorColectie::urmator()
{
	frecvElem++;
	if (frecvElem > pozElem->frecventa)
	{
		if (st.empty() == false)
		{
			st.pop();
			if (pozElem->dr != nullptr)
			{
				st.push(pozElem->dr);
			}
			if (pozElem->st != nullptr)
			{
				st.push(pozElem->st);
			}
			if (st.empty() == false)
			{
				pozElem = st.top();
				frecvElem = 1;
			}
			else
			{
				pozElem = nullptr;
				frecvElem = 0;
			}
		}
		else
		{
			pozElem = nullptr;
			frecvElem = 0;
		}
	}
}


bool IteratorColectie::valid() const
{
	if (pozElem == nullptr)
	{
		return false;
	}
	return true;
}


int IteratorColectie::element() const
{
	if (valid() == false)
		return -1;
	else
		return pozElem->element;
}



