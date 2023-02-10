#include<iostream>
#include <algorithm>
#define N 10
using namespace std;
/*
sample
4
1 0 10 2
2 2 5 1 
3 3 2 0
4 5 20 3

5
1 0 11 2
2 5 28 0
3 12 2 3
4 2 10 1
5 9 16 4
*/
int  p[N], bt[N],at[N],priority[N], ct[N], tat[N], wt[N];
float act=0,awt=0,atat=0;

int main()
{
    int i,j,n;

    printf("Priority Scheduling.... Enter no of process:");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        printf("index[%d]: P ",i);
        scanf("%d", &p[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf(" Burst time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d",&priority[i]);
    }
    
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(at[j]<at[i]){
                std::swap(at[i],at[j]);
                std::swap(bt[i],bt[j]);
                std::swap(priority[i],priority[j]);
                std::swap(p[i],p[j]);
            }     
        }
    }
    printf("\n\np\tat\tbt\tp\tct\ttat\twt\n");

    for(i=1;i<=n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],priority[i],ct[i],tat[i],wt[i]);
    }

    ct[0]=0;

   for(i=1;i<=n;i++)
    {
        int min = i;
        for(j=i;j<=n;j++)
        {
          if((at[j] <= ct[i-1] ) &&( priority[j]<priority[min]))
            {
                min = j;
            }
        std::swap(p[i],p[min]);
        std::swap(bt[i],bt[min]);
        std::swap(at[i],at[min]);
        std::swap(priority[i],priority[min]);


        ct[i] = ct[i-1] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        }

    }

    printf("\n\np\tat\tbt\tp\tct\ttat\twt\n");

    for(i=1;i<=n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],priority[i],ct[i],tat[i],wt[i]);
        act += ct[i];
        awt += wt[i];
        atat += tat[i];
    }
    act = act/n;
    awt = awt/n;
    atat = atat/n;
    printf("\n Average completion time = %f", act);
    printf("\n Average waiting time = %f", awt);
    printf("\n Average turnaround time = %f", atat);
    return 0;
}

