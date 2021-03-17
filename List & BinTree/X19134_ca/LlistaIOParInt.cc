#include "LlistaIOParInt.hh"

using namespace std;

void LlegirLlistaParInt(list<ParInt>& l)
{
    ParInt myParInt;
    myParInt.llegir();

    if(myParInt.primer() != 0 and myParInt.segon() != 0) l.push_back(myParInt);

    for (list<ParInt>::iterator it = l.begin(); myParInt.primer() != 0 and myParInt.segon() != 0; --it)
    {
        myParInt.llegir();
        l.insert(it, myParInt);
    }
}