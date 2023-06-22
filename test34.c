#include <stdio.h>
#include <string.h>
#define N 10

int n, m, size, ans;
int g[N][N]; // chessboard

void dfs(int row, int numQ, int numR){
    if(row == size){
        ans++;
        return;
    }
    for(int col=0; col<size; col++){
        if(g[row][col]) continue;
        for(int i=row+1; i<size; i++)
            g[i][col]++;
        // queens
        if(numQ < n){
            // check diagonal
            int flag = 1;
            for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
                if(g[i][j] == -1) flag = 0;
            for(int i=row-1, j=col+1; i>=0 && j<size; i--, j++)
                if(g[i][j] == -1) flag = 0;
            if(flag){
                for(int i=row+1, j=col-1; i<size && j>=0; i++, j--)
                    g[i][j]++;
                for(int i=row+1, j=col+1; i<size && j<size; i++, j++)
                    g[i][j]++;
                dfs(row+1, numQ+1, numR);
                for(int i=row+1, j=col-1; i<size && j>=0; i++, j--)
                    g[i][j]--;
                for(int i=row+1, j=col+1; i<size && j<size; i++, j++)
                    g[i][j]--;
            }
        }
        printf("1\n");
        for (int i =0;i<size;i++) {
            for (int j=0;j<size;j++) {
                printf("%d",g[i][j]);
            }
            printf("\n");
        }
        // rooks
        if(numR < m){
            g[row][col] = -1;
            dfs(row+1, numQ, numR+1);
            g[row][col] = 0;
        }
        printf("2\n");
        for (int i =0;i<size;i++) {
            for (int j=0;j<size;j++) {
                printf("%d",g[i][j]);
            }
            printf("\n");
        }
        for(int i=row+1; i<size; i++)
            g[i][col]--;
    }
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        size = n + m, ans = 0;
        memset(g, 0, sizeof(g));
        dfs(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
