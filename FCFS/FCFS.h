#ifndef FCFS_H
#define FCFS_H

typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

void calculate_fcfs(Process processes[], int n);
void print_processes(Process processes[], int n);
void input_processes(Process processes[], int n);
void calculate_averages(Process processes[], int n, float *avg_turnaround_time, float *avg_waiting_time);

#endif // FCFS_H

