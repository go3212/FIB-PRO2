#ifndef MYSET_HH
#define MYSET_HH

#include <iostream>

class MySet
{
public:
	MySet()
	{
		primer = NULL;
		ult = NULL;
	}
	
	void read(int k)
	{
		node* myNode = new node();
		int n; std::cin >> n;
		if (n != 0)
		{
			myNode->info = n;
			myNode->seg = NULL;
			primer = myNode;
			ult = myNode;
			
		    std::cin >> n;
			while (n != 0)
			{
				myNode->seg = new node();
				myNode = myNode->seg;
				myNode->info = n;
				myNode->seg = NULL;
				ult = myNode;
				std::cin >> n;
			}
		}
		else
		{
			primer = NULL;
			ult = NULL;
		}

	}
	
	void print()
	{
		node* iter = primer;
		while (iter != NULL)
		{
			std::cout << iter->info << " ";
			iter = iter->seg;
		}
	}
	
	#include "galopar.hh"
	
private:
	struct node 
	{
		int info;
		node* seg;
	};
	node* primer, *ult;
	
	#include "salta.hh"
};

#endif