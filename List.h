#pragma once
#include <iostream>

template <class T>
struct Node
{
    Node* next;
    T value;

};

template <class T>
class MyList
{
protected:
    Node<T>* pFirst;

public:

    MyList()
    {
        pFirst = NULL;
    }
    ~MyList()
    {
        while (pFirst != NULL)
        {
            Node<T>* p_delete = pFirst;
            pFirst = pFirst->next;
            delete p_delete;
        }
    }

    void Push(T _value)
    {
        Node<T>* newFirst = new Node<T>;
        newFirst->value = _value;
        newFirst->next = pFirst;

        pFirst = newFirst;
    }

    void PrintList()
    {
        Node<T>* cur = pFirst;
        while (cur != NULL)
        {
            std::cout << cur->value << std::endl;
            cur = cur->next;
        }
        delete cur;
    }

    void Delete2k()
    {
        Node<T>* cur = pFirst;
        Node<T>* prev = pFirst;
        for (int i = 1; cur != NULL; i++)
        {
            if (!(i % 2))
            {
                Node<T>* p_delete = cur;
                cur = cur->next;
                prev->next = cur;
                delete p_delete;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }

        }
        delete cur;
    }

};
