#include<stdio.h>
# define SIZE 4
int graph[SIZE][SIZE]={
    {0,1,1,1},
    {1,0,1,0},
    {1,1,0,1},
    {1,0,1,0},
};
int x[SIZE];
int colour;

int NextValue(int k,int colour)
{
    int i;
    while(1)
    {
        x[k]=(x[k]+1)%(colour+1);
        if(x[k]==0)
        {
            return 0;
        }
        for(i=0;i<SIZE;i++)
        {
            if(graph[k][i]!=0 && x[k]==x[i])
            {
                break;
            }
        }
        if(i==SIZE)
        {
            return 1;
        }
    }
}

int mcolouring(int k,int colour)
{
    while(1)
    {
        NextValue(k,colour);
        if(x[k]==0)
        {
            return 0;
        }
        if(k==SIZE-1)
        {
            for(int i=0;i<SIZE;i++)
            {
                printf("%d ",x[i]);
            }
            printf("\n");
        }
        else
        {
            mcolouring(k+1,colour);
        }
    }
}

void main()
{
    for(int i=0;i<SIZE;i++)
    {
        x[i]=0;
    }
    printf("Enter number of colours:");
    scanf("%d",&colour);
    int k=0;
    mcolouring(k,colour);
}
