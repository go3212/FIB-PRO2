void elim_repes_cons()
{
	node_llista* antact =  primer_node;
	act = antact->seg;
	while(act != NULL)
	{
		//act = antact->seg;
		//if (act != NULL) antact = act->ant;
		
		node_llista* segact = act->seg;
		if (antact->info == act->info)
		{
			delete act;
			antact->seg = segact;
			act = segact;
			if (act != NULL) act->ant = antact;
		}
		else
		{
			antact = act;
			act = segact;
		}
	}
	ultim_node = antact;
}

void marca_canvis_signe()
{
	node_llista* antact = primer_node;
	act = antact->seg;
	while(act != NULL)
	{
		if (antact->info * act->info < 0)
		{
			node_llista* zero = new node_llista();
			zero->info = 0;
			antact->seg = zero; zero->ant = antact;
			zero->seg = act; act->ant = zero;
		}
		antact = act;
		act = act->seg;
	}

}