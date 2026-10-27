#include "BST.h"


//Inserts smaller values left
//Equal or greater values right

void BST::insert(int key)

{
    if (find(key))
        return;

    BSTnode* pNewNode = new BSTnode(key);

    if (isEmpty())
    {
        pRoot = pNewNode;
    }
    else
    {
        BSTnode* pCurrnent = pRoot;
        BSTnode* pCandidate = pRoot;

        while (pCandidate != nullptr) {
            pCurrnent = pCandidate;
            if (pNewNode->key < pCurrnent->key) 
            {
                pCandidate = pCurrnent->pLeft;
            }
            else 
            {
                pCandidate = pCurrnent->pRight;

            }
        }
        
        // Check which direction we need to put
        if (pNewNode->key < pCurrnent->key)
            pCurrnent->pLeft = pNewNode;
        else
            pCurrnent->pRight = pNewNode;
    }

}

void BST::print()
{
    if (isEmpty())
        return;


    currentLayer.clear();

    currentLayer.push_back(pRoot);

    printLayer();

}

void BST::printLayer()
{
    if (currentLayer.empty())
        return;

    std::list<BSTnode*> nextLayer;

    for (BSTnode* node : currentLayer) {
        std::cout << " " << node->key;

        if(node->pLeft != nullptr)
           nextLayer.push_back(node->pLeft);

        if (node->pRight != nullptr)
          nextLayer.push_back(node->pRight);

    }

    std::cout << std::endl << std::endl;

    currentLayer = nextLayer;

    printLayer();
}


bool BST::find(int key)
{
    if (isEmpty())
        return false;

    BSTnode* currentNode = pRoot;

    while (currentNode != nullptr) 
    {
        if (currentNode->key == key)
            return true;

        if (currentNode->key < key) 
        {
            currentNode = currentNode->pRight;
        }
        else 
        {
            currentNode = currentNode->pLeft;
        }
    }


    return false;
}

bool BST::remove(int key)
{
    if (isEmpty())
        return false;

    if (!find(key))
        return false;

    pRoot = removeHelper(pRoot, key);


    return true;
}

BSTnode* BST::removeHelper(BSTnode* node, int key)
{
    if (node == nullptr)
        return node;

    if (key < node->key) {
        node->pLeft = removeHelper(node->pLeft, key);
    }
    else if (key > node->key) {
        node->pRight = removeHelper(node->pRight, key);
    }
    else
    {
        if (node->pLeft == nullptr && node->pRight == nullptr) {
            delete node;
            node = nullptr;
        }
        else if (node->pRight != nullptr) {
            node->key = successor(node);
            node->pRight = removeHelper(node->pRight, node->key);
        }
        else {
            node->key = predecessor(node);
            node->pLeft = removeHelper(node->pLeft, node->key);
        }
    }
    return node;
}

int BST::successor(BSTnode* node)
{
    node = node->pRight;
    while (node->pLeft != nullptr) {
        node = node->pLeft;
    }
    return node->key;
}

int BST::predecessor(BSTnode* node)
{
    node = node->pLeft;
    while (node->pRight != nullptr) {
        node = node->pRight;
    }
    return node->key;
}

int BST::CountNodes()
{
    if (isEmpty())
        return 0;

    return countNodes(pRoot);
}

int BST::countNodes(BSTnode* T)
{
    if (T == nullptr)
        return 0;

    return countNodes(T->pLeft) + countNodes(T->pRight) + 1;

}

int BST::CountLeaves()
{
    if (isEmpty())
        return 0;

    return countLeaves(pRoot);
}

int BST::countLeaves(BSTnode* T)
{
    if (T == nullptr)
        return 0;

    if(T->pLeft == nullptr && T->pRight == nullptr)
        return countLeaves(T->pLeft) + countLeaves(T->pRight) + 1;


    return countLeaves(T->pLeft) + countLeaves(T->pRight);

}

