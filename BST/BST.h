#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char prodName[20];
    float prodPrice;
    int prodQty;
    Date expDate;
} Product;

typedef struct node {
    Product item;
    struct node *left, *right;
} NodeType, *NodePtr;

typedef struct queueNode {
    NodePtr treeNode;
    struct queueNode *next;
} QueueNode, *QueueNodePtr;

typedef struct {
    QueueNodePtr front, rear;
} Queue;

NodePtr add(NodePtr root, Product item);
NodePtr delete(NodePtr root, char *prodName);
void inorder(NodePtr root);
void preorder(NodePtr root);
void postorder(NodePtr root);
void BFS(NodePtr root);

void initQueue(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, NodePtr treeNode);
NodePtr dequeue(Queue *q);

#endif /* BST_H */

