#include <stdio.h>
#include "MyQueue.h"

int main() {
    // Create a new queue
    QueueLinkedList queue;
    initQueue(&queue);

    // Enqueue elements
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    // Display the elements in the queue
    printf("Queue elements after enqueuing: ");
    Node* current = queue.front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Dequeue an element
    dequeue(&queue);

    // Display the elements in the queue after dequeuing
    printf("Queue elements after dequeuing: ");
    current = queue.front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}

