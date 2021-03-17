#include <iostream>
#include <list>

using namespace std;

/* Pre: uno = U */
/* Post: uno pasa a ser la interseccion de U y dos */
void inter (list<int>& uno, const list<int>& dos )
{
    list<int>::iterator unoIter = uno.begin();
    list<int>::const_iterator dosIter = dos.begin();

    while (dosIter != dos.end() and unoIter != uno.end())
    {
        if (*unoIter < *dosIter) unoIter = uno.erase(unoIter);
        else if (*unoIter > *dosIter) ++dosIter;
        else ++unoIter, ++dosIter;
    }
    while (unoIter != uno.end()) unoIter = uno.erase(unoIter);
}

void createList(list<int> &myList)
{
    int n;
    
    int elem; cin >> elem;
    for (int i = 0; i < elem; ++i)
    {
        cin >> n;
        myList.push_back(n);
    }
}

void printList(const list<int> &myList)
{
    list<int>::const_iterator myIterator = myList.begin();
    while (myIterator != myList.end())
    {
        cout << (*myIterator) << " ";
        ++myIterator;
    }
    cout << endl;

}

int main ()
{
    list<int> uno;
    list<int> dos;

    createList(uno);
    createList(dos);

    inter (uno, dos);

    printList(uno);
}