#include <iostream>
#include <datastruct.h>
#include <Queue.h>

int main()
{
    List<int> mylist;
    Node<int>* nd[10];
    Node<char>* nd2[10];
    for (int i = 0; i < 10; i++) {
        nd[i] = new Node<int>(100 + i);
        nd2[i] = new Node<char>('A' + i);
        if (i % 2)
            mylist.insertNodeAtHead(nd[i]);
        else
            mylist.insertNodeAtTail(nd[i]);
    }


    mylist.displayList();
    mylist.removeNodeFromHead(nd[3]->getData());
    mylist.displayList();


    Stack<char> mystk;
    mystk.pushStk(nd2[2]);
    mystk.pushStk(nd2[5]);
    mystk.pushStk(nd2[7]);
    mystk.displayStack();
    mystk.popStk();
    mystk.popStk();
    mystk.displayStack();

    Queue<int> myqueue;

    myqueue.Enqueue(nd[7]);
    myqueue.Enqueue(nd[4]);
    myqueue.Enqueue(nd[8]);
    myqueue.Enqueue(nd[2]);
    myqueue.Enqueue(nd[5]);
    myqueue.DisplayQueue();
    myqueue.Dequeue();
    myqueue.Dequeue();
    myqueue.DisplayQueue();
    return 0;
}
