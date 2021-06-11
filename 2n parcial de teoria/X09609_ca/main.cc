#include <iostream>
#include "Arbre.hh"
#include "ArbIOint.hh"

int main ()
{
	Arbre<int> treeinp, treeout;
	llegir_arbre_int (treeinp, 0);
	treeinp.sub_arrel(treeout, 10);
	escriure_arbre_int (treeout);
	// d = -4 6 -1 0 0 3 0 0 -2 8 0 0 0 
	// a = 7 6 -2 0 0 -3 0 0 -2 -1 0 0 3 0 0
	// b = 4 9 -1 0 0 3 0 0 6 8 0 0 -3 1 0 0 0
	// c = 10 -1 -2 0 0 0 -2 -1 0 0 3 0 0
}