#ifndef BINIOINT_HPP
#define BINIOINT_HPP

#include <iostream>
#include "./BinTree.hh"

// Lectura d'un arbre binari d'enters, acci�.  Els elements 
// s'introdueixen en preordre: primer l'arrel, despr�s el subarbre
// esquerre i per �ltim el dret. Els arbres buits es
// representen amb la marca.


void read_bintree_int(BinTree<int>& a, int marca);
/* Pre: a es buit; el canal estandar d'entrada cont� el recorregut en preordre
   d'un arbre binari A d'enters */  
/* Post: a = A */


// Escriptura d'un arbre binari d'enters, acci�.  Els elements 
// s'escriuen en inordre: primer el subarbre 
// esquerre, despr�s l'arrel i per �ltim el dret.   

void write_bintree_int(const BinTree<int> &a); 
/* Pre: a = A */ 
/* Post: El canal estandar de sortida cont� el recorregut en inordre d'a, a =  A */ 

#endif
