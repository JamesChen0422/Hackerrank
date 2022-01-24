/*
Time Limit Exceed
*/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool specialstr(char* s, int start, int end){
    int mid = (end-start)/2 + start;
    if((end-start)%2){
        for(int i=start; i<end; i++){
            if(s[i]!=s[end])
                return false;
            }
    } else {
        for(int i=start; i<end; i++){
            if(i!=mid){
                if(s[i]!=s[end])
                    return false;
            }
        }
    }
    return true;
}
// Complete the substrCount function below.
long substrCount(int n, char* s) {
    int tmp = 1;
    long sub = n;
    while(tmp<=n){
        for(int i = 0; i<n-tmp; i++){
            if(specialstr(s, i, i+tmp))
                sub++;
        }
        tmp++;
    }
    return sub;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    char* s = malloc(n*sizeof(char));
    scanf("%s", s);

    long result = substrCount(n, s);

    printf("%ld\n", result);

    return 0;
}


=============================================================


#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (a > b ? b : a)

struct hashmap {
    char* charc;
    int* cnt;
};
// Complete the substrCount function below.
long substrCount(int n, char* s) {
    struct hashmap* map = malloc(sizeof(struct hashmap));
    map->charc = malloc(n * sizeof(char));
    map->cnt = calloc(n, sizeof(int));
    int i, idx = 0;
    long res = 0;

    map->charc[0] = s[0];
    map->cnt[0] = 1;

    for(i=1; i<n; i++){
        if(s[i] != map->charc[idx]){
            idx++;
            map->charc[idx] = s[i];
            map->cnt[idx]++;
        } else
            map->cnt[idx]++;
    }

    for(i=0; i<=idx; i++){
        res += (map->cnt[i]*(map->cnt[i]+1)/2);
        
        if(i>0 && map->cnt[i]==1 && map->charc[i-1]==map->charc[i+1])
            res+= MIN(map->cnt[i-1], map->cnt[i+1]);       
    }  

    return res;        
}

int main()
{
    int n;
    scanf("%d", &n);
    
    char* s = malloc(n*sizeof(char));
    scanf("%s", s);

    long result = substrCount(n, s);

    printf("%ld\n", result);

    return 0;
}