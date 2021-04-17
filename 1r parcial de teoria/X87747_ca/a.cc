#include <iostream>
#include <vector>

using namespace std;

/** \pre v.size() > 0
 *  \post el resultado es el numero de solitarios en v.
 */
int solitaris(const vector<int>& v)
{
    // Inv: el último elemento es solitario si, y solo si, el anterior es diferente de el, forall size >= 1
    int solitarios = 0;
    int i = 0; int size = v.size();

    bool next_neq, prev_neq = true;
    while (i < size - 1)
    {   
        next_neq = v[i] != v[i+1];
        solitarios += next_neq*prev_neq;
        prev_neq = next_neq;
        ++i;
    }
    solitarios += prev_neq;
    return solitarios;
}

int main ()
{
    vector<int> vect = {-7,5,5,5,-2,2,5,1,1}; 
    cout << solitaris(vect);
}