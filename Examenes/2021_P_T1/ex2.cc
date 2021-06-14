#include <iostream>
#include <list>

using namespace std;

void insertarcada (list<int>& l1, list<int>& l2, int k)
{
    list<int>::iterator it = l1.begin();
    while(!l2.empty())
    {
        for(int j = 0; j < k; ++j) ++it;
        l1.insert(it, *(l2.begin()));
        l2.erase(l2.begin());
    }
}

int main ()
{
    list<int> l1;
    l1.push_back(0);
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);

    list<int> l2;
    l2.push_back(-1);
    l2.push_back(-2);

    insertarcada(l1, l2, 1);

    list<int>::iterator it = l1.begin();
    for(int i = 0; i < l1.size(); ++i)
    {
        cout << *it << ' ';
        ++it;
    }
    cout << endl;
}