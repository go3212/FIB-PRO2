#include <iostream>
#include <vector>

using namespace std;


void swap (vector<int>& v, int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void reordena (vector<int>& v, int& a, int& b)
{
    a = 0;
    b = 0;
    int c = 0;
    while(c < v.size())
    {
        if(v[c] < 0)
        {   
            int i = c;
            while (i > 0 && v[i-1] >= 0) swap(v, i-1, i), --i;
            if (v[i] < 0) a = i + 1;
            else a = i;
            if(v[i+1] == 0) b = i+1;
            c++;
        }
        else if (v[c] == 0)
        {
            int i = c;
            while (i > 0 and (v[i-1] > 0) and i < v.size())
            {
                swap(v, i-1, i), --i;
            }
            b = i;
            c++;
        } else
        {
            int i = c;

        }
    }   
}

int main ()
{
    int a, b;
    vector<int> v = {2, 4, -2, 0, -7, 2, -2, 2, 4, -5, 1 };
    reordena(v, a, b);
    cout << a << ' ' << b << endl;
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}