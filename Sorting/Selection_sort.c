#include<stdio.h>
#include<time.h>
#include<stdlib.h>
# define n 100
int arr[n];

void main()
{
    int imin;
    clock_t start,end;
    double time_taken;
    int temp;
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100;
    }
    start=clock();
    for(int i=0;i<n;i++)
    {
        imin=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[imin])
            {
                imin=j;
            }
        }
        temp=arr[imin];
        arr[imin]=arr[i];
        arr[i]=temp;
    }
    end=clock();
    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken is:%f",time_taken);
}
