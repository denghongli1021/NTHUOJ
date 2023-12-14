#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
typedef struct p_list {
    char name[25];
    int current;
    int max;
}list;

void swap_list (list *a,list *b) {
    list tmp;
    strcpy(tmp.name,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,tmp.name);

    tmp.current=a->current;
    a->current=b->current;
    b->current=tmp.current;

    tmp.max=a->max;
    a->max=b->max;
    b->max=tmp.max;
}

void bubble_sort (list *pokemon) {
    for (int k=1;k<=n;k++) {
        for (int i=0;i<=n-2;i++) {
            if (pokemon[i].max == pokemon[i].current) {
                if (pokemon[i+1].max == pokemon[i+1].current) {
                    if (pokemon[i].max > pokemon[i+1].max) {
                        swap_list(&pokemon[i],&pokemon[i+1]);
                    }
                }
                else {
                    swap_list(&pokemon[i],&pokemon[i+1]);
                }
            }
            else {
                if (pokemon[i+1].max == pokemon[i+1].current) {
                    continue;
                }
                else {
                    if (pokemon[i].current > pokemon[i+1].current) {
                        swap_list(&pokemon[i],&pokemon[i+1]);
                    }
                    else if (pokemon[i].current == pokemon[i+1].current) {
                        if (pokemon[i].max > pokemon[i+1].max) {
                            swap_list(&pokemon[i],&pokemon[i+1]);
                        }
                    }
                }
            }
        }

    }
}

int main () {
    scanf("%d",&n);
    list pokemon[n];

    for (int i=0;i<=n-1;i++) {
        scanf("%s%d%d",pokemon[i].name,&pokemon[i].current,&pokemon[i].max);
    }

    bubble_sort(pokemon);

    for (int i=0;i<=n-1;i++) {
        printf("%s %d %d\n",pokemon[i].name,pokemon[i].current,pokemon[i].max);
    }
}
