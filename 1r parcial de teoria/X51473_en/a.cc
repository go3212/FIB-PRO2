#include <iostream>
#include <list>

using namespace std;

/* Pre: l is not empty, sol is empty */
/* Post: sel is the result of extracting from l the elements weak on average */
void seleccio(const list<double>& l, list<double>& sel)
{
    list<double>::const_iterator myIter = l.begin();
    list<double>::const_iterator myIterEnd = l.end();

    double sum = (*myIter), elements = 1;
    sel.push_back(*myIter); ++myIter;
    while(myIter != myIterEnd)
    {
        if(*myIter >= sum/elements) sel.push_back(*myIter);
        sum += *myIter;
        elements += 1;
        ++myIter;
    }

}