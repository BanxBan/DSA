#include <stdio.h>
#include "fcfs.h"

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];
    input_processes(processes, n);

    calculate_fcfs(processes, n);
    print_processes(processes, n);

    return 0;
}

