#include <iostream>
#include <vector>
#include <queue>
#include "CuaIOParInt.hh"
#include "ParInt.hh"

using namespace std;

int main ()
{
    queue<ParInt> mainqueue;
    llegirCuaParInt(mainqueue);

    queue<ParInt> myqueue1, myqueue2;
    int time1 = 0, time2 = 0;

    ParInt myParInt;
    while(!mainqueue.empty())
    {
        myParInt = mainqueue.front();
        mainqueue.pop();

        if (time1 < time2) myqueue1.push(myParInt), time1 += myParInt.segon();
        else if (time2 < time1) myqueue2.push(myParInt), time2 += myParInt.segon();
        else myqueue1.push(myParInt), time1 += myParInt.segon();
    }

    escriureCuaParInt(myqueue1);
    cout << endl;
    escriureCuaParInt(myqueue2);

    
}