#include "BinTreeIOEst.hh"

using namespace std;

void read_bintree_est(BinTree<Estudiant>& a)
{
    // Podemos aproximar la solucion de manera recursiva.
    Estudiant myEstudiant;
    myEstudiant.llegir();
    if (myEstudiant.consultar_DNI() != 0)
    {
        BinTree<Estudiant> node_left;
        BinTree<Estudiant> node_right;
        read_bintree_est(node_left);
        read_bintree_est(node_right);
        a = BinTree<Estudiant> (myEstudiant, node_left, node_right);
    }
}
