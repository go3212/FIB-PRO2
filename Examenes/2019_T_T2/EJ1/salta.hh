static node* salta (node* p, int k)
{
	for (int i = 0; i < k; ++i)
	{
		if (p == NULL) break;
		p = p->seg;
	}
	return p;
}