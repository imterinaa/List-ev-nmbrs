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
        pFirst = nullptr;
    }
    ~MyList()
    {
        while (pFirst != nullptr)
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
        if (pFirst == nullptr)
            std::cout << "stack is empty." <<  std::endl;
        else
        {
            Node<T>* p;
            p = pFirst;
            while (p != nullptr)
            {
                std::cout << p->value << "\t";
                p = p->next;
            }
            std::cout << std::endl;
        }
    }

    void Delete2k()
    {
        Node<T>* cur = pFirst;
        Node<T>* prev = pFirst;
        for (int i = 1; cur != nullptr; i++)
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
