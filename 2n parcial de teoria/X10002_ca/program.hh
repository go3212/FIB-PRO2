void deleteNode (node_llista** node)
{
	--longitud;
	
	if (*node == primer_node && *node == ultim_node) 
	{
		delete *node;
		primer_node = NULL;
		ultim_node = NULL;
		(*node) = NULL;
		return void();
	}
	
	if (*node == primer_node)
	{
		primer_node = primer_node->seg;
		delete *node;
		primer_node->ant = NULL;
		(*node) = primer_node;
		return void();
	}
	
	if (*node == ultim_node)
	{
		ultim_node = ultim_node->ant;
		delete *node;
		ultim_node->seg = NULL;
		(*node) = NULL;
		return void();
	}
	
	(*node)->seg->ant = (*node)->ant;
	(*node)->ant->seg = (*node)->seg;
	node_llista* temp = (*node);
	(*node) = (*node)->seg;
	delete temp;
	
}

/* Pre: parametre implicit = P */
/* Post: s'han eliminat del parametre implicit totes les aparicions d'x (la
   resta d'elements queda en el mateix ordre que a P); si el punt d'interes de P
   referenciava a una aparicio d'x, passa a referenciar al primer element
   diferent d'x posterior a aquesta (si no hi ha cap element diferent d'x, passa
   a la dreta el tot); en cas contrari, el punt d'interes no canvia */
void esborrar_tots(const T& x)
{
	if (primer_node == NULL) return void();
	bool replace_next = false;
	
	node_llista* iter = primer_node;
	while (iter != NULL)
	{
		if (iter->info == x) 
		{
			if (iter == act) replace_next = true;
			deleteNode(&iter);
			if (replace_next) act = iter, replace_next = false;
		} else iter = iter->seg;
	}
	
}