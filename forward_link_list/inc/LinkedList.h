/*
 * LinkedList.h
 *
 *  Created on: Feb 23, 2019
 *      Author: z003xwaj
 */

#ifndef REVERSE_LINKED_LIST_INC_LINKEDLIST_H_
#define REVERSE_LINKED_LIST_INC_LINKEDLIST_H_

#include <ostream>

template <typename T>
class LinkedList
{
    T m_data;
    LinkedList<T>* m_Next;

    LinkedList(const LinkedList<T>& rhs) = delete;
    LinkedList<T>& operator=(const LinkedList<T>& rhs) = delete;

public:
    LinkedList(T data);
    LinkedList(T data, LinkedList<T>* next);

    ~LinkedList() = default;

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
    LinkedList<T>* tail() const;

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
    if(nullptr == matchNode || nullptr == newNode)
        return false;

    bool isMatchNodeFound = false;

    for(LinkedList<T>* node = this; nullptr != node; node = node->next())
    {
        if(node == matchNode)
        {
            isMatchNodeFound = true;
            newNode->tail()->setNext(node->next());
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
            newNode.tail()->setNext(node->next());
            node->setNext(&newNode);
            break;
        }
    }

    return isMatchNodeFound;
}

template <typename T>
LinkedList<T>* LinkedList<T>::insertAfter(LinkedList<T>* newNode)
{
    if(nullptr == newNode)
        return nullptr;

    LinkedList<T>* newNodeTail = newNode->tail();

    newNodeTail->setNext(next());
    setNext(newNode);

    return newNodeTail;
}

template <typename T>
LinkedList<T>& LinkedList<T>::insertAfter(LinkedList<T>& newNode)
{
    LinkedList<T>* newNodeTail = newNode.tail();

    newNodeTail->setNext(next());
    setNext(newNode);

    return *newNodeTail;
}

template <typename T>
bool LinkedList<T>::insertBefore(LinkedList<T>* matchNode, LinkedList<T>* newNode)
{
    if(nullptr == matchNode || nullptr == newNode)
        return false;

    bool isMatchNodeFound = false;

    if(this == matchNode)
    {
        newNode->tail()->setNext(this);
        return true;
    }

    for(LinkedList<T>* node = this; nullptr != node; node = node->next())
    {
        if(node->next() == matchNode)
        {
            isMatchNodeFound = true;
            newNode->tail()->setNext(matchNode);
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

    if(this == &matchNode)
    {
        newNode.tail()->setNext(this);
        return true;
    }

    for(LinkedList<T>* node = this; nullptr != node; node = node->next())
    {
        if(node->next() == (&matchNode))
        {
            isMatchNodeFound = true;
            newNode.tail()->setNext(matchNode);
            node->setNext(newNode);
            break;
        }
    }
    return isMatchNodeFound;
}

template <typename T>
bool LinkedList<T>::deleteNode(LinkedList<T>* matchNode)
{
    if(nullptr == matchNode)
        return false;

    if(this == matchNode)
    {
        setNext(nullptr);
        return true;
    }

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
    if(this == &matchNode)
    {
        setNext(nullptr);
        return true;
    }

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
LinkedList<T>* LinkedList<T>::setNext(LinkedList<T>* node)
{
    m_Next = node;
    return m_Next;
}

template <typename T>
LinkedList<T>& LinkedList<T>::setNext(LinkedList<T>& node)
{
    m_Next = &node;
    return *m_Next;
}

template <typename T>
LinkedList<T>* LinkedList<T>::next() const
{
    return m_Next;
}

template <typename T>
LinkedList<T>* LinkedList<T>::tail() const
{
    LinkedList<T>* node = const_cast<LinkedList<T>*>(this);

    while(nullptr != node->next())
    {
        node = node->next();
    }

    return node;
}

template <typename T>
T LinkedList<T>::data() const
{
    return m_data;
}

#endif /* REVERSE_LINKED_LIST_INC_LINKEDLIST_H_ */
