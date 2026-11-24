#include "WordHashSet.h"
#include <iostream>
#include <cctype>


void WordHashSet::insert(const std::string& word)
{
	if (contains(word) || word.size() > 5)
		return;

	int index = hashFunction(word);

	StringNode* indexNode = nodearray[index];

	if (indexNode->data == "")
	{
		indexNode->data = word;
	}
	else
	{
		StringNode* pNewNode = new StringNode(word);
		StringNode* pLast = indexNode;

		while (pLast->pNext != nullptr) {
			pLast = pLast->pNext;
		}
		pLast->pNext = pNewNode;
	}

}

void WordHashSet::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i << ": ";

		StringNode* indexNode = nodearray[i];

		if (indexNode->data != "")
			std::cout << indexNode->data;

		while (indexNode->pNext != nullptr)
		{
			indexNode = indexNode->pNext;
			std::cout << "->" << indexNode->data;
		}

		std::cout << std::endl;
	}

}


bool WordHashSet::contains(const std::string& word)
{
	int index = hashFunction(word);
	StringNode* indexNode = nodearray[index];

	while (indexNode != nullptr)
	{
		if (indexNode->data == word)
			return true;

		indexNode = indexNode->pNext;
	}

	return false;
}

int WordHashSet::hashFunction(const std::string& word)
{
	int letterNum;
	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		char letter = word[i];

		letterNum = std::tolower(letter) - 'a' + 1;

		int multiplier;

		if (i == 0) 
		{
			multiplier = 1;
		}
		else 
		{
			multiplier = 27;

			for (int j = 1; j < i; j++) 
			{
				multiplier *= 27;
			}
		}

		sum += letterNum * multiplier;
	}

	return sum % size;
}
