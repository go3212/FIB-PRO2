#include <iostream>
#include "LlistaIOint.hh"
#include "Llista.hh"

int main ()
{
    Llista<int> list;
    llegir_llista_int(list, 0);
    escriure_llista_int(list.reorganitzar_out(5));
}