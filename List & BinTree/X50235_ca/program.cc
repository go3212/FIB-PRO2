#include <iostream>
#include "BinTree.hh"
#include "BinTreeIOint.hh"

using namespace std;

bool poda_subarbre(BinTree<int> &a, int x)
{
    // Podemos implementar una solución recursiva. Donde el árbol se genera no accediendo al nodo que contiene
    // el nodo a elminar

    if (a.empty()) return false;
    if (a.value() == x) 
    {
        a = BinTree<int>();
        return true;
    }

    // Inv: a nunca será vacio
    BinTree<int> myTreeLeft = a.left();
    BinTree<int> myTreeRight = a.right();

    // En el momento que encontremos el subarbol a eliminar, acabamos el programa
    if (!myTreeLeft.empty())
    {
        if (poda_subarbre(myTreeLeft, x)) 
        {
            a = BinTree<int>(a.value(), myTreeLeft, myTreeRight);
            return true;
        }
    }

    if (!myTreeRight.empty())
    {
        if (poda_subarbre(myTreeRight, x)) 
        {
            a = BinTree<int>(a.value(), myTreeLeft, myTreeRight);
            return true;
        }
    }

    return false; 
}

int main() {
    cout << "Arbol binario (con el valor de 0 en los extremos):" << endl;
    BinTree<int> a;
    read_bintree_int(a, 0);
    
    cout << "¿Que nodo desea eliminar?" << endl;
    int x;
    cin >> x;
    cout << "Arbol original: ";
    write_bintree_int(a);
    cout << endl;
    cout << ((poda_subarbre(a, x)) ? "Borrado" : "No encontrado") << endl;
    cout << "Arbol reconstruido: ";
    write_bintree_int(a);
    cout << endl;
}
/* 
Arbol binario (con el valor de 0 en los extremos):
1 2 3 0 0 4 0 0 5 0 7 8 0 0 9 0 0
¿Que nodo desea eliminar?
2
Arbol original:  3 2 4 1 5 8 7 9
Borrado
Arbol reconstruido:  1 5 8 7 9
*/
