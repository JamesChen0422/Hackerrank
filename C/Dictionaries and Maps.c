#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct hashmap{
    char** name;
    unsigned int* number;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    scanf("%d", &n);
    
    struct hashmap* map = malloc(sizeof(struct hashmap));
    map->name = malloc(n * sizeof(char*));
    map->number = malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        map->name[i] = malloc(10 * sizeof(char));
        scanf("%s", map->name[i]);
        scanf("%d", &map->number[i]);
    }
       
    char input[10];
    while(scanf("%s",input) != EOF){
        int index = -1;        
        for(int i=0; i<n; i++){
            if(!strcmp(input, map->name[i]))
                index = i;
        }
        
        if(index >= 0)
            printf("%s=%d\n", input, map->number[index]);
        else
            printf("Not found\n"); 
    }
    
    return 0;
}



==================================================================


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct pair {
	char* first;
	char* second;
	struct pair* next;
} pair;

typedef struct dict {
	int size;
	pair** table;
} dict;

unsigned int hash(char* s) {
	unsigned int hashval = 1337;
	for (int i=0; i<(int)strlen(s); i++) {
		hashval = hashval * s[i] + 0xdeadbeef;
		hashval %= 0x3f3f3f3f;
	}
	return hashval;
}

void setsize(dict* d, int s) {
	d->table = malloc(s * sizeof(pair*));
	d->size = s;
	bzero(d->table, s * sizeof(pair*));
}

void insert(dict* d, char* k, char* v) {
	pair* p = malloc(sizeof(pair));

	char* s = malloc(strlen(k) * sizeof(char) + 1);
	char* t = malloc(strlen(v) * sizeof(char) + 1);
	strcpy(s, k);
	strcpy(t, v);

	p->first = s;
	p->second = t;
	p->next = NULL;

	unsigned int hashval = hash(k);
	if (d->table[hashval % d->size] == NULL)
		d->table[hashval % d->size] = p;
	else {
		pair* q = d->table[hashval % d->size];
		while (q->next)
			q = q->next;
		q->next = p;
	}
}

char* retreive(dict* d, char* k) {
	unsigned int hashval = hash(k);
	pair* p = d->table[hashval % d->size];

	if (!p) return NULL;

	while (strcmp(p->first, k) != 0) {
		if (p->next) p = p->next;
		else return NULL;
	}

	return p->second;
}

int main(void) {
	dict* d = malloc(sizeof(dict));
	setsize(d, 10000007);

	int T;
	scanf("%d", &T);

	char s[37];
	char t[37];
	while(T--) {
		scanf("%s %s", s, t);
		insert(d, s, t);
	}

	while(scanf("%s", s) != EOF) {
		if (retreive(d, s) != NULL)
			printf("%s=%s\n", s, retreive(d, s));
		else
			printf("Not found\n");
	}

	return 0;
}