#pragma once
#include "stringnode.h"

class WordHashSet
{
public:
	WordHashSet(int max) {
		size = max;
		nodearray = new StringNode * [size] {};
		for (int i = 0; i < size; i++)
		{
			nodearray[i] = new StringNode("");
		}
	}

	void insert(const std::string& word);
	bool contains(const std::string& word);
	void print();

private:
	StringNode** nodearray;
	int size;
	int hashFunction(const std::string& word);
};

