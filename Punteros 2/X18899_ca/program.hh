int node_create_sum_tree (node_arbreNari* inNode, node_arbreNari** outNode) const
{
    if (inNode == NULL) return 0;

    int size = (inNode->seg).size();

    (*outNode) = new node_arbreNari();
    
    (*outNode)->info = inNode->info;
    (*outNode)->seg = vector<node_arbreNari*>(size);
    for (int i = 0; i < size; ++i)
    {
        if (inNode->seg[i] != NULL)
        {
            (*outNode)->info += node_create_sum_tree (inNode->seg[i], &(*outNode)->seg[i]);
        } else (*outNode)->seg[i] = NULL;
    }
    return (*outNode)->info;
}

/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
void arbsuma(ArbreNari& asum) const
{
    asum.primer_node = new node_arbreNari();
    asum.N = N;
    node_create_sum_tree (primer_node, &asum.primer_node);
}