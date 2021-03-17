#include <iostream>
#include <list>
#include "Estudiant.hh"
#include "LlistaIOEstudiant.hh"
#include "solution.hh"

int main() {
  list<Estudiant> t; 
  LlegirLlistaEstudiant(t); 
 
  int x;
  cin >> x;
 
  esborra_tots(t,x); 
  EscriureLlistaEstudiant(t);
}
  
