
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main ()
{
    // Primero guardamos todos los "alumnos" en un set, 
    set<string> noActSet;
    set<string> allActSet;

    string key;
    while (cin >> key and key != ".") noActSet.insert(noActSet.end(), key), allActSet.insert(allActSet.end(), key);
    // Sabiendo el número de actividades, podemos usar un mapa para almacenar n act x alumno

    set<string>::iterator it1 = allActSet.begin();
    set<string>::iterator it2;
    set<string>::iterator it3;
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        it1 = allActSet.begin();
        it3 = noActSet.begin();
        while (cin >> key and key != ".")
        {   
            it3 = noActSet.erase(it3);

            it2 = allActSet.find(key);
            if (it2 != allActSet.end())
            {
                if (*it1 != *it2) it1 = allActSet.erase(it1, it2);
                ++it1;
            }
        }
        allActSet.erase(it1, allActSet.end());
    }

    cout << "Totes les activitats:";
    for (it1 = allActSet.begin(); it1 != allActSet.end(); ++it1)
    {
        cout << " " << *it1;
    }
    cout << endl;
    cout << "Cap activitat:";
    for (it1 = noActSet.begin(); it1 != noActSet.end(); ++it1)
    {
        cout << " " << *it1;
    }
    cout << endl;

}