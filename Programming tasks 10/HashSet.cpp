#include "HashSet.h"
#include <iostream>


void HashSet::insert(int key)
{
	if (contains(key))
		return;

	int index = hashFunction(key);

	Node* indexNode = nodearray[index];

	if (indexNode->data == -1) 
	{
		indexNode->data = key;
	}
	else
	{
		Node* pNewNode = new Node(key);
		Node* pLast = indexNode;

		while (pLast->pNext != nullptr) {
			pLast = pLast->pNext;
		}
		pLast->pNext = pNewNode;
	}

}

void HashSet::print()
{
	for (int i = 0; i < size; i++) 
	{
		std::cout << i << ": ";

		Node* indexNode = nodearray[i];

		if(indexNode->data != -1)
			std::cout << indexNode->data;

		while (indexNode->pNext != nullptr) 
		{
			indexNode = indexNode->pNext;
			std::cout << "->" << indexNode->data;
		}

		std::cout << std::endl;
	}

}

bool HashSet::contains(int key)
{
	int index = hashFunction(key);
	Node* indexNode = nodearray[index];

	while (indexNode != nullptr) 
	{
		if (indexNode->data == key)
			return true;

		indexNode = indexNode->pNext;
	}

	return false;
}
