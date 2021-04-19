#include <iostream>
#include "BinTree.hh"
#include "BinTreeIOint.hh"

bool arbre01 ( const BinTree <int > & a )
{
    if (a.empty()) return true;
    BinTree<int> left = a.left(), right = a.right();

    if (!left.empty() && left.value() != !a.value()) return false;
    if (!right.empty() && right.value() != !a.value()) return false;

    arbre01(left);
    arbre01(right);

    return true;
}

int main ()
{
    // a: 1 0 1 0 2 2 0 1 2 2 2 1 2 0 2 2 0 1 0 2 2 0 2 2 2 true
    // b: 1 0 1 0 2 2 0 1 2 2 2 1 2 0 2 2 1 0 1 2 2 1 2 2 2 false
    BinTree<int> myTree;
    read_bintree_int(myTree, 2);
    cout << arbre01(myTree) << endl;
}