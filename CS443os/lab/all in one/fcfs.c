#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid, arrival, burst;
    int completion, waiting, turnaround;
};

// Comparison function for qsort (sort by arrival, then PID)
int cmp(const void *a, const void *b) {
    struct Process *p1 = (struct Process *)a;
    struct Process *p2 = (struct Process *)b;
    if (p1->arrival == p2->arrival)
        return p1->pid - p2->pid;
    return p1->arrival - p2->arrival;
}

int main() {
    int n, cst;
    scanf("%d", &n);
    scanf("%d", &cst);

    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &processes[i].pid, &processes[i].arrival, &processes[i].burst);
    }

    // Sort by arrival time, then PID
    qsort(processes, n, sizeof(struct Process), cmp);

    int currentTime = 0;
    double totalWait = 0, totalTAT = 0, totalBurst = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrival) {
            currentTime = processes[i].arrival; // CPU idle
        }

        int start = currentTime;
        processes[i].waiting = start - processes[i].arrival;
        currentTime += processes[i].burst;
        currentTime += cst; // context switch after process
        processes[i].completion = currentTime;
        processes[i].turnaround = processes[i].completion - processes[i].arrival;

        totalWait += processes[i].waiting;
        totalTAT += processes[i].turnaround;
        totalBurst += processes[i].burst;
    }

    double avgWait = totalWait / n;
    double avgTAT = totalTAT / n;
    int finalCT = processes[n - 1].completion;
    double efficiency = (totalBurst / finalCT) * 100.0;
    double inefficiency = 100.0 - efficiency;

    // Output
    printf("Process Arrival Time Burst Time Completion Time Waiting Time Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d       %d            %d          %d                %d             %d\n",
               processes[i].pid, processes[i].arrival, processes[i].burst,
               processes[i].completion, processes[i].waiting, processes[i].turnaround);
    }

    printf("Average Waiting Time: %.2f\n", avgWait);
    printf("Average Turnaround Time: %.2f\n", avgTAT);
    printf("Efficiency: %.2f\n", efficiency);
    printf("Inefficiency: %.2f\n", inefficiency);

    return 0;
}
//INPUT 
//CONTECT SWITIHING 
// PT AT BT 