#ifndef BAG_HH
#define BAG_HH

template <typename T>
class Bag
{
public:
		void afegeix (const T& x);
		bool conte (const T& x);
		int cardinalitat () const;
		T primer() const;
		
private:
	struct node
	{
		T info;
		node* seg;
	};
	node* sent;
	int tam;
};

#endif