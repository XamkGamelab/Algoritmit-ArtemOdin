#pragma once
#include <iostream>

class StringNode
{
public:
	std::string data;
	StringNode* pNext;

	StringNode(std::string data) {
		this->data = data;
		this->pNext = nullptr;
	}
};