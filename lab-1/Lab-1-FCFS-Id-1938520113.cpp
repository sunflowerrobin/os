#include<iostream>
#include<string.h>
#define N 10
//using namespace std;
/*
4
1 0 18
2 1 3
3 2 3
4 3 6

ct
18 21 24 30
tat
18 20 22 27
wt
0 17 19 21

act = 23.25
atat = 21.75
awt =
*/

int  at[N], ct[N], tat[N], wt[N];
float act,awt,atat;

int main()
{
    int i,n,p[N], bt[N];
    printf("Enter Process no: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("P ");
        scanf("%d", &p[i]);
        printf("Arrival time: ");
        scanf("%d",&at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
    }

    for(i=1;i<=n;i++)
    {
        ct[i] = ct[i-1]+ bt[i];
        act += ct[i];
    }
    act/=n;

    for(i=1;i<=n;i++)
    {
        tat[i] = ct[i]-at[i];
        atat += tat[i];
    }
    atat/=n;

    for(i=1;i<=n;i++)
    {
        wt[i] = tat[i]-bt[i];
        awt += wt[i];
    }
    awt/=n;
    printf("Process\tCompletion-Time  Turnaround-Time  Waiting-Time\n");

    for(i=1;i<=n;i++)
    {
        printf("%d\t  %d\t\t\t %d\t\t%d\n",i,ct[i],tat[i],wt[i]);
    }

    printf("Average completion Time: %.2f\n",act);
    printf("Average Turnaround Time: %.2f\n",atat);
    printf("Average Waiting Time: %.2f\n",awt);

    return 0;
}
