#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_PROCESSES 100

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n;
    struct process processes[MAX_PROCESSES];
    bool completed[MAX_PROCESSES] = {false};
    int current_time = 0, completed_count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = 0;
    }

    while (completed_count < n) {
        int shortest_index = -1;
        int shortest_time = INT_MAX;

        // Find process with shortest remaining time at current_time
        for (int i = 0; i < n; i++) {
            if (!completed[i] && processes[i].arrival_time <= current_time) {
                if (processes[i].remaining_time < shortest_time) {
                    shortest_time = processes[i].remaining_time;
                    shortest_index = i;
                }
            }
        }

        if (shortest_index == -1) {
            // No process has arrived yet
            current_time++;
            continue;
        }

        // Execute process for 1 unit
        processes[shortest_index].remaining_time--;
        current_time++;

        // If process finished
        if (processes[shortest_index].remaining_time == 0) {
            processes[shortest_index].completion_time = current_time;
            completed[shortest_index] = true;
            completed_count++;
        }
    }

    // Calculate waiting and turnaround times
    int total_waiting_time = 0, total_turnaround_time = 0;

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;

        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].completion_time,
               processes[i].waiting_time,
               processes[i].turnaround_time);
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\nThe Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("The Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}

/*Enter the number of processes: 4
Enter arrival time and burst time for process 1: 0 7 
Enter arrival time and burst time for process 2: 2 4 
Enter arrival time and burst time for process 3: 4 1
Enter arrival time and burst time for process 4: 5 4

Process AT      BT      CT      WT      TAT
1       0       7       16      9       16
2       2       4       7       1       5
3       4       1       5       0       1
4       5       4       11      2       6

The Average Waiting Time: 3.00
The Average Turnaround Time: 7.00 */