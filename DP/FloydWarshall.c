#include<stdio.h>
# define SIZE 5
int parent[SIZE][SIZE];
int distance[SIZE][SIZE]={
        {0,4,7,9,8},
        {4,0,1,1000,1000},
        {7,1,0,2,1000},
        {9,1000,2,0,6},
        {8,1000,1000,6,0},
};

void main()
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            if(distance[i][j]!=0 && distance[i][j]!=1000){
                parent[i][j]=i;
            }
            else{
                parent[i][j]=-1;
            }
        }
    }
    int k=0;
    while(k<SIZE)
    {
        for(int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                if(distance[i][j]>distance[i][k]+distance[k][j]){
                    distance[i][j]=distance[i][k]+distance[k][j];
                    parent[i][j]=k;
                }
            }
        }
        k++;
    }
    printf("Weights:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", distance[i][j]);
        }
        printf("\n");
    }
    printf("Parents:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d  ", parent[i][j]);
        }
        printf("\n");
    }
}
