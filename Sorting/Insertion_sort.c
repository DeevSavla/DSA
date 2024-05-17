#include<stdio.h>
#include<time.h>
#include<stdlib.h>
# define n 1000
int arr[n];
void main()
{
    double time_taken;
    clock_t start,end;
    int temp,j;
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100;
    }
    start=clock();
    for(int i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    end=clock();
    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken is:%f",time_taken);
}
