#include<iostream>
using namespace std;
int main()
{
    int bt[100],wt[100],tat[100],avg_wt=0,avg_tat=0;
    int n,i,j;
    cout<<"Enter total number of processes:";
    cin>>n;
 
    cout<<"Enter the burst time of process\t";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
    }
    wt[0]=0;    
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avg_wt+=wt[i];
        avg_tat+=tat[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }
    avg_wt/=i;
    avg_tat/=i;
    cout<<"\n\nAverage Waiting Time:"<<avg_wt;
    cout<<"\nAverage Turnaround Time:"<<avg_tat;
 
    return 0;
}
