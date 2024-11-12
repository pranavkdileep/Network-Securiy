#include <stdio.h>

struct process{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};

int main(){
    int n,t=0,totalTAT=0,totalWT=0;
    float avgWT,avgTAT;
    struct process p[10],temp;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the arrival and burst time of process %d: ",i+1);
        scanf("%d %d",&p[i].arrival_time,&p[i].burst_time);
        p[i].pid = i+1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].arrival_time>p[j+1].arrival_time){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    printf("|| 0 ");
    for(int i=0;i<n;i++){
        if(t<p[i].arrival_time){
            t = p[i].arrival_time;
        }
        p[i].completion_time = t + p[i].burst_time;
        p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
        t = p[i].completion_time;
        totalTAT += p[i].turn_around_time;
        totalWT += p[i].waiting_time;

    }
    printf("\n");
    avgTAT = totalTAT/n;
    avgWT = (float)totalWT/n;
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].completion_time,p[i].turn_around_time,p[i].waiting_time);
    }
    printf("Average Turn Around Time: %f\n",avgTAT);
    printf("Average Waiting Time: %f\n",avgWT);
    return 0;

}