#pragma once
#include<vector>
#include<string>
#include<memory.h>
using namespace std;



template <typename ElementT>
class IteratorVectorT;

template <typename ElementT>
class VectDinNewDeleteT;

template<typename ElementT>
class nod;


class VectorException : public exception {
public:
    vector<string> mesajEroare;
    VectorException(const vector<string>& errors) : mesajEroare{ errors } {}
    friend ostream& operator<<(ostream& out, const VectorException& ex);
};
ostream& operator<<(ostream& out, const VectorException& exceptii)
{
    for (unsigned int i = 0; i < exceptii.mesajEroare.size(); i++) {
        out << exceptii.mesajEroare.at(i);
    }
    return out;
}

template<typename ElementT>
class nod
{
public:
    ElementT valoare;
    unique_ptr<nod<ElementT>> urmator;
    nod(ElementT e)  noexcept :valoare{ e }, urmator{ nullptr }{}
};

template <typename ElementT>
class VectDinNewDeleteT
{
private:
    int lungime;
    nod<ElementT>* prim;
    nod<ElementT>* ultim;

public:

    /*
        Constructor
    */
    VectDinNewDeleteT() noexcept;	//constructor

    /*
    Constructor de copiere
    */
    VectDinNewDeleteT(const VectDinNewDeleteT& ot); //rule of 3

    /*
    Eliberam memoria
    */
    ~VectDinNewDeleteT() noexcept;//rule of 3

    /*
    Operator assgnment
    elibereaza ce era in obiectul curent (this)
    aloca spatiu pentru elemente
    copieaza elementele din ot in this
    */
    VectDinNewDeleteT& operator=(const VectDinNewDeleteT& ot);//rule of 3


    /*
    Move constructor
    Apelat daca construim un nou vector dintr-un r-value (ex temporary, expresie de la return)
    Obiectul ot nu se mai foloseste astfel se poate refolosi interiorul lui
    */
    VectDinNewDeleteT(VectDinNewDeleteT&& ot) noexcept; //rule of 5

    /*
    Move assignment
    Similar cu move constructor
    Folosit la assignment
    */
    VectDinNewDeleteT& operator=(VectDinNewDeleteT&& ot) noexcept; //rule of 5

    void push_back(const ElementT& el);

    ElementT& at(int poz) const;

    void set(int poz, const ElementT& el);

    int size() const noexcept;

    friend class IteratorVectorT<ElementT>;
    //functii care creaza iteratori
    IteratorVectorT<ElementT> begin() noexcept;
    IteratorVectorT<ElementT> end() noexcept;
};

/*
Constructor default
*/
template<typename ElementT>
VectDinNewDeleteT<ElementT>::VectDinNewDeleteT() noexcept
{
    lungime = 0;
    prim = nullptr;
    ultim = nullptr;
}

/*
Constructor de copiere
Obiectul current (this) acum se creaza
aloca spatiu pentru elemente
copieaza elementele din ot in this
*/
template<typename ElementT>
VectDinNewDeleteT<ElementT>::VectDinNewDeleteT(const VectDinNewDeleteT<ElementT>& ot) {
    unique_ptr<nod<ElementT>> nodNou;
    nod<ElementT> *auxiliar=ot.prim;

    this->ultim = this->prim = nullptr;
    this->lungime = 0;

    while (auxiliar != nullptr)
    {
        try {
            nodNou = make_unique<nod<ElementT>>(auxiliar->valoare);
        }
        catch (...) {
            vector<string> exceptii;
            exceptii.push_back("exceptie make_unique");
            throw VectorException(exceptii);
        }

        if (this->prim == nullptr)
        {
            this->prim = this->ultim = nodNou.release();
        }
        else
        {
            this->ultim->urmator = move(nodNou);
            this->ultim = this->ultim->urmator.get();
        }
        this->lungime++;
        auxiliar = auxiliar->urmator.get();
    }
}

