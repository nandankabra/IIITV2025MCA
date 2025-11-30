#include <stdio.h>

struct process {
    int id, at, bt, rt, ct, tat, wt;
};

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct process p[100];
    for(int i=0;i<n;i++) {
        printf("Enter arrival time and burst time of P%d: ",i+1);
        scanf("%d %d",&p[i].at,&p[i].bt);
        p[i].id=i+1;
        p[i].rt=p[i].bt;   // remaining time
        p[i].ct=0;         // completion time
    }

    printf("Enter time quantum: ");
    scanf("%d",&tq);

    int t=0, done=0;
    int q[100], front=0, rear=0; // queue
    int visited[100]={0};

    // push first arrived process
    while(1) {
        int earliest=-1;
        for(int i=0;i<n;i++) {
            if(p[i].at<=t && !visited[i]) {
                q[rear++]=i;
                visited[i]=1;
            }
        }
        if(rear>0) break;
        t++;
    }

    // main loop
    while(done<n) {
        int i=q[front++];  // take process from queue

        if(p[i].rt>tq) {
            t+=tq;
            p[i].rt-=tq;
        } else {
            t+=p[i].rt;
            p[i].rt=0;
            p[i].ct=t;
            done++;
        }

        // add new arrivals to queue
        for(int j=0;j<n;j++) {
            if(p[j].at<=t && !visited[j]) {
                q[rear++]=j;
                visited[j]=1;
            }
        }

        // if unfinished, put it back
        if(p[i].rt>0) {
            q[rear++]=i;
        }

        // idle CPU handling
        if(front==rear && done<n) {
            t++;
            for(int j=0;j<n;j++) {
                if(p[j].at<=t && !visited[j]) {
                    q[rear++]=j;
                    visited[j]=1;
                }
            }
        }
    }

    int twt=0, ttat=0;
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++) {
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        twt+=p[i].wt;
        ttat+=p[i].tat;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }

    printf("\nAverage WT = %.2f",(float)twt/n);
    printf("\nAverage TAT = %.2f\n",(float)ttat/n);

    return 0;
}
