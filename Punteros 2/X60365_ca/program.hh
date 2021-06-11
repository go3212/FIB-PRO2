void rec_search (bool& found, const T search_val, const node_arbreGen* node) const
{
    if (node == NULL || found) return void();
    if (node->info == search_val) 
    {
        found = true;
        return void();
    }
    int size = node->seg.size();
    int i = 0;
    while (!found && i < size)
    {
        rec_search (found, search_val, node->seg[i]);
        ++i;
    }

}

/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
bool buscar(const T& x) const
{
    bool found = false;
    rec_search(found, x, primer_node);
    return found;
}