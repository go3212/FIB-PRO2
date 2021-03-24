#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main ()
{
    map<string, int> myMap;

    char operation; string key;
    while (cin >> operation >> key)
    {
        if (myMap.find(key) == myMap.end()) myMap[key] = 0;
        switch (operation)
        {
            case 'a':
                // Revisamos si existe la key, si no existe, creamos una con freq 1
                myMap[key] += 1;
                break;
            case 'e':
                myMap[key] -= 1;
                if (myMap[key] < 0) myMap[key] = 0; 
                break;
            
            case 'f':
                cout << myMap[key] << endl;
                break;
        }
    }
}