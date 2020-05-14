#include "list.h"

//Почему реализация работает только если поместить её в заголовок?
/*
    template<typename T>
    List<T>::List()
    {

    }

    template<typename T>
    void List<T>::popBack()
    {
        if (tail == nullptr) return;

        if (tail == head )
        {
            delete tail;
            tail = nullptr;
            head = nullptr;
        }
        else
        {
            Node* n = tail->prev;
            delete tail;
            tail = n;
            tail->next = nullptr;
        }
        _size--;
        Update_end();
    }

    template<typename T>
    void List<T>::popFront()
    {
        if (head == nullptr) return;

        if (tail == head)
        {
            delete head;
            tail = nullptr;
            head = nullptr;
        }
        else
        {
            Node* n = head->next;
            delete head;
            head = n;
            head->prev = nullptr;
        }
        _size--;

    }

    template<typename T>
    void List<T>::pushFront(T val)
    {
        Node* n = new Node;

        if (head == nullptr) head = tail = n;
        else
        {
            head->prev = n;
            n->next = head;
            head = n;
        }

        n->val = val;
        _size++;
    }

    template<typename T>
    void List<T>::pushBack(T val)
    {
        Node *n = new Node;

        if (tail == nullptr) head = tail = n;
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }

        n->val = val;
        _size++;
    }

    template<typename T>
    T& List<T>:: back()
    {
        return tail->val;
    }

    template<typename T>
    T& List<T>:: front()
    {
        return head->val;
    }

    template<typename T>
    void List<T>:: clear() {
        while (_size != 0) {
            popBack();
        }
    }

    template<typename T>
    int List<T>:: size()
    {
        return _size;
    }

    template<typename T>
    List<T>::~List() {
        clear();
    }
    */
