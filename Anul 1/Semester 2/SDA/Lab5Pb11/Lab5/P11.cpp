#include "pch.h"
#include "P11.h"
#include <exception>
#include <iostream>
#include <stdlib.h>
#include <vector>
using std::exception;
using std::cout;
using std::vector;

int parinte(int i)
{
	return (i - 1) / 2;
}

int left(int i)
{
	return (2 * i + 1);
}

int right(int i)
{
	return (2 * i + 2);
}
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void adauga(TElem a[], TElem e, int& n)
{
	n++;
	int i = n - 1;
	a[i] = e;

	while (i != 0 && a[parinte(i)] > a[i])
	{
		swap(&a[i], &a[parinte(i)]);
		i = parinte(i);
	}
}

void MinALL(TElem a[], int i, int n)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < n && a[l] < a[i])
		smallest = l;
	if (r < n && a[r] < a[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&a[i], &a[smallest]);
		MinALL(a,smallest,n);
	}
}
int extract_min(TElem a[], int& n)
{
	if (n == 1)
	{
		n--;
		return a[0];
	}

	int root = a[0];
	a[0] = a[n - 1];
	n--;
	MinALL(a, 0, n);
	return root;
}
void sterge(TElem a[], int &n)
{
	extract_min(a, n);
}


void stergeMin(list<TElem>& elemente, int k)
{
	//if (k <= 0)
	//	throw exception("");
	TElem* a;
	a = new int[10000];
	int n = 0;
	list <int> ::iterator it;
	vector <TElem> vec(elemente.begin(), elemente.end());

	for (it = elemente.begin(); it != elemente.end(); ++it)
	{
		adauga(a, *it, n);
		//cout << *it << ' ';
	}

	elemente.clear();
	for (int i = 1; i <= k; ++i)
	{
		sterge(a, n);
	}

	for (int i = 0; i < n; ++i)
	{
		elemente.push_back(a[i]);
	}

	/*cout << '\n';

	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
		*/

}
