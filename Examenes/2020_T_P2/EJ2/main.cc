#include <iostream>
#include "Arbre.hh"
#include "ArbIOint.hh"

int main ()
{
	Arbre<int> treeinp;
	llegir_arbre_int(treeinp, -1);
	std::cout << treeinp.frontisses();
	// 13 -4 1 -1 1 -1 -1 -1 10 0 -1 -1 -7 3 2 -1 -1 5 -1 -1 -2 -1 -1
}