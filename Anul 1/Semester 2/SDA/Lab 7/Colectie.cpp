#include"Colectie.h"
#include"IteratorColectie.h"

bool relMaiMic(TElem a, TElem b)
{
	return a < b;
}

Colectie::Colectie()
{
	relatie = relMaiMic;
}



void Colectie::adauga(TElem e)
{
	Nod *curent = rad, *precedent = rad, *nodNou;

	nrElem++;
	while (curent != nullptr)
	{
		if ((relatie(e, curent->element) == 0) && (relatie(curent->element,e) == 0))
		{
			curent->frecventa++;
			return ;
		}

		if (relatie(e, curent->element) == 1)
		{
			precedent = curent;
			curent = curent->st;
			continue;
		}

		if (relatie(e, curent->element) == 0)
		{
			precedent = curent;
			curent = curent->dr;
			continue;
		}
	}

	nodNou = new Nod(e,1);
	nodNou->parinte = precedent;

	if (precedent == nullptr)
	{
		rad = nodNou;
		return;
	}

	if (relatie(e, precedent->element) == 1)
	{
		precedent->st = nodNou;
	}
	else
	{
		precedent->dr = nodNou;
	}

	return;
}

Nod* Colectie::minim(Nod* subarbore)
{
	Nod *curent = subarbore, *precedent = subarbore;

	while (curent != nullptr)
	{
		precedent = curent;
		curent = curent->st;
	}
	return precedent;
}

Nod* Colectie::succesor(Nod* nod)
{
	if (nod->dr != nullptr)
	{
		return minim(nod->dr);
	}
	else
	{
		Nod *precedent = nod->parinte, *p=nod;
		while (precedent != nullptr && precedent->dr == p)
		{
			p = p->parinte;
			precedent = p->parinte;
		}
		return precedent;
	}
}

void Colectie::sterge_rec(Nod *arbore, TElem e)
{
	if (arbore == nullptr)
		return ;

	if (relatie(e, arbore->element) == 0 && relatie(arbore->element, e) == 0)	// am subarbore si stang si drept
	{

		arbore->frecventa--;

		if (arbore->frecventa > 0)
			return;

		if (arbore->dr == nullptr)
		{
			Nod *parinte = arbore->parinte;
			if (parinte == nullptr)
			{
				rad = arbore->st;
				if(rad!=nullptr)
					rad->parinte = nullptr;
			}
			else
			{
				if (parinte->st == arbore)
				{
					parinte->st = arbore->st;
					if (arbore->st != nullptr)
						(arbore->st)->parinte = parinte;
				}
				else
				{
					parinte->dr = arbore->st;
					if (arbore->st != nullptr)
						(arbore->st)->parinte = parinte;
				}
			}
			delete arbore;
			return;
		}

		if (arbore->st == nullptr)
		{
			Nod *parinte = arbore->parinte;
			if (parinte == nullptr)
			{
				rad = arbore->dr;
				if (rad != nullptr)
					rad->parinte = nullptr;
			}
			else
			{
				if (parinte->st == arbore)
				{
					parinte->st = arbore->dr;
					if (arbore->dr != nullptr)
						(arbore->dr)->parinte = parinte;
				}
				else
				{
					parinte->dr = arbore->dr;
					if (arbore->dr != nullptr)
						(arbore->dr)->parinte = parinte;
				}
			}
			delete arbore;
			return;
		}

		Nod *mini = minim(arbore->dr);

		arbore->element = mini->element;
		arbore->frecventa = mini->frecventa;
		mini->frecventa = 1;
		sterge_rec(mini, mini->element);

		return;
	}
	if (relatie(e, arbore->element) == 1)	// e este in stanga
	{
		sterge_rec(arbore->st, e);
		return;
	}
	if (relatie(e, arbore->element) == 0)		//	e este in dreapta
	{

		sterge_rec(arbore->dr, e);
		return;
	}
	
}


bool Colectie::sterge(TElem e)
{
	bool rez = cauta(e);
	if (rez == true)
	{
		nrElem--;
		sterge_rec(rad, e);
	}
	return rez;
}


bool Colectie::cauta(TElem e) const
{
	Nod *curent = rad;

	while (curent != nullptr)
	{
		if ((relatie(e, curent->element) == 0) && (relatie(curent->element, e) == 0))
		{

			return true;
		}

		if (relatie(e, curent->element) == 1)
		{
			curent = curent->st;
			continue;
		}

		if (relatie(e, curent->element) == 0)
		{
			curent = curent->dr;
			continue;
		}
	}
	return false;
}

Nod* Colectie::search(TElem e)
{
	Nod *curent = rad;

	while (curent != nullptr)
	{
		if ((relatie(e, curent->element) == 0) && (relatie(curent->element, e) == 0))
		{

			return curent;
		}

		if (relatie(e, curent->element) == 1)
		{
			curent = curent->st;
			continue;
		}

		if (relatie(e, curent->element) == 0)
		{
			curent = curent->dr;
			continue;
		}
	}
	return nullptr;
}

int Colectie::nrAparitii(TElem e) const
{
	Nod *curent = rad;

	while (curent != nullptr)
	{
		if ((relatie(e, curent->element) == 0) && (relatie(curent->element, e) == 0))
		{
			return curent->frecventa;
		}

		if (relatie(e, curent->element) == 1)
		{
			curent = curent->st;
			continue;
		}

		if (relatie(e, curent->element) == 0)
		{
			curent = curent->dr;
			continue;
		}
	}
	return 0;
}

int Colectie::dim() const
{
	return nrElem;
}

bool Colectie::vida() const
{
	if (dim() == 0)
		return true;
	return false;
}

Colectie::~Colectie()
{
	while (dim() > 0)
	{
		sterge(rad->element);
	}
}

IteratorColectie Colectie::iterator() const
{
	return IteratorColectie(*this);
}

void Colectie::diferenta(Colectie &c2) 
{
	IteratorColectie ic2 = c2.iterator();
	int e2;

	while (ic2.valid() == true)
	{
		e2 = ic2.element();
		ic2.urmator();
		sterge(e2);
	}
}