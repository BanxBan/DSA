#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
#include "StackArray.h"
d 
#include <stdbool.h>

#define MAX 1
#define TOP -1

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

#endif /* STACK_ARRAY_H */

