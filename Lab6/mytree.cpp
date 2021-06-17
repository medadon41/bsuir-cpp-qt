#include "mytree.h"

MyTree::MyTree() : Tree()
{

}

MyTree::MyTree(QVector<std::pair<int, QString> > *arr) : Tree(arr)
{

}


void MyTree::trySwap()
{
    if (root == nullptr)
        return;

    swap();
}

void MyTree::swap()
{
    Node *minNode = findMostLeft(root);
    minValue = minNode->value;

    Node *maxNode = findMostRight(root);
    maxValue = maxNode->value;

    minNode->value = maxValue;
    maxNode->value = minValue;
}




