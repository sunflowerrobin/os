#include<stdio.h>
#define N 10
/*
4
1 0 7
2 2 4
3 4 1
4 5 4

wt
0 2 7 7
ct
7 8 12 16
tat
7 6 8 11

awt=4
act= 10.75
atat = 8
*/
int  at[N], ct[N], tat[N], wt[N];
float act,awt,atat;
int main()
{
    int temp,i,j,n,p[N], bt[N];

    printf("Shortest job first...... enter no of process:");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        printf("P ");
        scanf("%d", &p[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
    }

    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(at[j]<at[i]){
                temp = p[i];
                p[i]=p[j];
                p[j]=temp;

                temp = bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp = at[i];
                at[i]=at[j];
                at[j]=temp;
            }
        }
    }

    /*printf("\n p\t at\t bt\n");

    for(i=1;i<=n;i++){
        printf("%d\t%d\t%d\n",p[i],at[i],bt[i]);
    }*/

    ct[1]= bt[1]+at[1];
    //printf("%d\n",ct[1]);

    for(i=1;i<=n;i++)
    {
        int min = i;
        for(j=i;j<=n;j++)
        {
            if(at[j] <= ct[i-1] && bt[j] <= bt[min])
            {
                min = j;
            }
        }
        int temp = p[i];
        p[i] = p[min];
        p[min] = temp;

        temp = bt[i];
        bt[i] = bt[min];
        bt[min] = temp;

        temp = at[i];
        at[i] = at[min];
        at[min] = temp;

        ct[i] = ct[i-1] + bt[i];

        tat[i] = ct[i] - at[i];
     //   printf("TAT: %d\n",tat[i]);

        wt[i] = tat[i] - bt[i];

    }

    printf("p\tat\tbt\tct\ttat\twt\n");

    for(i=1;i<=n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
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
//using namespace std;

/*
sample
4
1 7
2 4
3 1
4 4

4
1 0 7
2 2 4
3 4 1
4 5 4
*/
 /*
    for(i=1;i<=n;i++){
        ct[i] = ct[i-1]+ bt[i];
        act += ct[i];
    }
    act/=n;

    for(i=1;i<=n;i++){
        tat[i] = ct[i]-at[i];
        atat += tat[i];
    }
    atat/=n;

    for(i=1;i<=n;i++){
        wt[i] = tat[i]-bt[i];
        awt += wt[i];
    }
    awt/=n;

    printf("Process\tCompletion-Time  Turnaround-Time  Waiting-Time\n");
    for(i=1;i<=n;i++){
        printf("%d\t  %d\t\t\t %d\t\t%d\n",p[i],ct[i],tat[i],wt[i]);
    }

    printf("Average completion Time: %.2f\n",act);
    printf("Average Turnaround Time: %.2f\n",atat);
    printf("Average Waiting Time: %.2f\n",awt);
    */
/*
// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to implement bubble sort
void bubbleSort(int *arr, int n)
{
    int i, j;

    // Traverse through all array elements
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            // Swap adjacent elements if they are in decreasing order
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

 //   bublesort(arr,n);
    return 0;
}

*/
