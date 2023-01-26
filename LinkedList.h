#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "Node.h"

template <class T>
class LinkedList
{
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList<T> &obj);
    ~LinkedList();

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

    int getSize() const;
    bool isEmpty() const;
    bool containsNode(Node<T> *node) const;
    int getIndex(Node<T> *node) const;

    Node<T> *getFirstNode() const;
    Node<T> *getLastNode() const;
    Node<T> *getNode(const T &data) const;
    Node<T> *getNodeAtIndex(int index) const;

    void append(const T &data);
    void prepend(const T &data);
    void insertAfterNode(const T &data, Node<T> *node);
    void insertAtIndex(const T &data, int index);
    void moveToIndex(int currentIndex, int newIndex);

    void removeNode(Node<T> *node);
    void removeNode(const T &data);
    void removeNodeAtIndex(int index);
    void removeAllNodes();

    void print() const;

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

private: // DO NOT CHANGE THIS PART.
    Node<T> *head;
    int size;
};

template<class T>
LinkedList<T>::LinkedList()
{
    /* TODO */
    size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj)
{
    /* TODO */
    size = 0;
    Node<T> *obj_cur = obj.head;
    head = new Node<T>(obj_cur->data);
    head->next = head;
    head->prev = head;
    Node<T>* cur = head; 
    for(int i = 1; i<obj.size; i++)
    {
        obj_cur = obj_cur->next;
        cur->next = new Node<T>(obj_cur->data);
        cur->next->prev = cur;
        cur->next->next = head;
        head->prev = cur->next;
        cur = cur->next; 
    }
    size = obj.size;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    /* TODO */
    (*this).removeAllNodes();
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
    /* TODO */
    (*this).removeAllNodes();
    if(rhs.size == 0) return *this;
    Node<T> *rhs_cur = rhs.head;
    head = new Node<T>(rhs_cur->data);
    head->next = head;
    head->prev = head;
    Node<T>* cur = head; 
    for(int i = 1; i<rhs.size; i++)
    {
        rhs_cur = rhs_cur->next;
        cur->next = new Node<T>(rhs_cur->data);
        cur->next->prev = cur;
        cur->next->next = head;
        head->prev = cur->next;
        cur = cur->next; 
    }
    size = rhs.size;
    return *this;
}

template<class T>
int LinkedList<T>::getSize() const
{
    /* TODO */
    return size;
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
    /* TODO */
    if(size == 0) return true;
    else return false;
}

template<class T>
bool LinkedList<T>::containsNode(Node<T> *node) const
{
    /* TODO */
    if(size == 0)return false;
    Node<T> *cur = head;
    for(int i = 0; i<size; i++)
    {
        if(cur == node) return true;
        cur = cur->next;
    }
    return false;
}

template<class T>
Node<T> *LinkedList<T>::getFirstNode() const
{
    /* TODO */
    if(size == 0) return NULL;
    return(head);
}

template<class T>
Node<T> *LinkedList<T>::getLastNode() const
{
    /* TODO */
    if(size == 0) return NULL;
    return(head->prev);
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const
{
    /* TODO */
    if(size == 0) return NULL;
    Node<T>* cur = head;
    for(int i = 0; i<size; i++)
    {
        if(cur->data == data) return cur;
        cur = cur->next;
    }
    return NULL;
}

template<class T>
Node<T> *LinkedList<T>::getNodeAtIndex(int index) const
{
    /* TODO */
    if(size == 0 || index > size - 1) return NULL;
    if(index < 0) return NULL;
    Node<T> *cur = head;
    for(int i = 0; i<index; i++)
    {
        cur = cur->next;
    }
    return cur;
}

template<class T>
void LinkedList<T>::append(const T &data)
{
    /* TODO */    
    if(size == 0)
    {
        head = new Node<T>(data);
        head->data = data;
        head->next = head;
        head->prev = head;
        size++;
    }
    else
    {
        (*this).insertAfterNode(data, head->prev);
    }

}

template<class T>
void LinkedList<T>::prepend(const T &data)
{
    /* TODO */
    if(size != 0) 
    {
        (*this).insertAfterNode(data, head->prev);
        head = head->prev;
    }
    else
    {
        head = new Node<T>(data);
        head->data = data;
        head->next = head;
        head->prev = head;
        size++;
    }
}

template<class T>
void LinkedList<T>::insertAfterNode(const T &data, Node<T> *node)
{
    /* TODO */
    if(size == 0)return;
    if(!containsNode(node)) return;
    Node<T>* cur = head;
    while(cur != node)
    {
        cur = cur->next;
    }
    Node<T>* new_node = new Node<T>(data, cur, cur->next);
    new_node->data = data;
    new_node->prev = cur;
    new_node->next = cur->next;
    cur->next->prev = new_node;
    cur->next = new_node;
    size++;
}

template<class T>
void LinkedList<T>::insertAtIndex(const T &data, int index)
{
    /* TODO */
    if(index > size) return;
    Node<T>* cur = head;
    for(int i = 0; i<index; i++)
    {
        cur = cur->next;
    }
    (*this).insertAfterNode(data, cur->prev);
}

template<class T>
int LinkedList<T>::getIndex(Node<T> *node) const
{
    /* TODO */
    if(size == 0) return -1;
    Node<T> *cur = head;
    for(int i=0; i<size; i++)
    {
        if(cur == node) return i;
        else cur = cur->next;
    }
    return -1;
}

template<class T>
void LinkedList<T>::moveToIndex(int currentIndex, int newIndex)
{
    /* TODO */
    if(currentIndex > size) return;
    if(size == 1) return;
    if(newIndex > size) newIndex = size;
    Node<T>* insert = head;
    for(int i = 0; i<currentIndex; i++)
    {
        insert = insert->next;
    }
    Node<T>* cur = head;
    for(int i = 0; i<newIndex; i++)
    {
        cur = cur->next;
    }
    insert->prev->next = insert->next; // combining old befores next and after
    insert->next = cur->next; // combining the node's next with news after
    cur->next->prev = insert; // combinin the news afters prev with the node
    insert->prev->next->prev = insert->prev; // combinin old afters prev with the old before
    cur->next = insert;
    insert->prev = cur;
    head = getFirstNode();
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    /* TODO */
    if(!containsNode(node)) return;
    if(size == 1)
    {
        head->next = NULL;
        head->prev = NULL;
        delete head;
        size--;
        return;
    }
    Node<T>* cur = head;
    Node<T>* temp = head->next;
    Node<T>* temp2 = head;
    while(cur != node)
    {
        cur = cur->next;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    cur->next = NULL;
    cur->prev = NULL;
    delete cur;
    size--;
    if(temp2 == node)
    {
        head = temp;
    }
}

template<class T>
void LinkedList<T>::removeNode(const T &data)
{
    /* TODO */
    if(getNode(data) == NULL) return;
    while(getNode(data) != NULL)
    {
        removeNode(getNode(data));
    }
}

template<class T>
void LinkedList<T>::removeNodeAtIndex(int index)
{
    /* TODO */
    if(index >= size) return;
    removeNode(getNodeAtIndex(index));
}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    /* TODO */
    if(size == 0)return;
    int csize = size;
    for(int i = 0; i<csize; i++)
    {
        removeNodeAtIndex(csize-1-i);
    }
    size = 0;
}

template<class T>
void LinkedList<T>::print() const
{
    if (this->isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node<T> *node = this->getFirstNode();

    do {
        std::cout << *node << std::endl;
        node = node->next;
    }
    while (node != this->getFirstNode());
}

#endif //LINKEDLIST_H
