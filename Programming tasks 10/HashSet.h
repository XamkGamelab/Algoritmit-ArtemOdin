#pragma once
#include "node.h"

class HashSet
{
public:
	HashSet(int max) {
		size = max;
		nodearray = new Node* [size] {};
		for (int i = 0; i < size; i++) 
		{
			nodearray[i] = new Node(-1);
		}
	}

	void insert(int key);
	bool contains(int key);
	void print();
	
private:
	Node** nodearray;
	int size;
	int hashFunction(int key) { return key % size; }
};