MySet galopar () const
{
	MySet returnSet;
	node* iter = primer;
	
	if (iter == NULL) return returnSet;
	
	returnSet.primer = new node();
	returnSet.primer->seg = NULL;
	returnSet.primer->info = iter->info;
	returnSet.ult = returnSet.primer;
	iter = iter->seg;
	
	int stride = 2;
	while (iter != NULL)
	{
		returnSet.ult->seg = new node();
		returnSet.ult->seg->info = iter->info;
		returnSet.ult->seg->seg = NULL;
		returnSet.ult = returnSet.ult->seg;
		iter = salta(iter, stride);
		
		stride += stride;
	} 
	
	return returnSet;
}