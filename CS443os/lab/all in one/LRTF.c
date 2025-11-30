#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rem[n], ct[n];
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time of P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rem[i] = bt[i]; // remaining time
        ct[i] = 0;
    }

    int completed = 0, time = 0;
    int earliest = at[0];
    for (i = 1; i < n; i++) if (at[i] < earliest) earliest = at[i];
    time = earliest; // start from earliest arrival

    int timeline[1000]; // timeline for Gantt
    int tpos = 0;

    while (completed < n) {
        int idx = -1;
        int maxRem = -1;

        // choose process with max remaining time that has arrived
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rem[i] > 0) {
                if (rem[i] > maxRem) {
                    maxRem = rem[i];
                    idx = i;
                } else if (rem[i] == maxRem && idx != -1) {
                    if (at[i] < at[idx]) idx = i;
                    else if (at[i] == at[idx] && i < idx) idx = i;
                }
            }
        }

        if (idx == -1) {
            timeline[tpos++] = -1; // idle
            time++;
        } else {
            timeline[tpos++] = idx;
            rem[idx]--;
            time++;

            if (rem[idx] == 0) {
                completed++;
                ct[idx] = time;
            }
        }
    }

    // calculate TAT and WT
    int tat[n], wt[n];
    double totalTAT = 0, totalWT = 0;
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        totalTAT += tat[i];
        totalWT += wt[i];
    }

    // print table
    printf("\n+----+----+----+----+----+----+\n");
    printf("| ID | AT | BT | CT | TAT| WT |\n");
    printf("+----+----+----+----+----+----+\n");
    for (i = 0; i < n; i++) {
        printf("| P%-2d| %-2d | %-2d | %-2d | %-2d | %-2d |\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("+----+----+----+----+----+----+\n");

    printf("\nAverage TAT = %.2f\n", totalTAT/n);
    printf("Average WT  = %.2f\n", totalWT/n);

    // print Gantt chart
    printf("\nGantt Chart:\n");
    int j = 0;
    int startTime = earliest;
    while (j < tpos) {
        int pid = timeline[j];
        int start = j;
        while (j < tpos && timeline[j] == pid) j++;
        int end = j - 1;
        int real_start = startTime + start;
        int real_end = startTime + end + 1;
        if (pid == -1)
            printf("[Idle: %d-%d] ", real_start, real_end);
        else
            printf("[P%d: %d-%d] ", pid+1, real_start, real_end);
    }
    printf("\n");

    return 0;
}
