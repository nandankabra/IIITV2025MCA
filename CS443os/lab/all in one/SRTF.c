#include <stdio.h>
#include <stdbool.h>

struct process {
    int id;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[100];
    bool done[100] = {false};

    for(int i=0;i<n;i++) {
        printf("Enter arrival and burst time of P%d: ",i+1);
        scanf("%d %d",&p[i].at,&p[i].bt);
        p[i].id = i+1;
        p[i].rt = p[i].bt;
    }

    int t=0, finished=0;

    while(finished<n) {
        int idx=-1;
        for(int i=0;i<n;i++) {
            if(!done[i] && p[i].at<=t) {
                if(idx==-1 || p[i].rt < p[idx].rt) {
                    idx=i;
                }
            }
        }

        if(idx==-1) {
            t++;
            continue;
        }

        p[idx].rt--;
        t++;

        if(p[idx].rt==0) {
            done[idx]=true;
            p[idx].ct=t;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;
            finished++;
        }
    }

    int twt=0, ttat=0;
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        twt+=p[i].wt;
        ttat+=p[i].tat;
    }

    printf("\nAvg WT=%.2f",(float)twt/n);
    printf("\nAvg TAT=%.2f\n",(float)ttat/n);

    return 0;
}
