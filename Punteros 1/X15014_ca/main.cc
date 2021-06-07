#include <iostream>
#include "Arbre.hh"
#include "ArbIOint.hh"

int main ()
{
    Arbre<int> tree, outputTree;
    llegir_arbre_int(tree, 0);
    tree.arb_sumes(outputTree);
    escriure_arbre_int(outputTree);
}