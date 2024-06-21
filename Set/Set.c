#include "set.h"
#include <stdio.h>

void initialize(Set *set) {
    set->size = 0;
}

void add(Set *set, int element) {
    int i; 

    if (set->size < MAX_SIZE) {
        for (i = 0; i < set->size; ++i) {
            if (set->elements[i] == element) {
                return; 
            }
        }
        set->elements[set->size++] = element;
    } else {
        printf("Set is full. Cannot add more elements.\n");
    }
}

void delete(Set *set, int element) {
    int i, j; 

    for (i = 0; i < set->size; ++i) {
        if (set->elements[i] == element) {
            for (j = i; j < set->size - 1; ++j) {
                set->elements[j] = set->elements[j + 1];
            }
            set->size--;
            return;
        }
    }
    printf("Element %d not found in set.\n", element);
}

void find_union(Set set1, Set set2, Set *result) {
    initialize(result);

    int i; 
    for (i = 0; i < set1.size; ++i) {
        add(result, set1.elements[i]);
    }
    
    for (i = 0; i < set2.size; ++i) {
        add(result, set2.elements[i]);
    }
}

void find_intersection(Set set1, Set set2, Set *result) {
    initialize(result);

    int i, j;

    for (i = 0; i < set1.size; ++i) {
        for (j = 0; j < set2.size; ++j) {
            if (set1.elements[i] == set2.elements[j]) {
                add(result, set1.elements[i]);

                break; 

            }
        }
    }
}

