/*
 * LinkedList.h
 *
 *  Created on: Feb 23, 2019
 *      Author: z003xwaj
 */

#include <ostream>

#ifndef REVERSE_LINKED_LIST_INC_LINKEDLIST_H_
#define REVERSE_LINKED_LIST_INC_LINKEDLIST_H_

template <typename T>
class LinkedList
{
    T m_data;
    LinkedList<T>* m_Next;

public:
    LinkedList(T data);
    LinkedList(T data, LinkedList<T>* next);

    LinkedList<T>* reverse();
    std::ostream& print(std::ostream& out) const;

    bool insertAfter(LinkedList<T>* matchNode, LinkedList<T>* newNode);
    bool insertAfter(LinkedList<T>& matchNode, LinkedList<T>& newNode);
    LinkedList<T>* insertAfter(LinkedList<T>* newNode);
    LinkedList<T>& insertAfter(LinkedList<T>& newNode);

    bool insertBefore(LinkedList<T>* matchNode, LinkedList<T>* newNode);
    bool insertBefore(LinkedList<T>& matchNode, LinkedList<T>& newNode);

    bool deleteNode(LinkedList<T>* matchNode);
    bool deleteNode(LinkedList<T>& matchNode);

    LinkedList<T>* setNext(LinkedList<T>* node);
    LinkedList<T>& setNext(LinkedList<T>& node);

    LinkedList<T>* next() const;

    void setData(T data);
    T data() const;
};

template <typename T>
LinkedList<T>::LinkedList(T data) : m_data(data), m_Next(nullptr)
{

}

template <typename T>
LinkedList<T>::LinkedList(T data, LinkedList<T>* next) : m_data(data), m_Next(next)
{

}

template <typename T>
LinkedList<T>* LinkedList<T>::reverse()
{
    bool isLastFound = false;

    LinkedList<T>* last;
    LinkedList<T>* lastPrev;
    LinkedList<T>* reversedHead;

    // Reverse Linked List
    while(nullptr != next())
    {
        last = next();
        lastPrev = this;

        while(1)
        {
            if(nullptr == last->next())
                break;
            else
            {
                lastPrev = last;
                last = last->next();
            }
        }

        if(false == isLastFound)
        {
            reversedHead = last;
            isLastFound = true;
        }

        last->setNext(lastPrev);
        lastPrev->setNext(nullptr);
    }

    return reversedHead;
}

template <typename T>
std::ostream& LinkedList<T>::print(std::ostream& out) const
{
    int index = 0;

    for(LinkedList<T>* node = const_cast<LinkedList<T>*>(this); nullptr != node; node = node->next(), ++index)
    {
        out << index << " : " << node->data() << std::endl;
    }

    return out;
}

template <typename T>
bool LinkedList<T>::insertAfter(LinkedList<T>* matchNode, LinkedList<T>* newNode)
{
    bool isMatchNodeFound = false;

    for(LinkedList<T>* node = this; nullptr != node; node = node->next())
    {
        if(node == matchNode)
        {
            isMatchNodeFound = true;
            newNode->setNext(node->next());
            node->setNext(newNode);
            break;
        }
    }

    return isMatchNodeFound;
}

template <typename T>
bool LinkedList<T>::insertAfter(LinkedList<T>& matchNode, LinkedList<T>& newNode)
{
    bool isMatchNodeFound = false;

    for(LinkedList<T>* node = this; nullptr != node; node = node->next())
    {
        if(node == (&matchNode))
        {
            isMatchNodeFound = true;
            newNode.setNext(node->next());
            node->setNext(&newNode);
            break;
        }
    }

    return isMatchNodeFound;
}

template <typename T>
LinkedList<T>* LinkedList<T>::insertAfter(LinkedList<T>* newNode)
{
    newNode->setNext(next());
    setNext(newNode);

    return newNode;
}

template <typename T>
LinkedList<T>& LinkedList<T>::insertAfter(LinkedList<T>& newNode)
{
    newNode.setNext(next());
    setNext(newNode);

    return newNode;
}

template <typename T>
bool LinkedList<T>::insertBefore(LinkedList<T>* matchNode, LinkedList<T>* newNode)
{
    bool isMatchNodeFound = false;

    for(LinkedList<T>* node = this; nullptr != node; node = node->next())
    {
        if(node->next() == matchNode)
        {
            isMatchNodeFound = true;
            newNode->setNext(matchNode);
            node->setNext(newNode);
            break;
        }
    }

    return isMatchNodeFound;
}

template <typename T>
bool LinkedList<T>::insertBefore(LinkedList<T>& matchNode, LinkedList<T>& newNode)
{
    bool isMatchNodeFound = false;

    for(LinkedList<T>* node = this; nullptr != node; node = node->next())
    {
        if(node->next() == (&matchNode))
        {
            isMatchNodeFound = true;
            newNode.setNext(matchNode);
            node->setNext(newNode);
            break;
        }
    }
    return isMatchNodeFound;
}

template <typename T>
bool LinkedList<T>::deleteNode(LinkedList<T>* matchNode)
{
    bool isMatchNodeFound = false;

    for(LinkedList<T>* node = this; nullptr != node; node = node->next())
    {
        if(node->next() == matchNode)
        {
            isMatchNodeFound = true;
            node->setNext(matchNode->next());
            break;
        }
    }
    return isMatchNodeFound;
}

template <typename T>
bool LinkedList<T>::deleteNode(LinkedList<T>& matchNode)
{
    bool isMatchNodeFound = false;

    for(LinkedList<T>* node = this; nullptr != node; node = node->next())
    {
        if(node->next() == (&matchNode))
        {
            isMatchNodeFound = true;
            node->setNext(matchNode.next());
            break;
        }
    }

    return isMatchNodeFound;
}

template <typename T>
LinkedList<T>* LinkedList<T>::next() const
{
    return m_Next;
}

template <typename T>
LinkedList<T>* LinkedList<T>::setNext(LinkedList<T>* node)
{
    m_Next = node;
    return m_Next;
}

template <typename T>
LinkedList<T>& LinkedList<T>::setNext(LinkedList<T>& node)
{
    m_Next = const_cast<LinkedList<T>*>(&node);
    return *m_Next;
}

template <typename T>
T LinkedList<T>::data() const
{
    return m_data;
}

#endif /* REVERSE_LINKED_LIST_INC_LINKEDLIST_H_ */