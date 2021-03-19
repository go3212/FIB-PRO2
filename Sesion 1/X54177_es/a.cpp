#include <iostream>
#include <string>

using namespace std;

int main ()
{
    int n; cin >> n;
    int x; cin >> x;

    int i = 1;
    while (n != 0)
    {   
        int sum = 0;

        int number;
        cin >> number;
        while (number != x)
        {
            sum += number;
            cin >> number;
        }        

        cout << "La suma de la secuencia " << i << " es " << sum  << endl;

        string buffer;
        getline(cin, buffer);
        --n;
        ++i;
    }

}