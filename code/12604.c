#include <stdio.h>
#include <string.h>

int n,m,size,ans;
int g[15][15];


int dfs(int num,int row,int qnums,int mnums) {
    if (num == size+1) {
        ans ++;
        return;
    }
    int flag = 1;

    if (g[num][row] == 1) {
        return;
    }

    for (int i=1;i<=num;i++) {
        if (g[i][row]) flag = 0;
    }
    for (int i=1;i<=row;i++) {
        if (g[num][i]) flag = 0;
    }

}

int main () {
    while (scanf("%d %d",&n,&m) != EOF) {
        size = n+m;
        ans = 0;
        memset(g,0,sizeof(g));
        dfs(1,1,n,m);
        printf("%d\n",ans);
    }
    return 0;
}

