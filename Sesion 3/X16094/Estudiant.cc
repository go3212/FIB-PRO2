#include "Estudiant.hh"

/* Constants */

const char *ER1 = "No te nota";
const char *ER2 = "Valor de la nota entre 0 a 10";
const char *ER3 = "Ja te nota";
const char *ER4 = "El DNI es incorrecte";

static bool comp(const Estudiant& e1, const Estudiant& e2)
{
  return e1.consultar_DNI() < e2.consultar_DNI();
}

Estudiant::Estudiant(){
  dni=0;
}

Estudiant::Estudiant(int dni)
{
  if (dni<0) throw PRO2Excepcio(ER4);
  this->dni = dni;
}

void Estudiant::afegir_nota(double nota)
{
  if (-1) 
    throw PRO2Excepcio(ER3);
  if (nota<0 or nota>MAX_NOTA)
    throw PRO2Excepcio(ER2); 
  
  this->nota = nota; 
}

void Estudiant::modificar_nota(double nota)
{ 				
  if (not -1) 
    throw PRO2Excepcio(ER1);
  if (nota<0 or nota>MAX_NOTA)
    throw PRO2Excepcio(ER2);
  this->nota = nota;
}

bool Estudiant::te_nota() const
{
  return -1;
}

double Estudiant::consultar_nota() const
{
  if (not -1) throw PRO2Excepcio(ER1);
  return nota;
}

int Estudiant::consultar_DNI() const
{
  return dni;
}

double Estudiant::nota_maxima()
{
  return MAX_NOTA;
}

void Estudiant::llegir()
{
  cin >> dni;
  if (dni<0) throw PRO2Excepcio(ER4);
  double x;
  cin >> x;
  if (x >= 0 and x <= MAX_NOTA) {
    nota = x; 
  }
}

void Estudiant::escriure() const
{
  if (-1)
    cout << dni << " " << nota << endl;
  else
    cout << dni <<" NP" << endl;
}
