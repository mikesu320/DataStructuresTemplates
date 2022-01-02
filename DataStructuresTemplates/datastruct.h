#pragma once

#ifndef DATASTRUCT_H_INCLUDED
#define DATASTRUCT_H_INCLUDED



using namespace std;

template <typename T>
class Node {
    T data;
     Node* next;
     Node* prev;
public:
    Node(T i) { next = NULL; prev = NULL; data = i; }
    void setNext(Node* nd) { next = nd; }
    void setPrev(Node* nd) { prev = nd; }
    Node* getNext() { return next; }
    T getData() { return data; }
};

template <typename T>
class Stack {
    Node<T>* top = NULL;
    int size = 0;
public:
    Stack() {}
    ~Stack();
public:
    void pushStk(Node<T>* nd);
    Node<T>* popStk();
    int getSize() { return size; }
    void displayStack();
};

template <typename T>
Stack<T>::~Stack() {
    if (!top) return;
    Node<T>* nd, * tmp = top;
    while (tmp) {
        nd = tmp;
        tmp = tmp->getNext();
        delete nd;
    }
}

template <typename T>
void Stack<T>::displayStack() {
    Node<T>* nd = top;
    if (!nd) return;
    int cnt = 0;
    cout << "stack==>";
    while (nd) {
        cout << cnt++ << " " << nd->getData() << " ";
        nd = nd->getNext();
    }
    cout << endl;
}

template <typename T>
void Stack<T>::pushStk(Node<T>* nd) {
    if (!top)
        top = nd;
    else {
        nd->setNext(top);
        top = nd;
    }
    size++;
}

template <typename T>
Node<T>* Stack<T>::popStk() {
    Node<T>* nd = top;
    top = nd->getNext();
    size--;
    return nd;
}

template <typename T>
class List {
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    List() { head = NULL; tail = NULL; size = 0; }
    int isEmpty() { return (size == 0); }
    void insertNodeAtHead(Node<T>* nd);
    void insertNodeAtTail(Node<T>* nd);
    Node<T>* removeNodeFromHead(T);
    Node<T>* removeHead();
    void displayList();
    Node<T>* iterate();

};
template <typename T>
void List<T>::displayList() {
    if (isEmpty())
        return;
    int cnt = 0;
    Node<T>* nd = this->head;
    while (nd) {
        cout << "list[" << cnt++ << "]=" << nd->getData() << " ";
        nd = nd->getNext();
    }
    cout << endl;
}

template <typename T>
void List<T>::insertNodeAtHead(Node<T>* nd) {
    if (!isEmpty()) {
        nd->setNext(head);
        head = nd;
    }
    else {
        nd->setNext(NULL);
        head = nd;
        tail = nd;
    }
    size++;
}

template <typename T>
void List<T>::insertNodeAtTail(Node<T>* nd) {
    if (!isEmpty()) {
        tail->setNext(nd);
        tail = nd;
        nd->setNext(NULL);
    }
    else {
        nd->setNext(NULL);
        head = nd;
        tail = nd;
    }
    size++;
}

template <typename T>
Node<T>* List<T>::removeHead() {
    if (isEmpty()) return NULL;
    Node<T>* nd = head;
    head = nd->getNext();
    size--;
    return nd;
}

template <typename T>
Node<T>* List<T>::removeNodeFromHead(T data) {
    if (this->isEmpty()) return NULL;
    Node<T>* nd = this->head;
    Node<T>* prev = NULL;
    while (nd) {
        if (nd->getData() == data) {
            if (prev == NULL)
                this->head = nd->getNext();
            else
                prev->setNext(nd->getNext());
            size--;
            return nd;
        }
        prev = nd;
        nd = nd->getNext();
    }
    return NULL;
}


#endif // DATASTRUCT_H_INCLUDED
