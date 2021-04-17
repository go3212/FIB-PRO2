#include <iostream>
#include <vector>

using namespace std;

/* Pre: cert */
/* Post: el resultat es el nombre d'elements frontissa de v */
int comptatge_frontisses(const vector<int> &v)
{
    // Inv: es frontissa si la diff de la suma total - v[i+1, i+2...] - la de los predecesores es v[i].
    int i = 0, size = v.size(), totalSum = 0;
    for (i = 0; i < size; ++i) totalSum += v[i];

    int frontisas = 0, diff = 0;
    i = 0;
    while (i < size)
    {
        totalSum -= v[i];
        frontisas += (v[i] == (totalSum - diff));
        diff += v[i];
        ++i;
    }
    return frontisas;
}

/*
int main ()
{
    vector<int> vect = {3,12,5,2,2,9,4,1,-3,9}; // 1
    //vector<int> vect = {3,0,-5,2,2}; // 0
    cout << comptatge_frontisses(vect);   
}
*/