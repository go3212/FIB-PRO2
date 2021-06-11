#ifndef ARBRE_BINARI_HH
#define ARBRE_BINARI_HH

#include <iostream>
#include <string>

template <typename T>
class ArbreBinari
{
private:
	struct node
	{
		T info;
		node* esq;
		node* dre;
		
		node() : esq(NULL), dre(NULL) {};
		node(T data) : info(data), esq(NULL), dre(NULL) {};
	};
	node* arrel;
		
	node* read_tree (T marca)
	{
		T input; std::cin >> input;
		if (input == marca) return NULL;
		node* root = new node(input);
		node* left = read_tree(marca);
		node* right = read_tree(marca);
		root->esq = left;
		root->dre = right;
		return root;
	}
	
	void print_tree (node* root, T marca)
	{
		if (root == NULL) 
		{
			std::cout << marca << ' ';
			return void();
		}
		std::cout << root->info << ' ';
		print_tree (root->esq, marca);
		print_tree (root->dre, marca);
	}
	
	#include "ratio_depth.hh"
public:
	ArbreBinari()
	{
		arrel = NULL;
	}

	void read (T marca)
	{
		arrel = read_tree(marca);
	}
	
	void print (T marca)
	{
		print_tree (arrel, marca);
	}
	
	#include "area.hh"
};

#endif
