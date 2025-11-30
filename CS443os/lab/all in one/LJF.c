#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;     // process id (1..n)
    int at;     // arrival time
    int bt;     // burst time
    int ct;     // completion time
    int tat;    // turnaround time
    int wt;     // waiting time
    int done;   // 0 = not done, 1 = done
} Process;

int main() {
    int n;
    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    Process *p = malloc(sizeof(Process) * n);
    if (!p) return 1;

    for (int i = 0; i < n; ++i) {
        p[i].id = i + 1;
        printf("Enter arrival and burst time of P%d: ", p[i].id);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].ct = p[i].tat = p[i].wt = 0;
        p[i].done = 0;
    }

    int completed = 0;
    int time = 0;
    double total_tat = 0.0, total_wt = 0.0;

    // If there are processes that start later than 0, move time to earliest arrival
    int earliest_at = p[0].at;
    for (int i = 1; i < n; ++i) if (p[i].at < earliest_at) earliest_at = p[i].at;
    if (time < earliest_at) time = earliest_at;

    while (completed < n) {
        // find the index of the arrived, not-done process with maximum burst time
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (!p[i].done && p[i].at <= time) {
                if (idx == -1) idx = i;
                else if (p[i].bt > p[idx].bt) idx = i;
                else if (p[i].bt == p[idx].bt) {
                    // tie-breaker: smaller arrival time first
                    if (p[i].at < p[idx].at) idx = i;
                    // if still tie, smaller id
                    else if (p[i].at == p[idx].at && p[i].id < p[idx].id) idx = i;
                }
            }
        }

        if (idx == -1) {
            // no process has arrived yet; advance time to next arrival
            int next_at = -1;
            for (int i = 0; i < n; ++i) {
                if (!p[i].done) {
                    if (next_at == -1 || p[i].at < next_at) next_at = p[i].at;
                }
            }
            time = next_at; // move to earliest not-yet-arrived process
            continue;
        }

        // schedule process idx (non-preemptive)
        time += p[idx].bt;
        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;
        p[idx].done = 1;
        completed++;

        total_tat += p[idx].tat;
        total_wt  += p[idx].wt;
    }

    // Print table
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; ++i) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage TAT = %.2f\n", total_tat / n);
    printf("Average WT  = %.2f\n", total_wt  / n);

    free(p);
    return 0;
}
