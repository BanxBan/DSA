//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX 10
//
///* run this program using the console pauser or add your own getch, system("pause") or input loop */
//
//
//typedef struct {
//	int data[MAX];
//	int front;
//	int rear;
//}CircularQ;
//
//void initQueue (CircularQ *Q){
//	Q->front = 8;
//	Q->rear = 6;
//}
//
//void enqueue(int data, CircularQ *Q){
//	if ((Q->rear + 2) % MAX != Q->front){
//		Q->rear = (Q->rear + 1 ) % MAX;
//		Q->data[Q->rear] = data;
//	}
//}
//
//void dequeue (CircularQ *R){
//	if ((R->rear + 1) % MAX != R->front){
//		R->front = (R->front + 1) % MAX;
//	}
//}


#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
} CircularQ;

void initQueue(CircularQ *Q);
void enqueue(int data, CircularQ *Q);
void dequeue(CircularQ *Q);
void display(CircularQ *Q);

int main() {
    CircularQ Q;
    initQueue(&Q);

    enqueue(1, &Q);
    enqueue(2, &Q);
    enqueue(3, &Q);
    enqueue(4, &Q);
    enqueue(5, &Q);
    dequeue(&Q);
    dequeue(&Q);

    display(&Q);

    return 0;
}

void initQueue(CircularQ *Q) {
    Q->front = 0;
    Q->rear = MAX; // Initialize rear as the last index
}

void enqueue(int data, CircularQ *Q) {
    if ((Q->rear + 1) % MAX != Q->front) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->data[Q->rear] = data;
        printf("%d enqueued to the queue.\n", data);
    } else {
        printf("Queue is full. Cannot enqueue %d.\n", data);
    }
}

void dequeue(CircularQ *Q) {
    if ((Q->rear + 1) % MAX != Q->front) {
        printf("%d dequeued from the queue.\n", Q->data[Q->front]);
        Q->front = (Q->front + 1) % MAX;
    } else {
        printf("Queue is empty. Cannot dequeue.\n");
    }
}

void display(CircularQ *Q) {
    int i = Q->front;
    if (i == Q->rear + 1) {
        printf("Queue is empty. Nothing to display.\n");
    } else {
        printf("Queue elements: ");
        while (i != (Q->rear + 1) % MAX) {
            printf("%d ", Q->data[i]);
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

