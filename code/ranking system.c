#include "function.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define max_size 1000

int cmp(const Node* a,const Node* b) {
    if (a->score > b->score) return -1;
    if (a->score < b->score) return 1;
    int sc = strcmp(a->name,b->name);
    return sc;
}

Node* createnode(int score,char* name) {
    Node* node = (*Node)malloc(sizeof(Node));
    node->score = score;
    node->name = (char*)malloc(sizeof(char)*sizeof(name)+1);
    strcpy(node->name,name);
    return node;
}

void Insert(Node** Table,int N,int score,char* name) {
    assert(N < max_size);
    Table[N] = createnode(score,name);
    for (int i=N-1;i>=0;i--) {
        if (cmp(Table[i]->name,Table[i+1]->name) >= 0) { //Table[i+1] 指的是新的Table成員
            Node* tmp = Table[i+1];
            Table[i+1] = Table[i];
            Table[i] = tmp;
        }
        else break;
    }
}

void Delete(Node** Table,int N,char* name) {
    for (int i=0;i<=N-1;i++) {
        if (strcmp(Table[i]->name,name) == 0) {
            free(Table[i]->name);
            free(Table[i]);
            for (int j=i;j<=N-1;j++) {
                Table[j] = Table[j+1];
            }
            Table[N-1] = NULL;
            return;
        }
    }
}

int* Top(Node** Table,int N,int x) {
    assert( x <= N) ;
    int* idxs = (int*)malloc(sizeof(int)*x);
    for (int i=0;i<=x-1;i++) {
        idxs[i] = i;
    }
    return idxs;
}
