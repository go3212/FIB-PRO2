#include <iostream>
#include "ArbreN.hh"
#include "ArbNIOint.hh"

int main ()
{
    ArbreNari<int> tree(3);
    llegir_arbre_int(tree, 0);
	//escriure_arbre_int(tree);
    cout << ((tree.condicio_pref()) ? "true" : "false") << endl;
    // 9 12 8 4 0 0 0 6 0 0 0 6 0 0 0 8 0 0 0 12 0 0 0 4 0 0 0 6 16 0 0 0 2 0 0 0 24 0 0 0

}