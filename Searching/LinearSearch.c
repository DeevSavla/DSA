#include<stdio.h>
#include<conio.h>
void main()
{
    int n,search;
    int z=0;
    printf("Enter number of elements in an array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter a sorted array!!\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter number:");
        scanf("%d",&a[i]);
    }
    printf("Enter the data to be searhed:");
    scanf("%d",&search);   
    for(int i=0;i<n;i++)
    {
        if(a[i]==search)
        {
            printf("The number is found at index %d.",i);
            break;
        }
        else
        {
            z++;
        }
    } 
    if(z==n)
    {
        printf("Not Found.");
    }
}