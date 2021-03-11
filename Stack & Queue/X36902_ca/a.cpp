#include <iostream>
#include <stack>

using namespace std;

int main ()
{
    stack<char> mystack;

    char n; cin >> n;
    while (n != '.')
    {
        if (n == '(' or n == '[') mystack.push(n);
        else if (!mystack.empty() and ((mystack.top() == '(' and n == ')') 
            or (mystack.top() == '[' and n == ']')))
        {
            mystack.pop();
        } else mystack.push(n);
        cin >> n;
    }

    if (mystack.empty()) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;

}
