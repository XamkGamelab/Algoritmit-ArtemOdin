

#include "linkedlist.h"
#include <iostream>

bool LinkedList::IsEmpty() 
{
	return this->pHead == nullptr;
}

void LinkedList::Insert(int value)
{
	if (IsEmpty()) //If empty - update the head node
	{
		Node* pNewNode = new Node(value);
		this->pHead = pNewNode;
	}
	else
	{
		Node* pNewNode = new Node(value);
		pNewNode->pNext = pHead;

		pHead = pNewNode;
	}
}

void LinkedList::InsertEnd(int value)
{
	if (IsEmpty()) //If empty - update the head node
	{
		Node* pNewNode = new Node(value);
		this->pHead = pNewNode;
	}
	else
	{
		Node* pNewNode = new Node(value);
		Node* pLast = this->pHead;

		while (pLast->pNext != nullptr) {
			pLast = pLast->pNext;
		}
		pLast->pNext = pNewNode;
	}
}

void LinkedList::Print()
{
	Node* pTmp = this->pHead;
	while (pTmp != nullptr) {
		std::cout << pTmp->data << std::endl;
		pTmp = pTmp->pNext;
	}
}

bool LinkedList::Find(int value)
{
	if (IsEmpty())
		return false;
	
	Node* pTmp = this->pHead;
	while (pTmp != nullptr) 
	{
		if (pTmp->data == value)
			return true;
		pTmp = pTmp->pNext;
	}

	return false;
}


bool LinkedList::Delete(int value)
{
	if (IsEmpty())
		return false;

	if (pHead->data == value)
	{
		Node* pToDelete = pHead;
		pHead = pHead->pNext;
		delete pToDelete;

		return true;
	}

	Node* pPrevious = this->pHead;
	Node* pCurrent = this->pHead;


	while (pCurrent != nullptr)
	{
		if (pCurrent->data == value)
		{
			pPrevious->pNext = pCurrent->pNext;
			delete pCurrent;
			return true;
		}
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
	}

	return false;
}

void LinkedList::Reverse()
{
	if (IsEmpty())
		return;

	Node* pPrevious = nullptr;
	Node* pCurrent = this->pHead;
	Node* pNext = this->pHead;

	while (pCurrent != nullptr)
	{
		pNext = pCurrent->pNext;

		pCurrent->pNext = pPrevious;

		pPrevious = pCurrent;
		pCurrent = pNext;

	}

	pHead = pPrevious;

}
