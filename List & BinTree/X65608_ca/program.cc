#include <iostream>
#include "Estudiant.hh"
#include "BinTree.hh"
#include "BinTreeIOEst.hh"

using namespace std;

struct StudentData
{
    Estudiant student;
    int depth;
    bool found;

    StudentData(int dni)
    {
        depth = 0, found = false;
        student = Estudiant(dni);
    }
};

void getStudentData(const BinTree<Estudiant> &myTree, StudentData &myData, StudentData &myDataTemp)
{
    if (myTree.empty()) 
    {
        myData.found = false, myData.depth = -1;
        return void();
    }

    // Cargamos los punteros a los nodos izq y der
    // Inv: siempre existira un puntero a otro nodo (puede ser nullptr)
    BinTree<Estudiant> myTreeLeft = myTree.left();
    BinTree<Estudiant> myTreeRight = myTree.right();

    // Busqueda recursiva. Final: encontramos estudiante. 
    // Inv: myTree nunca es vacio.
    if ((myTree.value()).consultar_DNI() == myData.student.consultar_DNI())
    {
        myDataTemp.student = myTree.value();
        if (!myData.found) myData = myDataTemp;
        else if (myData.depth > myDataTemp.depth) myData = myDataTemp;

        myData.found = true;
        return void();
    }

    // Para satisfacer el Inv, no podemos acceder a contenidos de arboles vacios
    if (!myTreeLeft.empty()) ++myDataTemp.depth, getStudentData(myTreeLeft, myData, myDataTemp), --myDataTemp.depth;
    if (!myTreeRight.empty()) ++myDataTemp.depth, getStudentData(myTreeRight, myData, myDataTemp), --myDataTemp.depth;
    
}

int main ()
{
    BinTree<Estudiant> myTree;
    read_bintree_est(myTree);

    int dni;

    if (myTree.empty())
    {
        while (cin >> dni)
        {
            cout << dni << " " << -1;
            cout << endl;
        }
    }

    while (cin >> dni)
    {
        StudentData myData(dni);
        StudentData myDataTemp(dni);
        getStudentData(myTree, myData, myDataTemp);

        if (myData.found and myData.student.te_nota()) 
            cout << myData.student.consultar_DNI() << " " << myData.depth << " " << myData.student.consultar_nota();
        else if (myData.found) cout << myData.student.consultar_DNI() << " " << myData.depth << " " << -1;
        else cout << myData.student.consultar_DNI() << " " << -1;
        cout << endl;
    }
}