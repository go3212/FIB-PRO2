#include <iostream>
#include <vector>
#include "Estudiant.hh"

using namespace std;

pair<int,int> max_min_vest(const vector<Estudiant>& v)
{
    if (v.empty()) return make_pair(-1, -1);

    int posmax, posmin;
    posmax = posmin = 0;
    
    // Buscamos el primer estudiante con nota
    if (!v[posmax].te_nota())
    {
        int i;
        for (i = 1; i < v.size() and !v[i].te_nota(); ++i);
        if (i < v.size()) posmax = posmin = i;
        else return make_pair(-1, -1);
    }

    // Inv: almenos el vector es size >= 1
    //      almenos hay 1 estudiante con nota
    for (int i = posmax += 1; i < v.size(); ++i)
    {
        // Solo nos interesan los estudiantes con nota máx
        if (v[i].te_nota())
        {
            if(v[posmax].consultar_nota() < v[i].consultar_nota()) posmax = i;
            else if (v[posmax].consultar_nota() == v[i].consultar_nota())
            {
                if (v[posmax].consultar_DNI() > v[i].consultar_DNI()) posmax = i;
            }
            if(v[posmin].consultar_nota() > v[i].consultar_nota()) posmin = i;
            else if (v[posmin].consultar_nota() == v[i].consultar_nota())
            {
                if (v[posmin].consultar_DNI() > v[i].consultar_DNI()) posmin = i;
            }
        }
    }

    return make_pair(posmax, posmin);
}
