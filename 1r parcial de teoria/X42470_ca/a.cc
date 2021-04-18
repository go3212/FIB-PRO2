#include "BinTree.hh"
#include <iostream>
using namespace std;

int mida(const BinTree<int>& a, BinTree<int>& sizeTree) {
    if (a.empty()) return 0;
    BinTree<int> sizeTreeL, sizeTreeR;
    int mida1 = mida(a.left(), sizeTreeL);
    int mida2 = mida(a.right(), sizeTreeR);
    sizeTree = BinTree<int>(mida1-mida2, sizeTreeL, sizeTreeR);
    return 1 + mida1*(mida1>= mida2) + mida2*(mida2 > mida1);
}

 /* Pre: a=A */
 /* Post: agd es un arbre amb la mateixa estructura que A on cada
    node conte el grau de desequilibri del subarbre d'A corresponent */
void arbre_graus_desequilibri(const BinTree<int> &a, BinTree<int> &agd) {
    mida(a, agd);
}

/*
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
   BinTree<int> myTree;
   BinTree<int> agd;
   read_bintree_int(myTree, 0);
   arbre_graus_desequilibri(myTree, agd);
   write_bintree_int(agd);
}
*/