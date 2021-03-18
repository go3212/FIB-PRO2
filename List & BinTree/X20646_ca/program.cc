#include <iostream>
#include "ParInt.hh"
#include "BinTree.hh"
#include "BinTreeIOParInt.hh"

using namespace std;

struct nodeData
{
    int first, second;
    int depth;
    bool found;
    nodeData(int number)
    {
        depth = 0;
        found = false;
        first = number;
    } 
};

void getNodeData (const BinTree<ParInt> &myTree, nodeData &node)
{
    BinTree<ParInt> myTreeLeft = myTree.left();
    BinTree<ParInt> myTreeRigth = myTree.right();

    if ((myTree.value()).primer() == node.first) 
    {
        node.found = true;
        node.depth = 0;
        node.second = (myTree.value()).segon();
        return void();
    }
    if (!myTreeLeft.empty() and !node.found) getNodeData(myTreeLeft, node);
    if (!myTreeRigth.empty() and !node.found) getNodeData(myTreeRigth, node);

    if (node.found) 
    {
        node.depth += 1;
    } else node.depth = -1;
    
}

int main ()
{
    // Leemos el arbol y lo guardamos
    BinTree<ParInt> myTree;
    read_bintree_parint(myTree);

    // Buscamos los nodos hasta que no quede nada mas por buscar
    // Podemos hacer un algoritmo recursivo para ello
    int n;
    while (cin >> n)
    {
        nodeData node(n);
        getNodeData (myTree, node); 
        if (node.found) cout << node.first << " " << node.second << " " << node.depth << endl;
        else cout << -1 << endl;
    }
}