#include <iostream>
#include <set>
#include <string>

using namespace std;

int main ()
{
    // Primero guardamos todos los "alumnos" en un set, 
    set<string> mySet;

    string key;
    while (cin >> key and key != ".") mySet.insert(key);   

    // Sabiendo el número de actividades, podemos usar un mapa para almacenar n act x alumno
    set<string> noActSet = mySet;
    set<string> allActSet = mySet;

    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        set<string> tempSet;
        set<string>::iterator it;
        while (cin >> key and key != ".")
        {
            noActSet.erase(key);
            tempSet.insert(key);
        }
        for (it = allActSet.begin(); it != allActSet.end(); it = it)
        {
            if (tempSet.find(*it) == tempSet.end()) 
            {
                it = allActSet.erase(it);
            } else ++it;
        }
    }

    cout << "Totes les activitats:";
    for (set<string>::iterator it = allActSet.begin(); it != allActSet.end(); ++it)
    {
        cout << " " << *it;
    }
    cout << endl;
    cout << "Cap activitat:";
    for (set<string>::iterator it = noActSet.begin(); it != noActSet.end(); ++it)
    {
        cout << " " << *it;
    }
    cout << endl;

}