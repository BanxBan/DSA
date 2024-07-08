#include <stdio.h>
#include <stdlib.h>
#include "Hashing.h"

int main(int argc, char *argv[]) {
    Dictionary D;
    initDict(D);

    PersonInfo info1 = {{"Smith", "John", 30}, "New York", "Manhattan", 101010};
    PersonInfo info2 = {{"Doe", "Jane", 25}, "Los Angeles", "Hollywood", 202020};
    PersonInfo info3 = {{"Brown", "Charlie", 35}, "Chicago", "Lincoln Park", 303030};
    PersonInfo info4 = {{"Johnson", "Emily", 28}, "Houston", "Midtown", 404040};

    insertSortByAge(D, info1);
    insertSortByAge(D, info2);
    insertSortByAge(D, info3);
    insertSortByAge(D, info4);

    deleteInfoByHouseNo(D, 505050);

    visualize(D);

    return 0;
}

