//
// Created by George on 2019-04-01.
//

#ifndef SET_NOD_H
#define SET_NOD_H
#include "Multime.h"
typedef int TElem;
typedef struct node{
    TElem value;
    struct node *next,*prev;
}NodeDL;
#endif //SET_NOD_H
