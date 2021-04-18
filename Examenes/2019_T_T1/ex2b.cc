#include <iostream>
#include "BinTree.hh"
#include "BinTreeIOint.hh"
#include <vector>

using namespace std;

// Pre: tots els elements d'a són 0s o 1s
// Post: zeros = nombre de 0s que conté l'arbre a,
// uns = nombre d'1s que conté l'arbre a
void frequency(const BinTree<int>& a, vector<int>& freq)
{
    if (a.empty()) return void();

    ++freq[a.value()];

    frequency (a.left(), freq);
    frequency(a.right(), freq);
}

int main ()
{
    // a: 7 4 2 10 3 10 10 10 2 3 10 10 4 5 6 10 10 7 10 10 2 10 10
    BinTree<int> myTree;
    read_bintree_int(myTree, 10);
    vector<int> freq(10, 0);
    frequency(myTree, freq);
    cout << "Zeros: " << freq[0] << endl;
    cout << "Unos: " << freq[1] << endl;
    cout << "Doses: " << freq[2] << endl;
    cout << "Treses: " << freq[3] << endl;
    cout << "Cuatros: " << freq[4] << endl;
    cout << "Cincos: " << freq[5] << endl;
    cout << "Seises: " << freq[6] << endl;
    cout << "Sietes: " << freq[7] << endl;
    cout << "Ochos: " << freq[8] << endl;
    cout << "Nueves: " << freq[9] << endl;

}