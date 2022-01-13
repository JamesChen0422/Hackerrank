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

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int makeAnagram(char* a, char* b) {
    char* map = calloc(26, sizeof(char));
    int res = 0, i;
    
    for(i=0; i<strlen(a); i++){
        map[a[i]-'a']++;
    }
    
    for(i=0; i<strlen(b); i++){
        map[b[i]-'a']--;
    }
    
    for(i=0; i<26; i++){
        if(map[i]) res+=abs(map[i]);
    }
    
    return res;
}

int main()
{
    char a[10001];
    scanf("%s", a);
    
    char b[10001];
    scanf("%s", b);

    int result = makeAnagram(a, b);

    printf("%d\n", result);

    return 0;
}