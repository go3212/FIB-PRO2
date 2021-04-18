#include <iostream>
#include "../X42470_ca/BinTree.hh"

using namespace std;

int check_diffs (const BinTree<int> &a, const BinTree<int> &b)
{
    int diffs = 0;
    if (a.empty() && b.empty()) diffs = 0;
    else if (!a.empty() && !b.empty())
    {
        int left_diffs = check_diffs (a.left(), b.left());
        int right_diffs = check_diffs (a.right(), b.right());
        diffs = left_diffs + right_diffs;
    } 
    else 
    {
        ++diffs;
        BinTree<int> right, left;
        if (!a.empty()) right = a.right(), left = a.left();
        if (!b.empty()) right = b.right(), left = b.left();
        diffs += !right.empty() + !left.empty();
    }

    return diffs;

}

/* Pre: cert */
/* Post: el resultat indica si a i b son quasi coincidents */
bool quasi_coincidents (const BinTree<int> &a, const BinTree<int> &b)
{
    int diff = check_diffs (a, b);
    //cout << diff << endl;
    return (diff <= 1);

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
    // a: 7 6 -2 0 0 -3 0 0 -2 -1 0 0 3 0 0
    // b: 4 9 -1 0 0 3 0 0 6 8 0 0 -3 1 0 0 0
    // c: 10 -1 -2 0 0 0 -2 -1 0 0 3 0 0
    // d: -4 6 -1 0 0 3 0 0 -2 8 0 0 0
    BinTree<int> myTree1;
    BinTree<int> myTree2;
    read_bintree_int(myTree1, 0);
    read_bintree_int(myTree2, 0);
    cout << quasi_coincidents(myTree1, myTree2) << endl;
}