#pragma once
class BSTnode
{
public:
	int key;
	BSTnode* pLeft;
	BSTnode* pRight;

	BSTnode() {
		key = -1;
		pLeft = nullptr;
		pRight = nullptr;
	}

	BSTnode(int key) {
		this->key = key;
		pLeft = nullptr;
		pRight = nullptr;
	}

};

