#include "tree.h"

Tree::Tree()
{
    root = nullptr;
}

Tree::Tree(QVector<std::pair<int, QString>> *arr)
{
    add(arr);
}

void Tree::add(int key, QString value)
{
    Node *newNode = new Node(key, value);

    if (root == nullptr)
        root = newNode;
    else
        pushRecursivly(newNode, root);
}

void Tree::add(QVector<std::pair<int, QString>> *arr)
{
    for (std::pair<int, QString> i : *arr)
        add(i.first, i.second);
}

void Tree::pushRecursivly(Node *node, Node *current)
{
    if (node->key < current->key)
    {
        if (current->left == nullptr)
            current->left = node;
        else
            pushRecursivly(node, current->left);
    }
    else if (node->key == current->key)
    {
        current->value = node->value;
        delete node;
    }
    else
    {
        if (current->right == nullptr)
            current->right = node;
        else
            pushRecursivly(node, current->right);
    }
}

void Tree::remove(int key)
{
    if (root == nullptr)
        return;

    removeRecursivly(key, root, nullptr);
}

void Tree::removeRecursivly(int key, Node *current, Node *parent)
{
    if (key < current->key && current->left != nullptr)
        removeRecursivly(key, current->left, current);

    else if (key == current->key)
    {
        Node **branch;
        Node *newNode;

        if (parent == nullptr)
            branch = &root;
        else if (parent->left != nullptr && parent->left->key == current->key)
            branch = &parent->left;
        else
            branch = &parent->right;


        if (current->left != nullptr && current->right != nullptr)
        {
            Node *tmp = findMostLeft(current->right);
            newNode = new Node(tmp->key, tmp->value);
            removeRecursivly(tmp->key, this->root, nullptr);
            newNode->left = current->left;
            newNode->right = current->right;

        }
        else if (current->left != nullptr || current->right != nullptr)
        {
            if (current->left != nullptr)
                newNode = current->left;
            else
                newNode = current->right;
        }
        else
            newNode = nullptr;

        *branch = newNode;
        delete current;
    }
    else if (key > current->key && current->right != nullptr)
        removeRecursivly(key, current->right, current);
}


Node *Tree::findMostLeft(Node *startPos)
{
    if (startPos->left != nullptr)
        return findMostLeft(startPos->left);

    return startPos;
}

Node *Tree::findMostRight(Node *startPos)
{
    if (startPos->right != nullptr)
        return findMostRight(startPos->right);

    return startPos;
}


QString Tree::find(int key)
{
    if (root == nullptr)
        return "";

    return findRecursivly(key, root);
}

QString Tree::findRecursivly(int key, Node *current)
{
    if (key < current->key && current->left != nullptr)
        return findRecursivly(key, current->left);

    else if (key == current->key)
        return current->value;

    else if (current->right != nullptr)
        return findRecursivly(key, current->right);

    return nullptr;
}


void Tree::balance()
{
    if (root == nullptr)
        return;

    QVector<std::pair<int, QString>> *sorted = getSorted();

    dispose();

    addSorted(sorted, 0, sorted->length() - 1);
}

void Tree::addSorted(QVector<std::pair<int, QString>> *arr, int left, int right)
{
    if (left == right)
        add((*arr)[left].first, (*arr)[left].second);

    else if (left + 1 == right)
    {
        add((*arr)[left].first, (*arr)[left].second);
        add((*arr)[right].first, (*arr)[right].second);
    }
    else
    {
        int m = (left + right) / 2;
        add((*arr)[m].first, (*arr)[m].second);
        addSorted(arr, left, m - 1);
        addSorted(arr, m + 1, right);
    }
}

void Tree::dispose()
{
    if (root == nullptr)
        return;

    disposeRecursivly(root);

    root = nullptr;
}


void Tree::disposeRecursivly(Node *first)
{
    if (first->left != nullptr)
        disposeRecursivly(first->left);

    if (first->right != nullptr)
        disposeRecursivly(first->right);

    delete first;
}


QVector<std::pair<int, QString>> *Tree::getSorted()  //Left-Root-Right
{
    if (root == nullptr)
        return nullptr;

    QVector<std::pair<int, QString>> *out = new QVector<std::pair<int, QString>>();
    dfsSorted(root, out);

    return out;
}

void Tree::dfsSorted(Node *current, QVector<std::pair<int, QString>> *out)
{
    if (current->left != nullptr)
        dfsSorted(current->left, out);

    out->push_back(std::make_pair(current->key, current->value));

    if (current->right != nullptr)
        dfsSorted(current->right, out);
}

QVector<std::pair<int, QString>> *Tree::getForward() //Root-Left-Right
{
    if (root == nullptr)
        return nullptr;

    QVector<std::pair<int, QString>> *out = new QVector<std::pair<int, QString>>();

    dfsForward(root, out);

    return out;
}

void Tree::dfsForward(Node *current, QVector<std::pair<int, QString>> *out)
{
    out->push_back(std::make_pair(current->key, current->value));

    if (current->left != nullptr)
        dfsSorted(current->left, out);

    if(current->right != nullptr)
        dfsSorted(current->right, out);
}

QVector<std::pair<int, QString>> *Tree::getBack()  //Left-Right-Root
{
    if (root == nullptr)
        return nullptr;

    QVector<std::pair<int, QString>> *out = new QVector<std::pair<int, QString>>();

    dfsBack(root, out);

    return out;
}

void Tree::dfsBack(Node *current, QVector<std::pair<int, QString>> *out)
{
    if (current->left != nullptr)
        dfsSorted(current->left, out);

    if (current->right != nullptr)
        dfsSorted(current->right, out);

    out->push_back(std::make_pair(current->key, current->value));
}
