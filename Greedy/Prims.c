#include <stdio.h>
#include <limits.h>
#define SIZE 5
int min(int distance[], int visited[])
{
    int min = INT_MAX;
    int minIndex;
    for (int i = 0; i < SIZE; i++)
    {
        if (visited[i] == 0 && distance[i] < min)
        {
            minIndex = i;
            min = distance[i];
        }
    }
    return minIndex;
}
void prims(int weight[SIZE][SIZE])
{
    int cost = 0;
    int visited[SIZE];
    int parent[SIZE];
    int distance[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        visited[i] = 0;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < SIZE; i++)
    {
        int minIndex = min(distance, visited);
        visited[minIndex] = 1;
        for (int j = 0; j < SIZE; j++)
        {
            if (weight[minIndex][j] != 0 && visited[j] == 0 && distance[j] > weight[minIndex][j])
            {
                distance[j] = weight[minIndex][j];
                parent[j] = minIndex;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        cost = cost + distance[i];
    }
    printf("Minimum Cost is %d", cost);
}

void main()
{
    int weight[SIZE][SIZE] = {
        {0, 4, 7, 9, 8},
        {4, 0, 10, 0, 0},
        {7, 10, 0, 5, 0},
        {9, 0, 5, 0, 6},
        {8, 0, 0, 6, 0},
    };
    prims(weight);
}
