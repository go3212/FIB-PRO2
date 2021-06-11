static int suma_elementos (node_arbre* root, int& elementos)
{
	if (root == NULL) return 0;
	int left = suma_elementos (root->segE, elementos);
	int right = suma_elementos (root->segD, elementos);
	if (right - left == root->info) ++elementos;
	return root->info + left + right;
}



int frontisses () const
{
	int elementos = 0;
	suma_elementos (primer_node, elementos);
	return elementos;
}