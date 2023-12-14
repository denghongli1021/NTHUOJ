#include <stdio.h>
#include <string.h>
int N, M;
int board[10][10];
int check_q(int r, int c, int size);
int check_r(int r, int c, int size);
int place(int r, int n, int m, int N, int M, int size);

int main(){
    while(~scanf("%d %d", &N, &M)) {
        memset(board, 0, sizeof(board));
        printf("%d\n", place(0, 0, 0, N, M, N + M));
    }
    return 0;
}
int check_q(int r, int c, int size){
    for(int i = 1; i <= r; i++){
        if(c - i >= 0 && (board[r - i][c - i] == 1 || board[r - i][c - i] == -1))
            return 0;
        if(c + i < size && (board[r - i][c + i] == 1 || board[r - i][c + i] == -1))
            return 0;
        if(board[r - i][c] == 1 || board[r - i][c] == -1)
            return 0;
    }
    return 1;
}
int check_r(int r, int c, int size){
    for(int i = 1; i <= r; i++){
        if(c - i >= 0 && board[r - i][c - i] == 1)
            return 0;
        if(c + i < size && board[r - i][c + i] == 1)
            return 0;
        if(board[r - i][c] == 1 || board[r - i][c] == -1)
            return 0;
    }
    return 1;
}
int place(int r, int n, int m, int N, int M, int size){
    if(r == size) return 1;
    int cnt = 0;
    for(int c = 0; c < size; c++){
        if(n < N && check_q(r, c, size)){
            board[r][c] = 1;
            cnt += place(r + 1, n + 1, m, N, M, size);
            board[r][c] = 0;
        }
        if(m < M && check_r(r, c, size)){
            board[r][c] = -1;
            cnt += place(r + 1, n, m + 1, N, M, size);
            board[r][c] = 0;
        }
    }
    return cnt;
}
// 1 for queen, -1 for rook
