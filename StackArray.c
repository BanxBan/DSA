#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Assuming a maximum size for the stack

typedef struct {
    int data[MAX_SIZE];
    int top;
} StackArrayList;

// Function to initialize the stack
void initStack(StackArrayList *L) {
    L->top = -1;
}

// Function to create a new stack
StackArrayList createStack() {
    StackArrayList stack;
    initStack(&stack);
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(StackArrayList s) {
    return s.top == -1;
}

// Function to check if the stack is full
bool isFull(StackArrayList s) {
    return s.top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
bool stack_push(StackArrayList *s, int elem) {
    if (isFull(*s)) {
        printf("Stack Overflow\n");
        return false;
    }
    s->data[++(s->top)] = elem;
    return true;
}

// Function to pop an element from the stack
bool stack_pop(StackArrayList *s) {
    if (isEmpty(*s)) {
        printf("Stack Underflow\n");
        return false;
    }
    (s->top)--;
    return true;
}

// Function to display the elements of the stack
void display(StackArrayList s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s.top; i++) {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

// Function to visualize the stack
void visualize(StackArrayList s) {
    printf("Stack Visualization:\n");
    printf("Top of Stack\n");
    for (int i = s.top; i >= 0; i--) {
        printf("| %d |\n", s.data[i]);
    }
    printf("Bottom of Stack\n");
}

int main() {
    StackArrayList stack = createStack();
    stack_push(&stack, 10);
    stack_push(&stack, 20);
    stack_push(&stack, 30);
    display(stack);
    visualize(stack);
    stack_pop(&stack);
    display(stack);
    visualize(stack);
    return 0;
}

