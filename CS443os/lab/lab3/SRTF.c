#include <stdio.h>
#include <stdbool.h>
struct process
{
    int id, at, bt, ct, tat, wt, rt;
};

int main()
{
    int n;
    printf("Enter number of processes: "); // ya par hume no of process ka input lare hai
    scanf("%d", &n);
    struct process p[100];
    bool done[100] = {false};
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time of process %d: ", i + 1); // ya per hume sari process ka at and bt lare hai
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].id = i + 1;
        p[i].rt = p[i].bt;
    }
    int t = 0, finshed = 0;
    while (finshed < n)
    {
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= t && !done[i])
            {
                if (idx == -1 || p[i].rt < p[idx].rt)
                {
                    idx = i;
                }
            }
        }
        if (idx == -1)
        {
            t++;
            continue;
        }
        p[idx].rt--;
        t++;
        if (p[idx].rt == 0) /// ya par hume tat or wt ki calucaltion kare hai
        {
            done[idx] = true;
            p[idx].ct = t;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            finshed++;
        }
    }
    // ab hume y  par ouptu ko dispklay kare  ga
    int twt = 0, ttat = 0;
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        twt += p[i].wt;
        ttat += p[i].tat;
    }
    // ya par hume avg wt and avg tat ki calculation kare hai
    printf("\nAvg Wt = %.2f", (float)twt / n);
    printf("\nAvg TAT = %.2f", (float)ttat / n);

    return 0;
}
