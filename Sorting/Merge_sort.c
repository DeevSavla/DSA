#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# define n 100
int arr[n];
int copy[n];

void merge(int low,int mid,int high)
{
    int i,j,k;
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            copy[k++]=arr[i++];
        }
        else
        {
            copy[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        copy[k++]=arr[i++];
    }
    while(j<=high)
    {
        copy[k++]=arr[j++];
    }
    for(int i=low;i<high;i++)
    {
        arr[i]=copy[i];
    }
}

void mergesort(int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
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
    mergesort(0,n-1);
    end=clock();
    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken is:%f",time_taken);
}