/*
	Eliberam memoria
*/
template<typename ElementT>
VectDinNewDeleteT<ElementT>::~VectDinNewDeleteT() noexcept {
    unique_ptr<nod<ElementT>> precedent = unique_ptr<nod<ElementT>>(prim);	// nod->urmator este unique_ptr, deci se dealoca singur pentru mine

    /* daca nu faceam cu unique_ptr trebuia sa fac asa
    while (auxiliar != nullptr) //parcurg si distrug fiecare nod
    {
        precedent = unique_ptr<nod<ElementT>>(auxiliar);
        auxiliar = auxiliar->urmator.get();
        //deoarece folosesc unique_ptr se va dealoca obiectul referit de precedent, adica elementul din nodul curent
    }
    */
}

/*
Operator assgnment
elibereaza ce era in obiectul curent (this)
aloca spatiu pentru elemente
copieaza elementele din ot in this
*/
template<typename ElementT>
VectDinNewDeleteT<ElementT>& VectDinNewDeleteT<ElementT>::operator=(const VectDinNewDeleteT<ElementT>& ot) {
    if (this == &ot) {
        return *this;//s-a facut l=l;
    }
    {//scope
        unique_ptr<nod<ElementT>> precedent = unique_ptr<nod<ElementT>>(prim);	//aici distrug elementele din this
    }

    unique_ptr<nod<ElementT>> nodNou;
    nod<ElementT> *auxiliar = prim;

    this->ultim = this->prim = nullptr;
    this->lungime = 0;

    auxiliar = ot.prim;
    while (auxiliar != nullptr)	//aici le copiez din ot in this
    {
        try {
            nodNou = make_unique<nod<ElementT>>(auxiliar->valoare);
        }
        catch (...) {
            vector<string> exceptii;
            exceptii.push_back("exceptie make_unique");
            throw VectorException(exceptii);
        }

        if (this->prim == nullptr)
            this->prim = this->ultim = nodNou.release();
        else{
            this->ultim->urmator = move(nodNou);
            this->ultim = this->ultim->urmator.get();
        }
        this->lungime++;
        auxiliar = auxiliar->urmator.get();
    }
    return *this;
}

/*
Move constructor
Apelat daca construim un nou vector dintr-un r-value (ex temporary)
Obiectul ot nu se mai foloseste astfel se poate refolosi interiorul lui
*/
template<typename ElementT>
VectDinNewDeleteT<ElementT>::VectDinNewDeleteT(VectDinNewDeleteT&& ot) noexcept {
    // Copy the data pointer from other
    this->prim = ot.prim;
    this->ultim = ot.ultim;
    this->lungime = ot.lungime;

    // Release the data pointer from the source object so that
    // the destructor does not free the memory multiple times.
    ot.prim = nullptr;
    ot.ultim = nullptr;
    ot.lungime = -1;
}

/*
Move assignment
Similar cu move constructor
Folosit la assignment
Elibereaza ce continea obiectul curent (this)
"fura" interiorul lui ot
pregateste ot pentru distrugere
*/
template<typename ElementT>
VectDinNewDeleteT<ElementT>& VectDinNewDeleteT<ElementT>::operator=(VectDinNewDeleteT<ElementT>&& ot)  noexcept {
    if (this == &ot) {
        return *this;
    }
    {
        unique_ptr<nod<ElementT>> precedent = unique_ptr<nod<ElementT>>(prim);
    }

    // Copy the data pointer from other
    this->prim = ot.prim;
    this->ultim = ot.ultim;
    this->lungime = ot.lungime;

    // Release the data pointer from the source object so that
    // the destructor does not free the memory multiple times.
    ot.prim = nullptr;
    ot.ultim = nullptr;
    ot.lungime = -1;

    return *this;
}

template<typename ElementT>
void VectDinNewDeleteT<ElementT>::push_back(const ElementT& e) {
    unique_ptr<nod<ElementT>> nodNou;
    try {
        nodNou = make_unique<nod<ElementT>>(e);
    }
    catch (...) {
        vector<string> exceptii;
        exceptii.push_back("exceptie make_unique");
        throw VectorException(exceptii);
    }

    if (ultim == nullptr)
    {
        prim = ultim = nodNou.release();
        lungime++;
        return;
    }
    ultim->urmator = move(nodNou);
    ultim = ultim->urmator.get();
    lungime++;
    return;
}

