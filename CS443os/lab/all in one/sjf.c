#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Process {
    int pid, arrival, burst;
    int completion, waiting, turnaround;
    int done;
};

int main() {
    int n, cst;
    scanf("%d", &n);
    scanf("%d", &cst);

    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &processes[i].pid, &processes[i].arrival, &processes[i].burst);
        processes[i].done = 0;
    }

    int completed = 0, currentTime = 0;
    double totalWait = 0, totalTAT = 0, totalBurst = 0;

    while (completed < n) {
        int idx = -1;
        int minBurst = INT_MAX;

        // Find the shortest job available
        for (int i = 0; i < n; i++) {
            if (!processes[i].done && processes[i].arrival <= currentTime) {
                if (processes[i].burst < minBurst ||
                    (processes[i].burst == minBurst && processes[i].arrival < processes[idx].arrival)) {
                    minBurst = processes[i].burst;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            // No process has arrived yet
            int nextArrival = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (!processes[i].done && processes[i].arrival < nextArrival) {
                    nextArrival = processes[i].arrival;
                }
            }
            currentTime = nextArrival;
            continue;
        }

        // Execute the chosen process
        processes[idx].waiting = currentTime - processes[idx].arrival;
        currentTime += processes[idx].burst;
        processes[idx].completion = currentTime;
        processes[idx].turnaround = processes[idx].completion - processes[idx].arrival;

        totalWait += processes[idx].waiting;
        totalTAT += processes[idx].turnaround;
        totalBurst += processes[idx].burst;

        processes[idx].done = 1;
        completed++;

        if (completed < n) {
            currentTime += cst; // add context switching only if not the last process
        }
    }

    double avgWait = totalWait / n;
    double avgTAT = totalTAT / n;
    int finalCT = 0;
    for (int i = 0; i < n; i++) {
        if (processes[i].completion > finalCT) finalCT = processes[i].completion;
    }
    double efficiency = (totalBurst / finalCT) * 100.0;
    double inefficiency = 100.0 - efficiency;

    // Output
    printf("Process Arrival Time Burst Time Completion Time Waiting Time Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%-7d %-12d %-11d %-15d %-13d %-15d\n",
               processes[i].pid, processes[i].arrival, processes[i].burst,
               processes[i].completion, processes[i].waiting, processes[i].turnaround);
    }

    printf("Average Waiting Time: %.2f\n", avgWait);
    printf("Average Turnaround Time: %.2f\n", avgTAT);
    printf("Efficiency: %.2f\n", efficiency);
    printf("Inefficiency: %.2f\n", inefficiency);

    return 0;
}
// input 4
//2
//1 0 5
//2 1 3
//3 2 8
//4 3 6
//Process Arrival Time Burst Time Completion Time Waiting Time Turnaround Time
//1       0            5           5               0             5
//2       1            3           10              6             9
//4       3            6           18              9             15
//3       2            8           28              18            26
//Average Waiting Time: 8.25
//Average Turnaround Time: 13.75
//Efficiency: 78.57
//Inefficiency: 21.43
