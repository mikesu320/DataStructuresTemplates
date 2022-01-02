#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <datastruct.h>


template <typename T>
class Queue
{
    List<T>* myq;
public:
    Queue() { myq = new List<T>(); };
    virtual ~Queue() {};
    void Enqueue(Node<T>* nd);
    Node<T>* Dequeue();
    void DisplayQueue();
    bool isEmpty() { return myq->isEmpty(); }
};

template <typename T>
void Queue<T>::Enqueue(Node<T>* nd) {
    myq->insertNodeAtTail(nd);
}

template <typename T>
Node<T>* Queue<T>::Dequeue() {
    return myq->removeHead();
}

template <typename T>
void Queue<T>::DisplayQueue() {
    myq->displayList();
}
#endif // QUEUE_H
