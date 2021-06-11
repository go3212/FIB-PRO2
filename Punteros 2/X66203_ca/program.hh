void node_search_max (const node_arbreNari* node, T& maxVal) const
{
    if (node == NULL) return void();
    if (node->info > maxVal) maxVal = node->info;
    int size = node->seg.size();
    for (int i = 0; i < size; ++i)
    {
        node_search_max (node->seg[i], maxVal);
    }
}

/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
T maxim() const
{
    T maxVal = primer_node->info;
    node_search_max (primer_node, maxVal);
    return maxVal;
}