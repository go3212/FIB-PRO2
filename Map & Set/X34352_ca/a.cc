#include <iostream>
#include <map>
#include <string>

using namespace std;

int main ()
{
    map<string, int> myMap;

    char operation; string key;
    while (cin >> operation >> key)
    {
        switch (operation)
        {
            case 'a':
                // Revisamos si existe la key, si no existe, creamos una con freq 1
                if (myMap.find(key) == myMap.end()) 
                {
                    myMap[key] = 1;
                    break;
                }
                myMap[key] += 1;
                break;
            case 'f':  
                if (myMap.find(key) == myMap.end()) cout << 0;
                else cout << myMap[key];
                cout << endl;
                break;
        }
    }
}