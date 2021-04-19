#include <iostream>
#include <list>
#include "BinTree.hh"

struct codificacio {
    string s;
    string codi; 
};

void obtenir_codis ( const BinTree < string >& T , list < codificacio >& C );