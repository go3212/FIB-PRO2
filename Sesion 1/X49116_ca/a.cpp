#include <vector>
using namespace std;

struct parint {int prim, seg;};

parint max_min1(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */
{
    parint result;
    result.prim = v[0];
    result.seg = v[0];

    int size = v.size();
    for (int i = 1; i < size; ++i)
    {
        if (result.prim < v[i]) result.prim = v[i];
        if (result.seg > v[i]) result.seg = v[i];
    }

    return result;
}

pair<int,int> max_min2(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
{
    pair<int, int> result;
    result.first = v[0];
    result.second = v[0];

    int size = v.size();
    for (int i = 1; i < size; ++i)
    {
        if (result.first < v[i]) result.first = v[i];
        if (result.second > v[i]) result.second = v[i];
    }

    return result;
}

void max_min3(const vector<int>& v, int& x, int& y)
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
    x = v[0];
    y = v[0];

    int size = v.size();
    for (int i = 1; i < size; ++i)
    {
        if (x < v[i]) x = v[i];
        if (y > v[i]) y = v[i];
    }
}