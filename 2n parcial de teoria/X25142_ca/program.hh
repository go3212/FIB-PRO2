T camino_maximo (node_arbreGen* root) const
{
	if (root == NULL) return 0;
	T max = 0; 
	int size = root->seg.size();
	for (int i = 0; i < size; ++i)
	{
		T x = camino_maximo (root->seg[i]);
		if (x > max) max = x;
	}
	return max + root->info;
}

/* Pre: el parametre implicit no es buit */
/* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
T max_suma_cami() const
{
	return camino_maximo (primer_node);
}
