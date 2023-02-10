#include<stdio.h>
#include<bits/stdc++.h>
#include<algorithm>
/*4
1 0 5 3
2 2 4 0
3 4 1 1
4 5 6 2
*/
using namespace std;

struct Process
{
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int priority;
    int temBt;
};
/*
bool sortByArrival(Process a, Process b)
{
    return a.at < b.at;
}
*/
int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process p[n+1];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter the process id, arrival time, burst time and priority for process " ;
         cin >> p[i].id >> p[i].at >> p[i].bt >> p[i].priority;
    }

   // sort(p, p+n, sortByArrival);
    
    for(int i=0;i<n;i++){
        p[i].temBt = p[i].bt;
    }
/*
    cout<<"Process\tat\ttemBt\tbt\tprio\n";
    for(int i=0;i<n;i++){
        cout<<p[i].id<<"\t"<<p[i].at<<"\t"<<p[i].temBt<<"\t"<<p[i].bt<<"\t"<<p[i].priority<<endl;
    }
*/
    float act=0,awt=0,atat=0;
    int min=0;
    int t =0,count=0;
    p[n+1].priority=10000;
    for(t=0;count!=n;t++)
    {
        // int next_process = current_process + 1;
        min = n+1;

        for(int j = 0 ; j <n; j++)
        {

            if((p[min].priority > p[j].priority)&& (p[j].at<=t)&& (p[j].bt>0))
            {
                min = j;
            }
        }
            p[min].bt -=1;

            if(p[min].bt == 0){
            count++;
            p[min].tat =t+1-p[min].at;
            p[min].wt = t +1-p[min].at- p[min].temBt;
            p[min].ct = p[min].tat+p[min].at;
           
            awt+=p[min].wt;
            atat+=p[min].tat;
            act+=p[min].ct;
        }
        
    
    }
/*
    for(int i = 0; i < n; i++)
    {
        turnaround_time[i] = completion_time[i] - p[i].at;
        waiting_time[i] = turnaround_time[i] - p[i].bt;
    }
*/  
    atat/=n;
    awt/=n;
    act/=n;
    cout << "Process id\tCompletion Time\tTurnaround Time\tWaiting Time" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << p[i].id << "\t\t" << p[i].ct << "\t\t" << p[i].tat << "\t\t" << p[i].wt << endl;
    }

    cout<<"\n\nAverage waiting time ="<<awt<<endl;
    cout<<"Average Turnaround time ="<<atat<<endl;
    cout<<"Average completion time ="<<act<<endl;

    return 0;
}
