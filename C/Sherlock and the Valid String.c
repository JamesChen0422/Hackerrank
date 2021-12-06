int compare(const void *a, const void *b){
    return *(const int *)a - *(const int *)b;
}
 
char* isValid(char* s) {
    if(strlen(s) <= 1)
        return "YES";
        
    int* character = malloc(26 * sizeof(int));
    
    int count = 0, tmp = 0;
    
    for(int i=0; i<strlen(s); i++){
        if(character[s[i]-'a'] == 0)
            count++;
        character[s[i]-'a']++;
    }

    int* occur = calloc(count, sizeof(int));
    
    for(int i=0; i<26; i++){
        if(character[i]){
            occur[tmp] = character[i];
            tmp++;
        }
    }
    
    qsort(occur, count, sizeof(int), compare);
     
    for(int i=0; i<count; i++)
        printf("%d %d \n", i, occur[i]);
    if(occur[0] == occur[count-1]) return "YES";
    
    if (occur[0] == occur[count-2] && occur[count-2] == (occur[count-1] - 1)) return "YES";
    
    if(occur[1] != occur[0] && occur[1] == occur[count-1])
        if(occur[1] == occur[0]+1 || occur[0] == 1)
            return "YES";
        
    return "NO";
}