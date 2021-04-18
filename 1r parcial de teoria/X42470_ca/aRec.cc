#include <iostream>
#include "BinTree.hh"
//#include "BinTreeIOint.hh"

using namespace std;

int calcular_altura(BinTree<int>& myTree)
{
   if (myTree.empty()) return 0;

   BinTree<int> myTreeLeft = myTree.left();
   BinTree<int> myTreeRight = myTree.right();

   int leftHeight = 1 + calcular_altura(myTreeLeft);
   int rightHeight = 1 + calcular_altura(myTreeRight);

   return leftHeight*(leftHeight >= rightHeight) + rightHeight*(rightHeight > leftHeight);
}

int calcular_grado_deseq (const BinTree<int>& myTree)
{
   if (myTree.empty()) return 0;

   BinTree<int> myTreeLeft = myTree.left();
   BinTree<int> myTreeRight = myTree.right();

   int rightHeight = calcular_altura(myTreeRight);
   int leftHeight = calcular_altura(myTreeLeft);

   return leftHeight - rightHeight;
}



/* Pre: a=A */
/* Post: agd es un arbre amb la mateixa estructura que A on cada
   node conte el grau de desequilibri del subarbre d'A corresponent */
void arbre_graus_desequilibri(const BinTree<int> &a, BinTree<int> &agd)
{
   if (!a.empty())
   {
      BinTree<int> myTreeLeft = a.left();
      BinTree<int> myTreeRight = a.right();
      BinTree<int> agdLeft;
      BinTree<int> agdRight;

      arbre_graus_desequilibri (myTreeLeft, agdLeft);
      arbre_graus_desequilibri (myTreeRight, agdRight);
      agd = BinTree<int>(diff, agdLeft, agdRight);
   }

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