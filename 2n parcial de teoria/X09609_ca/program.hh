void busca_nodo (node_arbre* root, int depth, int& element_depth, node_arbre** element, const T& x)
{
	if (root == NULL) return void();
	busca_nodo (root->segE, ++depth, element_depth, element, x);
	busca_nodo (root->segD, ++depth, element_depth, element, x);
	if (root->info == x &&  (element_depth == -1 || depth <= element_depth)) element_depth = depth, *element = root;
}

/* Pre: p.i. = A, asub es buit */
/* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
   si A no conte x, asub es buit */
void sub_arrel(Arbre& asub, const T& x)
{
	node_arbre* node = NULL;
	int element_depth = -1;
	busca_nodo (primer_node, 0, element_depth, &node, x);
	asub.primer_node = copia_node_arbre (node);
}
