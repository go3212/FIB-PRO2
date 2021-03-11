#include "CuaIOParInt.hh"

void llegirCuaParInt(queue<ParInt>& c)
{
    ParInt myParInt;
    while(myParInt.llegir())
    {
        c.push(myParInt);
    }
}

void escriureCuaParInt(queue<ParInt> c)
{
    ParInt myParInt;
    while(!c.empty())
    {
        myParInt = c.front();
        myParInt.escriure();
        c.pop();
    }
}
