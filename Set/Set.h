#ifndef SET_H
#define SET_H

#define MAX_SIZE 100

typedef struct {
    int elements[MAX_SIZE];
    int size;
} Set;

void initialize(Set *set);
void add(Set *set, int element);
void delete(Set *set, int element);
void find_union(Set set1, Set set2, Set *result);
void find_intersection(Set set1, Set set2, Set *result);

#endif 

