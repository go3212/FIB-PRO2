static double ratio_depth(node* root) // Se supone que es privado, por comodidad lo dejo publico.
{
	if (root == NULL) return 0;
	return 1 + (ratio_depth (root->esq) + ratio_depth (root->dre))/2;
}
