#include <iostream>
#include "Cua.hh"
#include "CuaIOint.hh"

int main ()
{
    Cua<int> first, conc;
    llegir_cua_int(first, 0);
    llegir_cua_int(conc, 0);

    first.concat(conc);

    escriure_cua_int(first);
}