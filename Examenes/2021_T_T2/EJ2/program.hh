static bool es_fulla (node* p)
{
	for (int i = 0; i < p->fill.size(); ++i)
	{
		if (p->fill[i] != NULL) return false;
	}
	return true;
}

static bool i_max (node* p, int& sum, int& nodes)
{
	if (es_fulla(p)) return true;
	else
	{
		bool condicio_pref = true;
		
		int c_sum = 0, c_nodes = 0;
		for (int i = 0; i < p->fill.size() and condicio_pref; ++i)
		{
			if (p->fill[i] != NULL)
			{
				c_sum = p->fill[i]->info;
				c_nodes = 1;
				
				condicio_pref = i_max (p->fill[i], c_sum, c_nodes);
				
				sum += c_sum;
				nodes += c_nodes;
			}
		}
		if (condicio_pref) return ((sum)%(nodes)) == 0;
		else return false;
	}
}

bool condicio_pref () const
{
	int sum = arrel->info, nodes = 1;
	return i_max (arrel, sum, nodes);
}