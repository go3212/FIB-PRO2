#include "BinTreeIOParInt.hh"

using namespace std;

void read_bintree_parint(BinTree<ParInt>& a)
{
    // Podemos aproximar la solucion de manera recursiva.
    ParInt node_data;
    if (node_data.llegir())
    {
        BinTree<ParInt> node_left;
        BinTree<ParInt> node_right;
        read_bintree_parint(node_left);
        read_bintree_parint(node_right);
        a = BinTree<ParInt> (node_data, node_left, node_right);
    }
}

//void write_bintree_parint(const BinTree<ParInt>& a)
//{
//
//}