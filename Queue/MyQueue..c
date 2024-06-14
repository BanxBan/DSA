#include <stdio.h>
#include <stdlib.h>
#include "MyQueue.h"

// Function to initialize the queue
void initQueue(QueueLinkedList* q) {
    q->front = q->rear = NULL;
}

// Function to enqueue an element into the queue
void enqueue(QueueLinkedList* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to dequeue an element from the queue
void dequeue(QueueLinkedList* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    Node* temp = q->front;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
}


typedef struct node {
	int data;
	struct node * next;
}Node, NodePTr*;

typedef struct {
	
};
