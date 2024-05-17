#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# define n 50
int arr[n];

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int low,int high)
{
    int pivot=arr[low];
    int start=low;
    int end=high;
    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[low],&arr[end]);
    return end;
}

void quicksort(int low,int high)
{
    if(low<high)
    {
        int loc=partition(low,high);
        quicksort(low,loc-1);
        quicksort(loc+1,high);
    }
}

void main()
{
    clock_t start,end;
    double time_taken;
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100;
    }
    start=clock();
    quicksort(0,n-1);
    end=clock();
    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken is:%f",time_taken);
}
