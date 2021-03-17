#include "LlistaIOEstudiant.hh"

using namespace std;

void LlegirLlistaEstudiant(list<Estudiant>& l)
{
    Estudiant myStudent;
    myStudent.llegir();

    while (myStudent.consultar_DNI() != 0 and myStudent.consultar_nota() != 0)
    {
        l.push_back(myStudent);
        myStudent.llegir();
    }
}
