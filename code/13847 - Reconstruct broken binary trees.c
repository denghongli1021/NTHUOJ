#include <stdio.h>

int child[3000][2];
int used[3000]; // whether the pair of child is used
int inpos[3005]; // the position in the inorder sequence
int Left[3005], Right[3005]; // left and right child of each node
int notrt[3005]; // whether the node is not the root

int ischild(int rt, int l, int r){
    return inpos[l] < inpos[rt] && inpos[rt] < inpos[r]; // 只是位置
}

void build(int rt, int p){
    for(int i = 0; i < p; i++){
        if(used[i]) continue;
        if(ischild(rt, child[i][0], child[i][1])){
            Left[rt] = child[i][0];
            Right[rt] = child[i][1];
            used[i] = 1;
            build(Left[rt], p); // p 代表有幾個 pair of child
            build(Right[rt], p);
            break;
        }
    }
}

void preorder(int rt){
    if(!rt) return;
    printf(" %d", rt);
    preorder(Left[rt]);
    preorder(Right[rt]);
}

int main(){
    int n, root, p;
    scanf("%d", &n);
    p = (n - 1) / 2;
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        inpos[a] = i;
    }
    for(int i = 0; i < p; i++){
        scanf("%d%d", &child[i][0], &child[i][1]);
        notrt[child[i][0]] = notrt[child[i][1]] = 1;
        if(inpos[child[i][0]] > inpos[child[i][1]]){
            int tmp = child[i][0];
            child[i][0] = child[i][1];
            child[i][1] = tmp;
        }
    }
    for(int i = 1; i <= n; i++){
        if(!notrt[i]){
            root = i;
            break;
        }
    }
    build(root, p);
    printf("%d", root);
    preorder(Left[root]);
    preorder(Right[root]);
    printf("\n");
    return 0;
}

