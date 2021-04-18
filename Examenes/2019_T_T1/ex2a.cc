#include <iostream>
#include "BinTree.hh"
#include "BinTreeIOint.hh"

using namespace std;

// Pre: tots els elements d'a són 0s o 1s
// Post: zeros = nombre de 0s que conté l'arbre a,
// uns = nombre d'1s que conté l'arbre a
void freq_zeros_uns(const BinTree<int>& a, int& zeros, int& uns)
{
    if (a.empty()) return void();

    zeros += (a.value() == 0);
    uns += (a.value() == 1);

    freq_zeros_uns (a.left(), zeros, uns);
    freq_zeros_uns(a.right(), zeros, uns);
}

int main ()
{
    // a: 0 1 0 2 0 2 2 2 0 1 2 2 0 0 0 2 2 1 2 2 0 2 2
    BinTree<int> myTree;
    read_bintree_int(myTree, 2);
    int zeros = 0, uns = 0;
    freq_zeros_uns(myTree, zeros, uns);
    cout << "Zeros: " << zeros << "  Uns: " << uns << endl;
}