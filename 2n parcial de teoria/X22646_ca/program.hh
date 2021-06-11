/* Pre: p.i. = C1, c = C2 */
/* Post: el p.i. passa a ser el resultat de trenar C1 i C2; c passa a ser buida */
void trenat(Cua &c)
{
	act = primer_node;
	c.act = primer_node;
	while (c.longitud != 0)
	{
		if (act != NULL && c.act != NULL) 
		{
			node_cua* par_seg = act->seg;
			node_cua* impar_seg = c.act->seg;
			act->seg = c.act;
			c.act->ant = ant;
			c.act->seg = par_seg;
			
			c.act = impar_seg;
			act = par_seg;
		}
		
		
		
		act->seg = c.act;
		
		
		++longitud;
		--c.longitud;
	}
}
