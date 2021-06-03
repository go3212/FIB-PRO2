void concat(Cua& c)
{
    if (!c.es_buida() && longitud == 0)
    {
        node_cua* node = new node_cua();
        node->info = c.primer();
        node->seguent = NULL;

        primer_node = node;
        ultim_node = node;

        ++longitud;

        c.avancar();
    }  

    while (!c.es_buida())
    {
        node_cua* node = new node_cua();
        node->info = c.primer();
        node->seguent = NULL;
        
        ultim_node->seguent = node;
        ultim_node = node;

        ++longitud;

        c.avancar();
    }
}