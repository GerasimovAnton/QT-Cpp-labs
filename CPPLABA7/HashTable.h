#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "list.h"


template<typename t_key,typename t_value>
class HashTable
{

private:
    int hash(t_key key)
    {
        return (int)key%size;
    }

    class Node
    {
    public:
        t_key key;
        t_value value;

        Node(t_key k,t_value v)
        {
            key = k;
            value = v;
        }
    };

    List<Node*>** arr;
    int size;
public:
    HashTable(int size)
    {
        arr = new List<Node*>*[size];
        this->size = size;

        for(int i = 0;i < size;i++)
        {
            arr[i] = new List<Node*>();
        }
    }
    ~HashTable()
    {
        for(int i = 0;i < size;i++)
        {
            arr[i]->clear();
            delete *arr[i];
        }

        delete [] arr;
    }


    void add(t_key key,t_value value)
    {
        Node *n = new Node(key,value);
        arr[hash(key)]->pushBack(n);
    }

    t_value get(t_key key)
    {
        int i = hash(key);

        List<Node *> *l = arr[i];

        for(Node *n: *l)
        {
             if(n->key == key) return n->value;
        }

        //return 0;
    }
};


#endif // HASHTABLE_H
