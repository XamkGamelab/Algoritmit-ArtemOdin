#include "linkedlist.h"
#include <iostream>

int main() {

	LinkedList ll; //Calls constructor

	for (int i = 1; i < 100; i++)
		ll.Insert(i);

	ll.Print();

	std::cout << std::endl << "Finding 42 " << ll.Find(42) << std::endl;

	std::cout << std::endl << "Finding 66 " << ll.Find(66) << std::endl;

	std::cout << std::endl << "Finding 100 " << ll.Find(100) << std::endl;

	std::cout << std::endl << "Deleting 77 " << ll.Delete(77) << std::endl;

	std::cout << std::endl << "Deleting 21 " << ll.Delete(21) << std::endl;

	std::cout << std::endl << "Deleting -1 " << ll.Delete(-1) << std::endl;

	std::cout << std::endl << "IsEmpty() Before deleting " << ll.IsEmpty() << std::endl;

	for (int i = 1; i < 100; i++)
		ll.Delete(i);

	std::cout << std::endl << "IsEmpty() After deleting " << ll.IsEmpty() << std::endl;

	for (int i = 1; i < 100; i++)
		ll.Insert(i);

	ll.Reverse();

	std::cout << std::endl;

	ll.Print();

	return EXIT_SUCCESS;
}