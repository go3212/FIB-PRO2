#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct book
{   
    string name;
    int category;
};

int main ()
{
    int stacks; cin >> stacks;
    vector<stack<string>> mystacks(stacks);


    int opcion;
    book mybook;
    int n1, n2;
    while (cin >> opcion)
    {
        if (opcion == -4) break;
        switch (opcion)
        {
            case -1:
                cin >> mybook.name >> mybook.category;
                mystacks[mybook.category - 1].push(mybook.name);
                break;
            case -2:
                cin >> n2 >> n1;
                for (int i = 0; i < n2; ++i) mystacks[n1 - 1].pop();
                break;
            case -3:
                cin >> n1;
                cout << "Pila de la categoria " << n1 << endl;
                for (stack<string> dumpstack = mystacks[n1 - 1]; !dumpstack.empty(); dumpstack.pop())
                {
                    cout << dumpstack.top() << endl;
                }
                cout << endl;
                break;
        }
    }
}