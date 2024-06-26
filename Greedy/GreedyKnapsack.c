#include <stdio.h>

float P[3] = {25.0, 24.0, 15.0};
float W[3] = {18.0, 15.0, 10.0};
float totalprofit[3];

void descendingsort(float arr[], float arr2[], float arr3[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;

                temp = arr3[j];
                arr3[j] = arr3[j + 1];
                arr3[j + 1] = temp;
            }
        }
    }
}
void method3(int m)
{
    float sum = 0;
    float ratios[3];
    for (int i = 0; i < 3; i++)
    {
        if (m == 0)
        {
            break;
        }
        else if (W[i] <= m && m > 0)
        {
            ratios[i] = 1.0;
            m = m - W[i];
        }
        else if (W[i] > m && m > 0)
        {
            ratios[i] = (float)m / W[i];
            m = 0;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        sum += (ratios[i] * P[i]);
    }
    totalprofit[2] = sum;
}

int main()
{
    float ratioPbyW[3];
    for (int i = 0; i < 3; i++)
    {
        ratioPbyW[i] = P[i] / W[i];
    }
    descendingsort(ratioPbyW, P, W, 3);
    method3(20);
    printf("Method 3 Profit: %.2f\n", totalprofit[2]);

    return 0;
}
