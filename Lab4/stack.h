#ifndef STACK_H
#define STACK_H

template<class T>
class Node
{
public:
    Node *pNext;
    T data;

    Node(T data = T(), Node *pNext = nullptr)
    {
        this->data = data;
        this->pNext = pNext;
    }
};

template<class T>
class Stack
{
public:
    Stack();
    ~Stack();
    void push(T data);
    T pop();
    void clear();
    T top();
    int getSize();
    bool empty();
    T &operator[](const int index);

private:
    int size = 0;
    Node<T> *head;
};

template<class T>
Stack<T>::Stack() { }

template<class T>
Stack<T>::~Stack() { }

template<class T>
void Stack<T>::push(T data)
{
    head = new Node<T>(data, head);
    size++;
}

template<class T>
T Stack<T>::top()
{
    return Stack<T>::operator[](0);
}

template<class T>
T Stack<T>::pop()
{
    if (head != nullptr)
    {
        Node<T> *tempNode = head;
        T data = head->data;
        head = head->pNext;

        delete tempNode;
        size--;
        return data;
    }
}

template<class T>
void Stack<T>::clear()
{
    while (size)
    {
        pop();
    }
}

template<class T>
int Stack<T>::getSize()
{
    return size;
}

template<class T>
bool Stack<T>::empty()
{
    return getSize() == 0;
}

template<class T>
T &Stack<T>::operator[](const int index)
{
    if (index < getSize()) {
        int counter = 0;

        Node<T> *currentNode = this->head;

        while (currentNode != nullptr)
        {
            if (counter == index)
            {
                return currentNode->data;
            }

            currentNode = currentNode->pNext;
            counter++;
        }
    }
}

#endif // STACK_H
