#include <iostream>
#include <stack>

using namespace std;

int main ()
{
    stack<int> mystack;
    int k; cin >> k;
    int n;
    
    bool is_palindrome = true;

    for (int i = 0; i < (k/2); ++i) cin >> n, mystack.push(n);
    if (k%2 != 0) cin >> n;
    
    while (is_palindrome and !mystack.empty())
    {
        cin >> n; 
        if (n != mystack.top()) is_palindrome = false;
        mystack.pop();
    }   

    if (is_palindrome) cout << "SI" << endl;
    else cout << "NO" << endl;




}