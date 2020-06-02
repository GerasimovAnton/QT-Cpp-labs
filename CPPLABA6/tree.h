#pragma once
#include <iostream>
#include "list.h"

template<typename ktype, typename vtype>

class Tree
{

private:
    class Node
    {
    public:
        ktype key;
        vtype value;
        Node* root = nullptr,
            * left = nullptr,
            * right = nullptr;

        int height;

        Node(ktype key, vtype value, Node* root)
        {
            this->key = key;
            this->value = value;
            this->root = root;

            height = 1;
        }

        Node(Node & other)
        {
            this->key = other.key;
            this->value = other.value;
            this->left= other.left;
            this->right = other.right;
            this->root = other.root;

            height = 1;
        }

        int bfactor()
        {
            int hl = left ? left->height : 0;
            int hr = right ? right->height : 0;
            return hr - hl;
        }

        void fixheight()
        {
            int hl = left ? left->height : 0;
            int hr = right ? right->height : 0;
            height = (hl > hr ? hl : hr) + 1;
        }

        void add(ktype key, vtype value)
        {
            Node* n = new Node;

            n->root = this;
            n->value = value;

            if (this->key > key)
            {
                if (this->left != nullptr)
                {
                    this->left.add(key, value);
                    delete n;
                }
                else this->left = n;
            }
            else
            {
                if (this->right != nullptr)
                {
                    this->tight.add(key, value);
                    delete n;
                }
                else this->right = n;
            }
        }
    };
    Node* mainRoot;
    int size = 0;

    void NLR(Node* n,List<vtype> &l)
    {
        if (n == nullptr) return;
        l.pushBack(n->value);

        NLR(n->left,l);
        NLR(n->right,l);
    }

    void LRN(Node* n,List<vtype> &l)
    {
        if (n == nullptr) return;
        LRN(n->left,l);
        LRN(n->right,l);
        l.pushBack(n->value);
    }

    void LNR(Node* n,List<vtype> &l)
    {
        if (n == nullptr) return;
        LNR(n->left,l);
        l.pushBack(n->value);
        LNR(n->right,l);
    }

    Node* rotateRight(Node* n)
    {
        Node* p = n->left;
        n->left = p->right;

        if (p->right != nullptr)
            p->right->root = n->left;

        p->right = n;
        p->root = n->root;
        n->root = p;

        n->fixheight();
        p->fixheight();

        return p;
    }

    Node* rotateLeft(Node* n)
    {
        Node* p = n->right;
        n->right = p->left;

        if(p->left != nullptr)
        p->left->root = n->right;

        p->left = n;
        p->root = n -> root;
        n->root = p;

        n->fixheight();
        p->fixheight();

        return p;
    }

    Node* add(Node* p, ktype k,vtype v)
    {
        if( !p ) return new Node(k,v,p);
        if( k < p->key)
            p->left = add(p->left,k,v);
        else
            p->right = add(p->right,k,v);
        return balance(p);
    }

    Node* del(Node* p, ktype k)
    {
        if( !p ) return 0;
        if( k < p->key )
            p->left = del(p->left,k);
        else if( k > p->key )
            p->right = del(p->right,k);
        else
        {
            Node* q = p->left;
            Node* r = p->right;
            delete p;
            if( !r ) return q;
            Node* min = findmin(r);
            min->right = removemin(r);
            min->left = q;
            return balance(min);
        }
        return balance(p);
    }

    Node* findmin(Node* p)
    {
        return p->left?findmin(p->left):p;
    }

    Node* removemin(Node* p)
    {
        if( p->left==nullptr )
            return p->right;
        p->left = removemin(p->left);
        return balance(p);
    }

    Node* balance(Node *n)
    {
        n->fixheight();

        if (n->bfactor() == 2)
        {
            if (n->right->bfactor() < 0)
                n->right = rotateRight(n->right);
            return rotateLeft(n);
        }
        if (n->bfactor() == -2)
        {
            if (n->left->bfactor() > 0)
                n->left = rotateLeft(n->left);
            return rotateRight(n);
        }

        return n;
    }

    bool isKey(Node* n,ktype key)
    {
        if(n == nullptr) return false;
        if(n->key == key) return true;

        else if(n->key < key) return isKey(n->right,key);
        else if(n->key > key )return isKey(n->left,key);
    }

    vtype& get(Node *n,ktype key)
    {
        if(n == nullptr) return NULL;
        if(n->key == key) return n->value;

        if(n->key < key)  get(n->right,key);
        else if(n->key > key ) get(n->left,key);
    }


public:

    Tree()
    {
        mainRoot = nullptr;
    }

    int Height()
    {
        return mainRoot->height;
    }

    int Size()
    {
        return size;
    }

    void addElement(ktype k,vtype v)
    {
        mainRoot = add(mainRoot,k,v);
        size++;
    }

    void deleteElement(ktype k)
    {
        if(isKey(mainRoot,k)){
            mainRoot = del(mainRoot,k);
            size--;
        }
    }

    void leftToRight(List<vtype> &l){
        NLR(mainRoot,l);
    }

    void rightToLeft(List<vtype> &l) {
        LRN(mainRoot,l);
    }

    void sorted(List<vtype> &l) {
        LNR(mainRoot,l);
    }

    vtype& getElement(ktype key)
    {
        return get(mainRoot,key);
    }

};
