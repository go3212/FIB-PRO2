#include <iostream>
#include "ArbreBinari.hh"

int main ()
{
	ArbreBinari<char> tree;
	std::cout << "Input: "; tree.read('0');
	std::cout << "Input check: "; tree.print('0');
	std::cout << std::endl;
	// EJ: a b c 0 f 0 0 0 d e 0 0 g j m 0 0 i 0 0 k 0 0
	std::cout << "Input area: " << tree.area() << std::endl;
}