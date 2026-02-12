#include<stdio.h>
#include<stdlib.h>
struct process
{
    int pid, at, bt,ct, tat, wt, rt;
}p[3];

int main(){
    struct process p1;
    int i;
    for(i=0;i<3;i++) {
        printf("Enter AT,BT for P%d \n",i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
    }
    for(i=0;i<3;i++){
    p[i].ct=p[i-1].ct+p[i].bt;
    p[i].tat=p[i].ct-p[i].at;
    p[i].wt=p[i].tat-p[i].bt;
    p[i].rt=p[i-1].ct-p[i].at;
    printf("p%d AT:%d | BT:%d | CT: %d | TAT:%d | WT:%d | RT:%d\n",i+1,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }
}