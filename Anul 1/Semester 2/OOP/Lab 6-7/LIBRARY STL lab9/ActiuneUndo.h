//
// Created by George on 2019-04-25.
//

#ifndef LIBRARY_ACTIUNEUNDO_H
#define LIBRARY_ACTIUNEUNDO_H
#include "bookrepo.h"
#include "Book.h"

#pragma once
class ActiuneUndo {
public:
    virtual void doUndo() = 0;
    //destructorul e virtual pentru a ne asigura ca daca dau delete pe un
    // pointer se apeleaza destructorul din clasa care trebuie
    virtual ~ActiuneUndo() {};
};
class UndoAdauga : public ActiuneUndo {
    Book carte;
    BookRepo& rep;
public:
    UndoAdauga(BookRepo& rep, const Book& carte) :rep{ rep }, carte{ carte } {}
    void doUndo() override {
        auto all{ rep.getAll() };
        auto i{ 0 };
        for (auto& Cart : all) {
            ++i;
            if (Cart.getTitle() == carte.getTitle())
                break;
        }
        rep.remove(i);
    }
};

class UndoSterge : public ActiuneUndo {
    Book carte;
    BookRepo& rep;
public:
    UndoSterge(BookRepo& rep, const Book& carte) :rep{ rep }, carte{ carte } {}
    void doUndo() override {
        rep.store(carte);
    }
};

class UndoModific : public ActiuneUndo {
    Book carte;
    int poz;
    BookRepo& rep;
public:
    UndoModific(BookRepo& rep, const Book& carte,int poz) :rep{ rep }, carte{ carte }, poz{ poz } {}
    void doUndo() override {
        rep.modify(poz, carte);
    }
};
#endif //LIBRARY_ACTIUNEUNDO_H