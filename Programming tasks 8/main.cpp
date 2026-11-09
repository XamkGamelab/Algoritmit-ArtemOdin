#include "Heap.h"
#include <iostream>
#include <chrono>  

int main() {

	Heap myheap;

	myheap.insert(17);
	myheap.insert(11);
	myheap.insert(6);
	myheap.insert(14);
	myheap.insert(22);
	myheap.insert(8);
	myheap.insert(1);
	myheap.insert(16);
	myheap.insert(10);
	myheap.insert(19);
	myheap.insert(12);
	myheap.insert(3);
	myheap.insert(5);
	myheap.insert(15);
	myheap.insert(13);

	myheap.print();

	myheap.del_min();

	myheap.print();

	myheap.sort();

	myheap.print();

	myheap.measureSortTime(100000);
	myheap.measureSortTime(1000000);
	myheap.measureSortTime(10000000);

	return EXIT_SUCCESS;
}