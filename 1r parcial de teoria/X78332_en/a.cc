#include <iostream>
#include "BinTree.hh"
#include <stack>

using namespace std;

/* Pre: c is empty */
/* Post: c contains the preferential path of a; if it is non-empty, the
         first element of the path is on the top of c */
void cami_preferent(const BinTree<int>& a, stack<int>& c)
{
    stack<BinTree<int>> steps; steps.push(a);
    BinTree<int> myTreeRight = a.right(), myTreeLeft = a.left();




}

void recursive_DFS();