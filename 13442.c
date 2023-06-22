#include <stdio.h>
#include <stdlib.h>
#include "function.h"


int main(){

    int n, k;

    scanf("%d%d", &n, &k);
    head = createList(n);
    Node *p = solve(n, k);
    for(int i = 0; i < n; i ++){
        printf("%d ", p -> age);
        p = p -> next;
    }
    printf("\n");
    return 0;
}

