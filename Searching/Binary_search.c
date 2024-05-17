#include <stdlib.h>
#include <stdio.h>

void binarySearch(int low,int high,int num,int a[])
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        if(a[mid]==num)
        {
            printf("Num found at position %d\n",mid+1);
        }
        else if(a[mid]>num)
        {
            binarySearch(low,mid-1,num,a);
        }
        else if(a[mid]<num)
        {
            binarySearch(mid+1,high,num,a);
        }
        else
        {
            printf("Num not found\n");
        }
    }
}

void main()
{
    int val,n;
    printf("Enter number of data items in the array:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter data %d: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Data to search? : ");
    scanf("%d",&val);
    binarySearch(0,n-1,val,a);

}
