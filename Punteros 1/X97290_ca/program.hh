/* Pre: cert */
/* Post: si m és NULL, el resultat, u i a són NULL; en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que són còpia de la cadena que té el node apuntat per m
       com a primer, u apunta a l'últim node, a és o bé NULL si oact
       no apunta a cap node de la cadena que comença amb m o bé apunta
       al node còpia del node apuntat per oact */
node_llista* copia_node_llista_it (node_llista* m, node_llista* oact, node_llista* &u, node_llista* &a)
{
    longitud = 0;
    if (m == NULL)
    {   
        u = NULL;
        a = NULL;
        return NULL;
    }

    node_llista* node = new node_llista();
    node->seg = NULL;
    node->ant = NULL;
    node->info = m->info;
    if (m == oact) a = node;
    else a = NULL;

    node_llista* first = node;

    m = m->seg;
    ++longitud;
    while (m != NULL)
    {
        node->seg = new node_llista();
        node->seg->ant = node;
        node->seg->seg = NULL;
        node->seg->info = m->info;
        if (m == oact) a = node->seg;
        
        node = node->seg;
        m = m->seg;
        ++longitud;
    }
    u = node;
    return first;
}

/* Pre: cert */
/* Post: El p.i. passa a ser una còpia d'original i qualsevol
   contingut anterior del p.i. ha estat esborrat (excepte si el
   p.i. i original ja eren el mateix objecte) */
Llista& operator=(const Llista& original) 
{
    if (this == &original) return *this;
    while (longitud != 0)
    {
        node_llista* del = primer_node;
        primer_node = primer_node->seg;
        delete del;
        --longitud;
    }
    primer_node = copia_node_llista_it(original.primer_node, original.act, this->ultim_node, this->act);
    return *this;
}