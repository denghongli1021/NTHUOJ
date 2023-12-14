#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct node{
    long long data;
    struct node *Left;
    struct node *Right;
}Node;

long long vari[7];
Node *root[30];
int cur;
const long long M = 998244353;

Node* newNode(char c){
    Node *N = (Node*)malloc(sizeof(Node));
    N->Left = N->Right = NULL;
    if(isalpha(c)){
        N->data = c;
    }
    else{
        if(c == '+') N->data = 0;
        else if(c == '-') N->data = 1;
        else if(c == '*') N->data = 2;
        else N->data = 3;
    }
    return N;
}

void deleteTree(Node *N){
    if(N->Left) deleteTree(N->Left);
    if(N->Right) deleteTree(N->Right);
    free(N);
}

Node* build(char *exp){
    Node *N = newNode(exp[cur++]);
    if(N->data < 4){
        N->Left = build(exp);
        N->Right = build(exp);
    }
    return N;
}

long long call(Node *N, long long x){
    long long ans = 0;
    if(N->data < 4){
        long long lchild = call(N->Left, x);
        long long rchild = call(N->Right, x);
        if(N->data == 0){
            ans = lchild + rchild;
        }
        else if(N->data == 1){
            ans = lchild - rchild;
        }
        else if(N->data == 2){
            ans = lchild * rchild;
        }
        else{
            ans = call(root[lchild], rchild);
        }
    }
    else if(N->data >= 'a'){
        ans = N->data - 'a';
    }
    else{
        ans = N->data == 'X' ? x : vari[N->data - 'A' + 1];
    }
    ans %= M;
    return ans < 0 ? ans + M : ans;
}

int main(){
    int n, q;
    char c;
    scanf("%d %d", &n, &q);
    while(n--){
        char exp[205];
        scanf("\n%c %s", &c, exp);
        cur = 0;
        root[c - 'a'] = build(exp);
    }
    while(q--){
        scanf("%c", &c);
        scanf("%c", &c);
        for(int i = 0; i < 5; i++){
            scanf("%lld", &vari[i]);
        }
        long long ans = call(root[c - 'a'], vari[0]);
        printf("%lld\n", ans);
    }
    for(int i = 0; i < 26; i++){
        if(root[i]){
            deleteTree(root[i]);
        }
    }
    return 0;
}

