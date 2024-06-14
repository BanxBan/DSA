#include <stdio.h>
#include<stdlib.h>

typedef struct {
    char name[10];
    int idNum;
    int age;
} info;

typedef struct node {
    info data;
    struct node* next;
} Node, *NodePtr;

void insertFirst(NodePtr *head, info data) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void displayList(NodePtr head) {
    NodePtr current = head;
    printf("Linked List:\n");
    while (current != NULL) {
        printf("Name: %s, ID: %d, Age: %d\n", current->data.name, current->data.idNum, current->data.age);
        current = current->next;
    }
}

int main() {
    NodePtr head = NULL;

    info data1 = {"John", 1, 25};
    info data2 = {"Alice", 2, 30};

    insertFirst(&head, data1);
    insertFirst(&head, data2);

    displayList(head);

    return 0;
}

