#include<stdio.h>
#include<string.h>

#define MAX(a,b) (a>b ? a:b)

char s1[5001], s2[5001];
int map[5001][5001];
int main()
{
    int i,j,m,n;
    scanf("%s %s",s1+1, s2+1);
    m=strlen(s1+1);
    n=strlen(s2+1);
    
    for(i=1;i<=m;i++) map[i][0]=0;
    for(j=0;j<=n;j++) map[0][j]=0;
    
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(s1[i] == s2[j])
                map[i][j] = map[i-1][j-1]+1;
            else
                map[i][j] = MAX(map[i-1][j],map[i][j-1]);
        }    
    }
    
    printf("%d \n", map[m][n]);
    return 0;
}