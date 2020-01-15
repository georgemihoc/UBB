//
// Created by George on 2019-03-13.
//

#include <stdio.h>
#include <string.h>
#include "Domain.h"
#include "Validator.h"

int valideazaMaterie(char* nume, char * producator,float cantitate)
{
    int erori = 0;
    if (strlen(nume) == 0)
    {
        erori++;
    }
    if (strlen(producator) == 0)
    {
        erori++;
    }
    if (cantitate < 0)
    {
        erori++;
    }
    if (erori == 0)
    {
        return 1;
    }
    return -1;
}