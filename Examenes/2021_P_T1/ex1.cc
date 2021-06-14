#include <iostream>
#include "../2020_T_T1/BinTree.hh"

using namespace std;

int maxvalcamino(BinTree<int>& a)
{
    int v = a.value();
    BinTree<int> l = a.left(), r = a.right();
    int v_left = 0, v_right = 0;
    if (!l.empty()) v_left = maxvalcamino(l);
    if(!r.empty()) v_right = maxvalcamino(r);
    return v + max(v_left, v_right); 
}

void read_bintree_int(BinTree<int>& a,int marca)
{
  int x;
  cin >> x;
  if (x!=marca){
        BinTree<int> l;
        read_bintree_int(l,marca);
        BinTree<int> r;
        read_bintree_int(r,marca);
        a=BinTree<int>(x,l,r);
  }
}

int main ()
{
    //a: 1 2 3 10 10 2 10 10 4 0 10 10 0 10 10  -  6
    //b: 1 2 0 10 10 2 10 10 4 0 10 10 0 10 10  -  5
    //c: 1 2 0 10 10 2 10 10 4 0 10 10 1 10 10  -  6
    BinTree<int> myTree;
    read_bintree_int(myTree, 10);
    cout << maxvalcamino(myTree) << endl;
}