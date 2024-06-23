#include <stdio.h>
#include "fcfs.h"

void input_processes(Process processes[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }
}

void calculate_fcfs(Process processes[], int n) {
    int i;
    int current_time = 0;

    for (i = 0; i < n; i++) {
        if (processes[i].arrival_time > current_time) {
            current_time = processes[i].arrival_time;
        }
        
        processes[i].completion_time = current_time + processes[i].burst_time;
        current_time += processes[i].burst_time;

        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;

        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

void calculate_averages(Process processes[], int n, float *avg_turnaround_time, float *avg_waiting_time) {
    int i;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;

    for (i = 0; i < n; i++) {
        total_turnaround_time += processes[i].turnaround_time;
        total_waiting_time += processes[i].waiting_time;
    }

    *avg_turnaround_time = (float)total_turnaround_time / n;
    *avg_waiting_time = (float)total_waiting_time / n;
}

void print_processes(Process processes[], int n) {
    int i;
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               processes[i].process_id,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].completion_time,
               processes[i].turnaround_time,
               processes[i].waiting_time);
    }
}

