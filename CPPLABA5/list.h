#ifndef LIST_H
#define LIST_H

template<typename T>
class List
{
private:

    int _size = 0;

    struct Node
    {
        Node* prev = nullptr;
        Node* next = nullptr;
        T val;
    };

    Node _end;
    Node *head = nullptr;
    Node *tail = nullptr;

    void clear() {
        while (_size != 0) {
            popBack();
        }
    }

    void Update_end()
    {
        _end.prev=tail;
        if(tail!=nullptr) tail->next=&_end;
    };

public:
    List()
    {

    }
    ~List() {
        clear();
    }

    int size()
    {
        return _size;
    }

    void popBack()
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

    void popFront()
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
        Update_end();
    }

    void pushFront(T val)
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
        Update_end();
    }

    void pushBack(T val)
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
        Update_end();
    }

    T& back()
    {
        return tail->val;
    }

    T& front()
    {
        return head->val;
    }

    class Iter {
        public:
            Iter(Node* PtrOther)
            {
                Ptr = PtrOther;
            }

            bool operator!= (Iter& other)
            {
                return Ptr != other.Ptr;
            }

            T& operator* ()
            {
                return Ptr->val;
            }

            Iter& operator++()
            {
                Ptr = Ptr->next;
                return *this;
            }

            Iter& operator--()
            {
                Ptr = Ptr->prev;
                return *this;
            }

        private:
            Node* Ptr = nullptr;

     };

    Iter end()
    {
        return Iter((&_end));
        //return Iter(const_cast<Node*>(&_end));
    }

    Iter begin()
    {
        if(head==nullptr) return end();
        return Iter(head);
    }

};

#endif // LIST_H
