#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct Process
{
    int pid,at,bt,wt,ct,rt,tat;
}P[MAX];
int main()
{
    int i,j,n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("Enter PID, AT and BT of the process : ");
        scanf("%d %d %d",&P[i].pid,&P[i].at,&P[i].bt);
    }

    // Sort by AT and BT
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(P[j].at > P[j+1].at || (P[j].at == P[j+1].at && P[j].bt > P[j+1].bt))
            {
                struct Process temp = P[j];
                P[j] = P[j+1];
                P[j+1] = temp;
            }
        }
    }

    int current_time = 0;
    for(i=0;i<n;i++) // CT 
    {
        if(current_time < P[i].at)
            current_time = P[i].at;
        current_time += P[i].bt;
        P[i].ct = current_time;
    }

    for(i=0;i<n;i++)
    {
        P[i].tat = P[i].ct - P[i].at;
        P[i].wt = P[i].tat - P[i].bt;
        P[i].rt = P[i].wt;
    }

    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",P[i].pid,P[i].at,P[i].bt,P[i].ct,P[i].tat,P[i].wt,P[i].rt);
    }

    printf("GANTTCHART\n[ ");
    for(i=0;i<n;i++)
    {
        printf("P%d ",P[i].pid);
    }
    printf("]\n");
    return 0;
}