#include <stdio.h>
#include "set.h"

void display_set(Set set) {
    int i; 

    printf("{ ");
    for (i = 0; i < set.size; ++i) {
        printf("%d ", set.elements[i]);
    }
    printf("}\n");
}

int main() {
    Set set1, set2, union_set, intersection_set;
    int i, j; 

    initialize(&set1);
    initialize(&set2);
    initialize(&union_set);
    initialize(&intersection_set);

    
    add(&set1, 1);
    add(&set1, 2);
    add(&set1, 3);
    add(&set1, 4);

    
    add(&set2, 4);
    add(&set2, 6);
    add(&set2, 7);
    add(&set2, 8);

    
    printf("Set 1: ");
    display_set(set1);
    printf("Set 2: ");
    display_set(set2);

    
    find_union(set1, set2, &union_set);
    find_intersection(set1, set2, &intersection_set);

    
    printf("Union: ");
    display_set(union_set);
    printf("Intersection: ");
    display_set(intersection_set);

    return 0;
}

