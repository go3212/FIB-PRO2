#include <iostream>
#include <vector>
#include "Estudiant.hh"

using namespace std;

pair<int,int> max_min_vest(const vector<Estudiant>& v)
{
    // first = máx
    // second = min
    pair<int, int> nota = {-1, -1};
    
    int n = v.size();
    int i = 0;
    bool found;
    if (n > 0)
    {
        while (!v[i].te_nota() and i < n) ++i;
        if (v[i].te_nota() and i < n) nota = {i, i}; 
        else nota = {-1, -1};
    } else return {-1, -1};

    for (i = i + 1; i < n; ++i)
    {
        if (v[i].te_nota())
        {
            if (v[nota.first].consultar_nota() < v[i].consultar_nota()) nota.first = i; 
            else if (v[nota.second].consultar_nota() > v[i].consultar_nota()) nota.second = i;
            if (v[nota.second].consultar_nota() == v[i].consultar_nota() and v[nota.second].consultar_DNI() > v[i].consultar_DNI())
                nota.second = i;
            else if (v[nota.first].consultar_nota() == v[i].consultar_nota() and v[nota.first].consultar_DNI() > v[i].consultar_DNI())
                nota.first = i;
        }
    }
    return nota;
}
/*
// Redondear, version accion

void redondear_e_a(Estudiant& est)
{
  est.modificar_nota(((int) (10. * (est.consultar_nota() + 0.05))) / 10.0);
}

int main()
{
    int n; cin >> n;
    vector<Estudiant> estudiante(n);
    for (int i = 0; i < n; ++i)
    {
        estudiante[i].llegir();
        if (estudiante[i].te_nota()) { // comprobamos la precondicion
            redondear_e_a(estudiante[i]);    // version accion
        }
    }

    pair<int,int> res = max_min_vest(estudiante);
    cout << res.first << " " << res.second << endl;
}
*/
