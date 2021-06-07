#include <iostream>
#include "Pila.hh"

/* Pre: cert */
/* Post: si m és NULL, el resultat és NULL; en cas contrari, el
   resultat apunta al primer node d'una cadena de nodes que són
   còpia de de la cadena que té el node apuntat per m com a primer */
node_pila* copia_node_pila_it(node_pila* m) 
{
    if (m == NULL) return NULL;

    node_pila* node = new node_pila();
    node->seguent = NULL;
    node->info = m->info;

    node_pila* first_node = node;

    m = m->seguent;
    while (m != NULL)
    {
        node->seguent = new node_pila();
        node = node->seguent;

        node->seguent = NULL;
        node->info = m->info;

        m = m->seguent;
    }

    return first_node;
}


/* Pre: cert */
/* Post: El p.i. passa a ser una còpia d'original i qualsevol
   contingut anterior del p.i. ha estat esborrat (excepte si el
   p.i. i original ja eren el mateix objecte) */

Pila& operator=(const Pila& original)
{
    if (this == &original) return *this;
    altura = original.mida();
    primer_node = copia_node_pila_it(original.primer_node);
    return *this;
}