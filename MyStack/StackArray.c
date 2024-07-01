#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Assuming a maximum size for the stack

typedef struct {
    int data[MAX_SIZE];
    int top;
} StackArrayList;

void initStack(StackArrayList *L) {
    L->top = -1;
}

StackArrayList createStack() {
    StackArrayList stack;
    initStack(&stack);
    return stack;
}

bool isEmpty(StackArrayList s) {
    return s.top == -1;
}

bool isFull(StackArrayList s) {
    return s.top == MAX_SIZE - 1;
}

bool stack_push(StackArrayList *s, int elem) {
    if (isFull(*s)) {
        printf("Stack Overflow\n");
        return false;
    }
    s->data[++(s->top)] = elem;
    return true;
}

bool stack_pop(StackArrayList *s) {
    if (isEmpty(*s)) {
        printf("Stack Underflow\n");
        return false;
    }
    (s->top)--;
    return true;
}
void display(StackArrayList s) {
    int i; 
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (i = 0; i <= s.top; i++) {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

void visualize(StackArrayList s) {
    printf("Stack Visualization:\n");
    printf("Top of Stack\n");
    int i; 
    for (i = s.top; i >= 0; i--) {
        printf("| %d |\n", s.data[i]);
    }
    printf("Bottom of Stack\n");
}


