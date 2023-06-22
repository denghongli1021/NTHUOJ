#include <stdio.h>
#include <string.h>
int search_map(int x,int y,int step,int min) ;

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int n,m,q;
int x1,y1;
int x,y;
int endx,endy;
char map[25][25];
int min ;
int main() {
    scanf("%d %d %d",&n,&m,&q);
    memset(map,'X',sizeof(map));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            scanf(" %c",&map[i][j]);
            if (map[i][j] == '-') {
                endx = i;
                endy = j;
            }
        }
    }
    scanf(" %d %d",&x1,&y1);
    while (q--) {
        min = 99999;
        scanf("%d %d",&x,&y);
        printf("%d ",search_map(x+1,y+1,0,min));
    }
}

int search_map(int x,int y,int step) {
    if (x == endx && y==endy) {
        if (step < min) {
            min = step;
        }

    }
    if (step > min) return;
    if (map[x][y] == 'X') return;
    else if (map[x][y] == '.' ) {
        for (int i=0;i<=3;i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            search_map(nx,ny,step+1,min) ;
        }
    }

    return min;
}
