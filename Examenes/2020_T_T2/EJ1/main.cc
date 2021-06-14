#include <iostream>
#include "Llista.hh"
#include "LlistaIOint.hh"

int main ()
{
	Llista<int> l;
	llegir_llista_int(l, 0);
	//l.elim_repes_cons();
	l.marca_canvis_signe();
	escriure_llista_int(l);
}
