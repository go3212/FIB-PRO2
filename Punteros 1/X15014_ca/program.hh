int tree_nodes_get_sum (node_arbre* root, node_arbre* outputRoot) const
{
    if (root == NULL) 
    {
        outputRoot = NULL;
        return 0;
    }
    outputRoot->info = 0;
    if (root->segE != NULL)
    {
        outputRoot->segE = new node_arbre();
        outputRoot->segE->info = tree_nodes_get_sum(root->segE, outputRoot->segE);
        outputRoot->info += outputRoot->segE->info;
    } else outputRoot->segE = NULL;
    if (root->segD != NULL)
    {
        outputRoot->segD = new node_arbre();
        outputRoot->segD->info = tree_nodes_get_sum(root->segD, outputRoot->segD);
        outputRoot->info += outputRoot->segD->info;
    } else outputRoot->segD = NULL;
    return root->info + outputRoot->info;
}

/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
void arb_sumes(Arbre<int> &asum) const
{
    if (primer_node != NULL) 
    {
        asum.primer_node = new node_arbre();
        asum.primer_node->info = tree_nodes_get_sum (primer_node, asum.primer_node);
    } else asum.primer_node = NULL;
}

