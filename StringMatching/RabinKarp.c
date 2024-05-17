#include <stdio.h>
#include <string.h>

#define d 10

void Rabin(char pattern[], char text[], int q) {
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int p = 0; 
    int t = 0; 
    int h = 1;
    
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
        
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    
    for (i = 0; i < N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == M)
                printf("Pattern found at index %d \n", i);
        }
        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;
            if (t < 0)  //if t is less than q 
                t = (t + q);
        }
    }
}

void main() {
    char text[100], pattern[100];
    int q;

    printf("Enter the text: ");
    scanf("%s", text);
    
    printf("Enter the pattern: ");
    scanf("%s", pattern);
    
    printf("Enter a prime number: ");
    scanf("%d", &q);
    
    Rabin(pattern, text, q);
}
