#include "myhashmap.h"
#include "mainwindow.h"
#include <QMessageBox>

MyHashMap::MyHashMap(int capacity) : HashMap(capacity)
{

}

MyHashMap * MyHashMap::removeNegativeKeys()
{
    MyHashMap * map2 = new MyHashMap(50);
    for (int i = 0; i < capacity; i++)
    {
        if (!arr[i]->isEmpty())
        {
            Node *current = arr[i]->first;

            while (current != nullptr)
            {
                if (current->key < 0)
                {
                    map2->add(current->key, current->value);
                    int k = current->key;
                    current = current->next;
                    arr[i]->remove(k);
                    continue;
                }
                current = current->next;
            }
        }
    }
    return map2;
}
