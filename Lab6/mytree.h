#ifndef MYTREE_H
#define MYTREE_H
#include "tree.h"

class MyTree : public Tree
{
public:
    MyTree();
    MyTree(QVector<std::pair<int, QString>> *arr);

    void trySwap();

    QString maxValue;
    QString minValue;

private:
    void swap();
};

#endif // MYTREE_H
