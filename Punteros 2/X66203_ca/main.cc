#include <iostream>
#include "ArbreN.hh"
#include "ArbNIOint.hh"

int main ()
{
    ArbreNari<int> tree(3);
    llegir_arbre_int(tree, 0);
    cout << tree.maxim() << endl;
    // 1 2 3 0 0 0 0 0 4 0 0 0 5 6 0 0 0 0 0 -> 6
    // 1 2 3 0 0 0 0 0 40 0 0 0 5 6 0 0 0 0 0 -> 40
    // 100 2 3 0 0 0 0 0 40 0 0 0 5 6 0 0 0 0 0 -> 100

}