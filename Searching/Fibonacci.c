#include<stdio.h>
#include<conio.h>
int min(int a,int b)
{
    return (a<=b)?a:b;
}
int fibonacci(int arr[],int x)
{
    int data;
    printf("Enter data to be searched:");
    scanf("%d",&data);
    int fib0=0;
    int fib1=1;
    int fib2=fib0+fib1;
    while(fib2<x)
    {
        fib0=fib1;
        fib1=fib2;
        fib2=fib0+fib1;
    }
    int offset=-1;
    while(fib2>1)
    {
        int i=min(offset+fib0,x-1);
        if(arr[i]<data)
        {
            fib2=fib1;
            fib1=fib0;
            fib0=fib2-fib1;
            offset=i;
        }   
        else if(arr[i]>data)
        {
            fib2=fib0;
            fib1=fib1-fib0;
            fib0=fib2-fib1;
        }
        else return i;
    }
    if(arr[offset+1]==data)
    {
        return offset+1;
    }
    return -1;
}
void main()
{
    int n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter sorted array\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter data:");
        scanf("%d",&a[i]);
    }
    int index=fibonacci(a,n);
    if(index==-1)
    {
        printf("Not found.\n");
    }
    else
    {
        printf("Data searched is found at %d position.",index);
    }
}