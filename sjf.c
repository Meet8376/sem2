#include<stdio.h>
int main() {
    int n,i,j;
    int bt[20],p[20],wt[20],tat[20];
    float avg_wt=0,avg_tat=0;
    int temp;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        p[i]=i+1;
        printf("Enter Burst Time for P%d: ",i+1);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(bt[i]>bt[j]) {
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    wt[0]=0;
    for(i=1;i<n;i++) {
        wt[i]=wt[i-1]+bt[i-1];
    }
    for(i=0;i<n;i++) {
        tat[i]=wt[i]+bt[i];
        avg_wt+=wt[i];
        avg_tat+=tat[i];
    }
    avg_wt/=n;
    avg_tat/=n;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++) {
        printf("\nP%d\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f",avg_tat);
    //dsbibvkjdsnlk
    return 0;
}
