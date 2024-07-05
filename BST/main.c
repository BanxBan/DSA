#include "BST.h"

int main() {
    NodePtr root = NULL;

    Product p1 = {"Banana", 1.5, 10, {1, 1, 2025}};
    Product p2 = {"Saging", 2.5, 12, {2, 5, 2027}};
    Product p3 = {"Plantains", 3.5, 14, {3, 10, 2029}};

    root = add(root, p1);
    root = add(root, p2);
    root = add(root, p3);

    printf("In-Order Traversal:");
    inorder(root);
    printf("\n");

    printf("Pre-Order Traversal:");
    preorder(root);
    printf("\n");

    printf("Post-Order Traversal:");
    postorder(root);
    printf("\n");

    printf("Breadth-First Search (BFS) Traversal:");
    BFS(root);
    printf("\n");

    root = delete(root, "Banana");

    printf("In-Order Traversal after deleting Banana:");
    inorder(root);
    printf("\n");

    return 0;
}

