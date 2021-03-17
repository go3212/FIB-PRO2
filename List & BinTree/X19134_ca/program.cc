#include <iostream>
#include <list>
#include "LlistaIOParInt.hh"
#include "ParInt.hh"

using namespace std;

int main ()
{
    list<ParInt> myList;
    LlegirLlistaParInt(myList);
    int n, sum = 0, occurences = 0; cin >> n;

    for (list<ParInt>::iterator it = myList.begin(); it != myList.end(); ++it)
    {
        if ((*it).primer() == n) ++occurences, sum += (*it).segon();
    }
    cout << n << " " << occurences << " " << sum << endl;
}
