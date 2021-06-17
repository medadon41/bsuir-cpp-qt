#include "randomqueue.h"
#include <random>
#include <math.h>

RandomQueue::RandomQueue()
{

}

RandomQueue::RandomQueue(int count, int lowerBound, int upperBound)
{
    for( int i = 0; i < count; i++)
        push(lowerBound + rand() % (upperBound - lowerBound));
}

int RandomQueue::getMin()
{
    Node *current = first;

    int min = INT_MAX;

    while (current != nullptr)
    {
        min = std::min(min, current->value);
        current = current->next;
    }

    return min;
}


void RandomQueue::clearBetweenMinAndMax()
{
    if (isEmpty() || first == last)
        return;

    int min = getMin();

    Node *t_first = new Node(min);

    t_first->prev = nullptr;
    t_first->next = first;

    first->prev = t_first;

    first = t_first;

    delete t_first;

    Node *currentNode = first->next;

    while (currentNode != nullptr) {
        if (currentNode->value == min) {
            Node *cprev = currentNode->prev;
            Node *cnext = currentNode->next;
            cprev->next = cnext;
            cnext->prev = cprev;
            delete currentNode;
            return;
        }
        currentNode = currentNode->next;
    }

}
