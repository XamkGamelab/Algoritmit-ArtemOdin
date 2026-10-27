#pragma once
#include "BSTnode.h"
#include <list>
#include <iostream>

class BST
{
public:
	BST() { pRoot = nullptr; }

	bool isEmpty() { return pRoot == nullptr; }

	void insert(int key);
	void print();

	bool find(int key);
	bool remove(int key);

	int CountNodes();
	int CountLeaves();

private:
	BSTnode* pRoot;
	int countNodes(BSTnode* node);
    int countLeaves(BSTnode* node);
	void printLayer();
	BSTnode* removeHelper(BSTnode* node, int key);
	int successor(BSTnode* node);
	int predecessor(BSTnode* node);

	std::list<BSTnode*> currentLayer;
};

