#include <stdio.h>
#define MAX 100

int numItems, maxWeight, permCount;
int profit[MAX], weight[MAX];
int permProfit[MAX];
int permWeight[MAX];
int tempCount;
int tempProfit[MAX];
int tempWeight[MAX];

void knapsack() {
    int i, j;
    permProfit[0] = 0;
    permWeight[0] = 0;
    permCount = 1;
    
    for (i = 0; i < numItems; i++) {
        tempCount = 0;
        
        for (j = 0; j < permCount; j++) {
            tempProfit[tempCount] = permProfit[j] + profit[i];
            tempWeight[tempCount] = permWeight[j] + weight[i];
            tempCount++;
        }
        
        for (j = 0; j < tempCount; j++) {
            if (tempWeight[j] <= maxWeight) {
                permProfit[permCount] = tempProfit[j];
                permWeight[permCount] = tempWeight[j];
                permCount++;
            }
        }
    }
    
    int maxProfit = 0;
    for (i = 0; i < permCount; i++) {
        if (permProfit[i] > maxProfit && permWeight[i] <= maxWeight) {
            maxProfit = permProfit[i];
        }
    }
    printf("Maximum Profit: %d\n", maxProfit);
}

int main() {
    int i;
    printf("Enter number of items:");
    scanf("%d", &numItems);
    printf("Enter weight and profit for each item:");
    for (i = 0; i < numItems; i++) {
        scanf("%d %d", &weight[i], &profit[i]);
    }
    printf("Enter maximum weight capacity of knapsack:");
    scanf("%d", &maxWeight);
    knapsack();
    return 0;
}
