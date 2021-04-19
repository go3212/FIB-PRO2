#include <iostream>
#include <vector>

using namespace std;


void swap (vector<int>& v, int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void printvec(vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}


void reordena (vector<int>& v, int& a, int& b)
{
    a = 0;
    b = 0;
    int c = 1;
    while(c < v.size())
    {
        if(v[c] < 0)
        {   
            int a = c;
            while (a > 0 && v[a-1] >= 0) swap(v, a-1, a), --a;

            cout << "<0: "; printvec (v);

            c++;
        }
        else if (v[c] == 0)
        {
            int b = c;
            while (b > 0 and (v[b-1] > 0) and b < v.size())
            {
                swap(v, b-1, b), --b;
            }

            cout << "==0: "; printvec (v);
            c++;
        } else
        {
            if (v[c-1] < 0 and v[c] == 0) a = c;
            if (v[c-1] == 0 and v[c] >= 0) b = c;
            c++;
        }
    }   
}



int main ()
{
    int a, b;
    vector<int> v = {2, 4, -2, 0, -7, 2, -2, 2, 4, -5, 1 };
    reordena(v, a, b);
    cout << a << ' ' << b << endl;
    printvec(v);
}