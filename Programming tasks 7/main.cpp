#include <iostream>
#include "BST.h"

int main() {
	BST bst;
	bst.insert(5);
	bst.insert(3);
	bst.insert(8);
	bst.insert(2);
	bst.insert(4);
	bst.insert(1);
	bst.insert(7);
	bst.insert(6);
	bst.insert(9);

	//std::cout << bst.find(2);
	bst.print();

	bst.remove(8);

	std::cout << std::endl;

	bst.print();

	return EXIT_SUCCESS;
}