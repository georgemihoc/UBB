#include "Vector.h"
#include "UI.h"
#include "Domain.h"
#include "Service.h"
#include <stdlib.h>
#include "Teste.h"

int main()
{
    ruleaza_teste(); // rulam testele

    VectorDinamic* v; // declaram vectorul dinamic
    v = creeaza_vector(); // creem vectorul dinamic

    afisare_meniu(v); // afisarea meniului

    distruge(v); // dealocam memoria alocata pt vectorul dinamic
    return 0;
}
