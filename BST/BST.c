#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"  // Include your BST header file here

NodePtr add(NodePtr root, Product item) {
    if (root == NULL) {
        root = (NodePtr)malloc(sizeof(NodeType));
        root->item = item;
        root->left = root->right = NULL;
    } else if (strcmp(item.prodName, root->item.prodName) < 0) {
        root->left = add(root->left, item);
    } else {
        root->right = add(root->right, item);
    }
    return root;
}

NodePtr minvalueNode(NodePtr node) {
    NodePtr current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

NodePtr delete(NodePtr root, char *prodName) {
    if (root == NULL) return root;

    if(strcmp(prodName, root->item.prodName) < 0 ) {
        root->left = delete(root->left, prodName);
    } else if(strcmp(prodName, root->item.prodName) > 0) {
        root->right = delete(root->right, prodName);
    } else {
        if(root->left == NULL) {
            NodePtr temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            NodePtr temp = root->left;
            free(root);
            return temp;
        }

        NodePtr temp = minvalueNode(root->right);
        root->item = temp->item;
        root->right = delete(root->right, temp->item.prodName);
    }
    return root;
}

void inorder(NodePtr root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s ", root->item.prodName);
        inorder(root->right);
    }
}

void preorder(NodePtr root) {
    if (root != NULL) {
        printf("%s ", root->item.prodName);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NodePtr root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->item.prodName);
    }
}

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, NodePtr treeNode) {
    QueueNodePtr newNode = (QueueNodePtr)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

NodePtr dequeue(Queue *q) {
    if (isEmpty(q)) return NULL;
    QueueNodePtr temp = q->front;
    NodePtr treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return treeNode;
}

void BFS(NodePtr root) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        NodePtr current = dequeue(&q);
        printf("%s ", current->item.prodName);
        if (current->left != NULL) enqueue(&q, current->left);
        if (current->right != NULL) enqueue(&q, current->right);
    }
}

