#ifndef ARBREN_HH
#define ARBREN_HH

#include "utils.PRO2"
#include <vector>

template <class T> class ArbreNari { 
  private:     
    struct node {
        T info;
        vector<node*> fill;
    };
    int N;
    node* arrel;
	
   // especificació operacions privades
 
static node* copia_node(node* m) { 
/* Pre: cert */
/* Post: el resultat és NULL si m és NULL; en cas contrari, el resultat apunta
         al node arrel d'una jerarquia de nodes que és una còpia de la 
         jerarquia de nodes que té el node apuntat per m com a arrel */
  node* n;
  if (m == NULL) n = NULL;
  else {
    n = new node;
    n->info = m->info;
    int ari = m->fill.size();
    n->fill = vector<node*>(ari);
    for (int i = 0; i < ari; ++i) 
      n->fill[i] = copia_node(m->fill[i]);
  }
  return n;
}

static void esborra_node(node* m) {  
/* Pre: cert */
/* Post no fa res si m és NULL; en cas contrari, allibera espai de tots els nodes
        de la jerarquia que té el node apuntat per m com a arrel */
  if (m != NULL) {
    int ari = m->fill.size();
    for (int i = 0; i < ari; ++i) 
      esborra_node(m->fill[i]);
    delete m;
  }
}

  public:
    // especificació operacions públiques

ArbreNari(int n) {
/* Pre: cert */
/* Post: el p.i. és un arbre buit d'aritat n */
  N = n;
  arrel= NULL;
}

ArbreNari(const T &x, int n) {
/* Pre: cert */
/* Post: el p.i. és un arbre amb arrel x i n fills buits */
  N = n;
  arrel= new node;
  arrel->info = x;
  arrel->fill = vector<node*>(N);
  for (int i=0; i<N; ++i) 
    arrel->fill[i] = NULL;
}

ArbreNari(const ArbreNari& original) {
/* Pre: cert */
/* Post: el p.i. és una còpia d'original */
  N = original.N;
  arrel = copia_node(original.arrel);
}

~ArbreNari() 
// Destructora: Esborra automàticament els objectes locals en
// sortir d'un àmbit de visibilitat
{
  esborra_node(arrel);
}

ArbreNari& operator=(const ArbreNari& original) 
/* Pre: cert */
/* Post: El p.i. passa a ser una còpia d'original i qualsevol
     contingut anterior del p.i. ha estat esborrat 
     (excepte si el p.i. i original ja eren el mateix objecte) */
{
  if (this != &original) {
    esborra_node(arrel);
    N = original.N;
    arrel = copia_node(original.arrel);
  }
  return *this;
}

void a_buit() {
/* Pre: cert */
/* Post: el p.i. és un arbre buit */
  esborra_node(arrel);
  arrel= NULL;
}        

void plantar(const T &x, vector<ArbreNari> &v) {
/* Pre:  el p.i. és buit i la longitud de v és igual a l'aritat del p.i.*/
/* Post: el p.i. té x com a arrel i els N elements originals  
         de v com a fills, v passa a contenir arbres buits */
  if (arrel==NULL){
    if (v.size()==N){ 
      node* aux= new node;
      aux->info= x;
      aux->fill = vector<node*>(N);
      for (int i=0; i<N; ++i) {
	aux->fill[i] = v[i].arrel;
	v[i].arrel = NULL;
      }
      arrel = aux;
    }
    else throw PRO2Excepcio("Al plantar, el size del vector ha de ser igual a l'aritat de l'arbre");
  }
  else throw PRO2Excepcio("El p.i. de plantar ha de ser buit a la crida");
}


void fills(vector<ArbreNari> &v) {
/* Pre:  el p.i. no és buit i li diem A, v és un arbre buit */
/* Post: el p.i. és buit, v passa a contenir els N fills de l'arbre A  */
  if (arrel!=NULL){
    if (v.size()==0){ 
      node* aux= arrel;
      v= vector<ArbreNari> (N,ArbreNari(N));
      for (int i=0; i<N; ++i) 
	v[i].arrel = aux->fill[i];  
      arrel= NULL;
      delete aux;
    }
    else throw PRO2Excepcio("No es pot passar a fills un vector no buit");
  }
  else throw PRO2Excepcio("El p.i. de fills no pot ser buit a la crida");
}

T _arrel() const {
/* Pre: el p.i. no és buit */
/* Post: el resultat és l'arrel del p.i. */
  if (arrel != NULL)   return arrel->info;
  else throw PRO2Excepcio("El p.i. d'arrel no pot ser buit a la crida");
}

bool es_buit() const {
/* Pre: cert */
/* Post: el resultat indica si el p.i. és un arbre buit */
    return (arrel == NULL);
}

int aritat() const {
/* Pre: cert */
/* Post: el resultat és l'aritat del p.i. */
    return N;
}

//
// extension
//
#include "program.hh"

};

#endif
