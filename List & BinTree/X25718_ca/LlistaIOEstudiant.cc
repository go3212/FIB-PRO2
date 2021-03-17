#include "LlistaIOEstudiant.hh"

using namespace std;

void LlegirLlistaEstudiant(list<Estudiant>& l)
{
    Estudiant myStudent;
    bool exitw = false;

    do
    {
        myStudent.llegir();
        if (!myStudent.te_nota()) l.push_back(myStudent);
        else if (myStudent.consultar_DNI() != 0 and myStudent.consultar_nota() != 0) l.push_back(myStudent);
        else exitw = true;
    } while (!exitw);
}


void EscriureLlistaEstudiant(list<Estudiant>& l)
{
    for (list<Estudiant>::iterator it = l.begin(); it != l.end(); ++it)
    {
        (*it).escriure();
    }
}
