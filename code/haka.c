#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char a[1005][1005];
bool v[1005][1005];
int x[1000005];
int y[1000005];
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
bool T;

void dfs(int j,int k) {
    printf("%d %d\n",j,k);
    v[j][k] = 1;
    if (a[j][k] == 'T') {
        T=1;
    }
    for (int i=0;i<=3;i++) {
        int nx= j+dx[i];
        int ny= k+dy[i];
        if (!v[nx][ny] && a[nx][ny] !='#') {
            dfs(nx,ny);
        }
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int q=0;
        int n,m;
        T=0;
        scanf(" %d %d",&n,&m);
        memset(a,'#',sizeof(a));
        memset(v,0,sizeof(v));
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                scanf(" %c",&a[i][j]);
                if (a[i][j] =='T') {
                    x[q] = i;
                    y[q] = j;
                    q++;
                }
            }
        }
        dfs(1,1);
        if (T) {
            for (int i=0;i<=q-1;i++) {
                int xx=x[i] ;
                int yy=y[i] ;
                if (!v[xx][yy]) dfs(xx,yy);
            }
        }
        if (v[n][m]) printf("Yes\n");
        else printf("No\n");
    }
}
