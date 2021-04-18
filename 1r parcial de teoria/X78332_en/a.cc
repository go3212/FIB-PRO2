#include <iostream>
#include "BinTree.hh"
#include <stack>

using namespace std;


int elements(const BinTree<int>& a)
{
    int count = 0;
    if (a.empty()) return 0;

    count += elements(a.left());
    count += elements(a.right());

    return 1 + count;
}
/*
void longest_path (const BinTree<int>& a, stack<int>& path)
{
    if (a.empty()) return void;

    longest_path(a.left(), path);
    longest_path(a.right(), path);
}
*/
/* Pre: c is empty */
/* Post: c contains the preferential path of a; if it is non-empty, the
         first element of the path is on the top of c */
void cami_preferent(const BinTree<int>& a, stack<int>& c)
{
    if (a.empty()) return void();


    if (elements(a.left()) >= elements(a.right())) cami_preferent(a.left(), c);
    else cami_preferent(a.right(), c);
    c.push(a.value());
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

void write_bintree_int(const BinTree<int> &a)
{
        if (not a.empty()) {
                int x = a.value();
                write_bintree_int(a.left());
                cout << " " << x;
                write_bintree_int(a.right());
  }
}

int main ()
{
    // a: 7 6 -2 1 0 0 8 0 0 -3 0 -5 2 0 0 4 0 0 -2 -1 0 0 3 0 10 9 0 0 0
    BinTree<int> myTree;
    stack<int> path;
    read_bintree_int(myTree, 0);
    cami_preferent(myTree, path);
    while(!path.empty()) cout << path.top() << ' ', path.pop();
}
