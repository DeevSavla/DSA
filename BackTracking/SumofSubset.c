#include <stdio.h>
int s = 0;
int k = 0;
int r = 18;
int w[100] = {5,4,8,1};
int m = 9;
int x[100];
int n = 4;
int SumOfSubsets(int s, int k, int r)
{
    x[k] = 1;
    if (s + w[k] == m)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d", x[i]);
        }
        printf("\n");
    }
    else if (s + w[k] + w[k + 1] <= m)
    {
        SumOfSubsets(s + w[k], k + 1, r - w[k]);
    }
    if (s + r - w[k] >= m && s + w[k + 1] <= m)
    {
        x[k] = 0;
        SumOfSubsets(s, k + 1, r - w[k]);
    }
    x[k] = 0;
}
int main()
{
    SumOfSubsets(s, k, r);
}
