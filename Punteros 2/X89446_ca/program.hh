/* Pre: cert */
/* Post: el resultat és una llista que conté els mateixos 
elements que el p.i. tal que tots els més petits o iguals 
que x al p.i. precedeixen als més grans que x al p.i. però 
sempre respectant l'ordre que hi havia entre ells al p.i. 
L'element actual de la llista retornada és el primer dels 
més grans que x, si existeix, sinó es situa a la detra del 
tot. El p.i. no es modifica */
Llista  reorganitzar_out(const T& x) const
{
    Llista<int> list;
    if (primer_node == NULL) return list;

    // Lists
    Llista<int> listGt; listGt.longitud = 0;
    Llista<int> listLt; listLt.longitud = 0; 

    node_llista* iter = primer_node;
    while (iter != NULL)
    {
        if (iter->info <= x)
        {
            if (listLt.longitud != 0)
            {
                listLt.ultim_node->seg = new node_llista();
                listLt.ultim_node->seg->ant = listLt.ultim_node;
                listLt.ultim_node->seg->seg = NULL;
                listLt.ultim_node->seg->info = iter->info;
            }
            else
            {
                listLt.ultim_node = new node_llista();
                listLt.ultim_node->ant = NULL;
                listLt.ultim_node->seg = NULL;
                listLt.ultim_node->info = iter->info;
                listLt.primer_node = listLt.ultim_node;
            }
            ++listLt.longitud;
        }
        else
        {
            if (listGt.longitud != 0)
            {
                listGt.ultim_node->seg = new node_llista();
                listGt.ultim_node->seg->ant = listGt.ultim_node;
                listGt.ultim_node->seg->seg = NULL;
                listGt.ultim_node->seg->info = iter->info;
            }
            else
            {
                listGt.ultim_node = new node_llista();
                listGt.ultim_node->ant = NULL;
                listGt.ultim_node->seg = NULL;
                listGt.ultim_node->info = iter->info;
                listGt.primer_node = listGt.ultim_node;
            }
            ++listGt.longitud;
        }
        iter = iter->seg;
    }
    list.primer_node = listLt.primer_node;
    list.ultim_node = listGt.ultim_node;
    listLt.ultim_node->seg = listGt.primer_node;
    listGt.primer_node->ant = listLt.ultim_node;
    list.longitud = listLt.longitud + listGt.longitud;

    list.act = listGt.primer_node;

    listLt.primer_node = NULL;
    listLt.ultim_node = NULL;
    listLt.act = NULL;
    listGt.primer_node = NULL;
    listGt.ultim_node = NULL;
    listGt.act = NULL;
    
    return list;
}