#include <stdio.h>

struct Process{
     int PID , AT,BT,CT,PRIORITY,TAT,WT;
     int done;
};

int main(){
   
    int n ;
    printf("Enter the number of process : ");
    scanf("%d",&n);

    struct Process p[n];
    
    for (int  i = 0; i < n; i++)
    {
         p[i].PID= i+1;
         printf("Enter the arival time , bust time , priority");
         scanf("%d %d %d" , p[i].AT,p[i].BT,p[i].PRIORITY);
         p[i].done=0;
    }

    int currentTime = 0, completed =0;
    float totalTAT=0 , totalWT=0;

    while (completed<n)
    {
        int idx = -1;
        int highestpriority = 100000;

        for (int  i = 0; i < n; i++)
        {
             if (p[i].AT<=currentTime && p[i].done ==0)
             {
                 if (p[i].PRIORITY < highestpriority)
                 {
                    highestpriority = p[i].PRIORITY;
                    idx=i;
                 }
             }
        }
        if(idx== -1){
            currentTime++;
        }else{
            p[idx].CT = currentTime + p[idx].BT;
            p[idx].TAT = p[idx].CT - p[idx].AT;
            p[idx].WT = p[idx].TAT - p[idx].BT;
            p[idx].done=1;
            completed++;
            currentTime=p[idx].CT;

            totalTAT +=p[idx].TAT;
            totalWT +=p[idx].WT;
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