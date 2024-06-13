#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stdbool.h>

#define MAX 1
#define TOP -1

typedef struct {
    int data[MAX];
    int top;
} StackArrayList;

// Function declarations
void initStack(StackArrayList *L);
StackArrayList createStack();
bool stack_push(StackArrayList *s, int elem);
bool stack_pop(StackArrayList *s);
void display(StackArrayList s);
void visualize(StackArrayList s);

#endif /* STACK_ARRAY_H */

