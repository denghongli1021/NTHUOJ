#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cat_list {
    char name[100];
    int ocu;
    int age;
} cat;


int cmp (const void *a , const void *b) {
    cat A = *(cat*)a;
    cat B = *(cat*)b;
    if (A.ocu == B.ocu) {
        if (A.age > B.age) {
            return A.ocu==5 ? 1:-1;
        }
        else if (A.age < B.age) {
            return A.ocu==5 ? -1:1;
        }
        else if (A.age == B.age) {
            return strcmp(A.name,B.name);
        }
    }
    else if (A.ocu <  B.ocu) {
        return -1;
    }
    else if (A.ocu > B.ocu) {
        return 1;
    }
}




cat catlist[1000000];

int main() {
    int n,m;

    while (~scanf("%d%d",&n,&m)) {
        for (int k=0;k<=n-1;k++) {
            char input[10000];
            scanf("%s%s%d",catlist[k].name,input,&(catlist[k].age) );
            if (input[0] == 'e') {
                catlist[k].ocu = 1;
            }
            else if (input[0] == 'n') {
                catlist[k].ocu = 2;
            }
            else if (input[0] == 'k') {
                catlist[k].ocu = 3;
            }
            else if (input[0] == 'w') {
                catlist[k].ocu = 4;
            }
            else if (input[0] == 'a') {
                catlist[k].ocu = 5;
            }
            else if (input[0] == 'm') {
                catlist[k].ocu = 6;
            }
            else if (input[0] == 'd') {
                catlist[k].ocu = 7;
            }
            else if (input[0] == 'l') {
                catlist[k].ocu = 8;
            }
        }
        qsort(catlist,n,sizeof(cat),cmp);
        for (int i=0;i<=m-1;i++) {
            printf("%s\n",catlist[i].name);
        }
    }
}