template<typename ElementT>
ElementT& VectDinNewDeleteT<ElementT>::at(int i) const {
    if (i < 0 || i >= lungime) {
        vector<string> exceptii;
        exceptii.push_back("i este in afara intervalului");
        throw VectorException(exceptii);
    }

    nod<ElementT>* auxiliar = prim;
    int pozitie = 0;

    while (auxiliar != ultim && pozitie < i) {
        auxiliar = auxiliar->urmator.get();
        pozitie++;
    }
    //auxiliar se afla pe pozitia i
    return auxiliar->valoare;
}

template<typename ElementT>
void VectDinNewDeleteT<ElementT>::set(int i, const ElementT& e) {
    if (i < 0 || i >= lungime) {
        vector<string> exceptii;
        exceptii.push_back("i este in afara intervalului");
        throw VectorException(exceptii);
    }

    nod* auxiliar = prim;
    int pozitie = 0;

    while (auxiliar != ultim && pozitie < i) {
        auxiliar = auxiliar->urmator;
        pozitie++;
    }
    //auxiliar se afla pe pozitia i
    const ElementT aux = auxiliar->valoare;
    auxiliar->valoare = e;
    return aux;
}

template<typename ElementT>
int VectDinNewDeleteT<ElementT>::size() const noexcept {
    return lungime;
}

template<typename ElementT>
IteratorVectorT<ElementT> VectDinNewDeleteT<ElementT>::begin() noexcept
{
    return IteratorVectorT<ElementT>(*this);
}

template<typename ElementT>
IteratorVectorT<ElementT> VectDinNewDeleteT<ElementT>::end() noexcept
{
    return IteratorVectorT<ElementT>(*this, lungime);
}












template<typename ElementT>
class IteratorVectorT {
private:
    friend class VectDinNewDeleteT<ElementT>;
    const VectDinNewDeleteT<ElementT>& referintaVector;
    nod<ElementT>* referintaNod;

public:
    IteratorVectorT(const VectDinNewDeleteT<ElementT>& v) noexcept;
    IteratorVectorT(const VectDinNewDeleteT<ElementT>& v, int poz) noexcept;
    bool valid()const;
    ElementT& element() const noexcept;
    void next() noexcept;
    ElementT& operator*() noexcept;
    IteratorVectorT& operator++() noexcept;
    bool operator==(const IteratorVectorT& ot) noexcept;
    bool operator!=(const IteratorVectorT& ot) noexcept;
};

template<typename ElementT>
IteratorVectorT<ElementT>::IteratorVectorT(const VectDinNewDeleteT<ElementT>& c) noexcept : referintaVector{ c }, referintaNod{ referintaVector.prim }{}

template<typename ElementT>
IteratorVectorT<ElementT>::IteratorVectorT(const VectDinNewDeleteT<ElementT>& c, int poz)noexcept : referintaVector{ c }, referintaNod{ referintaVector.ultim }{}

template<typename ElementT>
bool IteratorVectorT<ElementT>::valid()const {
    if (referintaNod == nullptr) {
        return false;
    }
    return true;
}

template<typename ElementT>
ElementT& IteratorVectorT<ElementT>::element() const noexcept {
    return referintaNod->valoare;
}

template<typename ElementT>
void IteratorVectorT<ElementT>::next()  noexcept {
    referintaNod = referintaNod->urmator.get();
}

template<typename ElementT>
ElementT& IteratorVectorT<ElementT>::operator*() noexcept {
    return element();
}

template<typename ElementT>
IteratorVectorT<ElementT>& IteratorVectorT<ElementT>::operator++() noexcept {
    next();
    return *this;
}

template<typename ElementT>
bool IteratorVectorT<ElementT>::operator==(const IteratorVectorT<ElementT>& ot) noexcept {
    return referintaNod == ot.referintaNod;
}

template<typename ElementT>
bool IteratorVectorT<ElementT>::operator!=(const IteratorVectorT<ElementT>& ot)noexcept {
    return !(*this == ot);
}


