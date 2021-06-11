void rec_count (int& count, const T search_val, const node_arbreGen* node) const
{
    if (node == NULL) return void();
    if (node->info == search_val) ++count;
    int size = node->seg.size();
    int i = 0;
    while (i < size)
    {
        rec_count (count, search_val, node->seg[i]);
        ++i;
    }

}

/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
int freq(const T& x) const
{
    int count = 0;
    rec_count (count, x, primer_node);
    return count;
}