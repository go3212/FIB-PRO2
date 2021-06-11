#include <iostream>
#include "ArbreN.hh"
#include "ArbNIOint.hh"

int main ()
{
    ArbreNari<int> tree(3), treetw(3);
    // 5 7 2 0 0 0 1 0 0 0 0 1 0 0 0 3 0 8 0 0 0 4 0 0 0
    llegir_arbre_int(tree, 0);
    tree.arbsuma(treetw);
    escriure_arbre_int(treetw);
}