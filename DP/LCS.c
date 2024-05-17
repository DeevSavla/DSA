#include<stdio.h>
#include<string.h>

#define SIZE 100
char X[SIZE];
char Y[SIZE];
int m,n;

void print_lcs(char direction[SIZE][SIZE], char X[], int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (direction[i][j] == 'd') {
        print_lcs(direction, X, i - 1, j - 1);
        printf("%c", X[i-1]); 
    }
    else if (direction[i][j] == 'u') {
        print_lcs(direction, X, i - 1, j);
    }
    else {
        print_lcs(direction, X, i, j - 1);
    }
}

void LCS() {
    int i, j;
    char direction[SIZE][SIZE];
    int value[SIZE][SIZE];
    for (i = 0; i < m; i++) {
        value[i][0] = 0;
    }
    for (j = 0; j < n; j++) { 
        value[0][j] = 0;
    }
    for (i = 1; i <= m; i++) { 
        for (j = 1; j <= n; j++) { 
            if (X[i - 1] == Y[j - 1]) { 
                value[i][j] = value[i - 1][j - 1] + 1;
                direction[i][j] = 'd';
            }
            else if (value[i - 1][j] >= value[i][j - 1]) { 
                value[i][j] = value[i - 1][j];
                direction[i][j] = 'u';
            }
            else {
                value[i][j] = value[i][j - 1];
                direction[i][j] = 'l';
            }
        }
    }
    print_lcs(direction, X, m, n); 
}

void main() { 
    printf("Enter string 1:");
    scanf("%s", X);
    printf("Enter string 2:");
    scanf("%s", Y);
    m = strlen(X);
    n = strlen(Y);
    printf("Common subsequence is:");
    LCS();
}
