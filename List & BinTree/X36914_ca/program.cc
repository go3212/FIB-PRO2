#include <iostream>
#include <list>
#include "Estudiant.hh"
#include "LlistaIOEstudiant.hh"

using namespace std;

int main ()
{
    list<Estudiant> myList;
    LlegirLlistaEstudiant(myList);
    int n, occurences = 0; cin >> n;

    for (list<Estudiant>::iterator it = myList.begin(); it != myList.end(); ++it)
    {
        if ((*it).consultar_DNI() == n) ++occurences;
    }

    cout << n << ' ' << occurences << endl;
}