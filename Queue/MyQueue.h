#ifndef MYQUEUE_H
#define MYQUEUE_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} QueueLinkedList;

void initQueue(QueueLinkedList* q);
void enqueue(QueueLinkedList* q, int data);
void dequeue(QueueLinkedList* q);

#endif /* MYQUEUE_H */

