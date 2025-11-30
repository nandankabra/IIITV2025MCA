#include <stdio.h>

struct Process {
    int pid, arrivalTime, burstTime , priority ,completionTime , turnaroundTime , waitingTime;
    int done;  
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time, burst time, and priority of P%d: ", i+1);
        scanf("%d %d %d", &p[i].arrivalTime, &p[i].burstTime, &p[i].priority);
        p[i].done = 0;  
    }

    int currentTime = 0, completed = 0;
    float totalTAT = 0, totalWT = 0;

    while(completed < n) {
        int idx = -1;
        int highestPriority = 100000;  
 
        for(int i = 0; i < n; i++) {
            if(p[i].arrivalTime <= currentTime && p[i].done == 0) {
                if(p[i].priority < highestPriority) {
                    highestPriority = p[i].priority;
                    idx = i;
                } else if(p[i].priority == highestPriority) {  
                    if(p[i].arrivalTime < p[idx].arrivalTime) {
                        idx = i;
                    }
                }
            }
        }

        if(idx == -1) {  
            currentTime++;
        } else { 
            p[idx].completionTime = currentTime + p[idx].burstTime;
            p[idx].turnaroundTime = p[idx].completionTime - p[idx].arrivalTime;
            p[idx].waitingTime = p[idx].turnaroundTime - p[idx].burstTime;
            p[idx].done = 1;
            completed++;
            currentTime = p[idx].completionTime;

            totalTAT += p[idx].turnaroundTime;
            totalWT += p[idx].waitingTime;
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
                p[i].pid, p[i].arrivalTime, p[i].burstTime, p[i].priority,
                p[i].completionTime, p[i].turnaroundTime, p[i].waitingTime);
    }

    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);
    printf("Average Waiting Time = %.2f\n", totalWT / n);

    return 0;
}
