#pragma once
#include "node.h"
#include <iostream>


template<typename T> class Stack {

public:
	void Push(T data) {
		Node<T>* pNewNode = new Node<T>(data);
        pNewNode->pNext = pTop;
	    pTop = pNewNode;
	}
	T Pop() {
		if(IsEmpty()) {
			if constexpr (std::is_same_v<T, std::string>)
				return "";
			if constexpr (std::is_same_v<T, char>)
				return ' ';
			if constexpr (std::is_same_v<T, int>)
				return -1;
		}
		


		Node<T>* pToBeDeleted = pTop;
		pTop = pToBeDeleted->pNext;
		T data = pToBeDeleted->data;
		delete pToBeDeleted;

		return data;
	}
	T Top() {
		if (IsEmpty())
			return static_cast<T>(-1);

		return pTop->data;
	}
	bool IsEmpty() { return pTop == nullptr; };

	Stack() {
		this->pTop = nullptr;
	}

private:
	Node<T>* pTop;


}; 
