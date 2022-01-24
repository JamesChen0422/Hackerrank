#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int** arr = malloc(6 * sizeof(int*));

    for (int i = 0; i < 6; i++) {
        *(arr + i) = malloc(6 * (sizeof(int)));
        
        for (int j = 0; j < 6; j++) {
            scanf("%d", (*(arr + i) + j));
        }
    }
    
    int max=INT_MIN, sum=0;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            max = max > sum ? max : sum;
        }
    }
    
    printf("%d \n", max);
    
    return 0;
}
