#include <stdio.h>
#include <stdlib.h>
#include "function.h"

long long arr[500][500] = {};

int main(void){

    int row, col;
    scanf("%d%d", &row, &col);

    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            scanf("%lld", &arr[i][j]);

    array2d_sort(row, col, arr);

    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            printf("%lld%c", arr[i][j], (j==col-1) ? '\n' : ' ');

    return 0;
}

void array2d_sort(int row, int col, long long arr[][500]) {
    int v=0,m=0;
    long long int print[500][500] ;
    int min1 ;
    int min2 ;
    for (int j=1;j<=row*col;j++) {
        long long int min1 = arr[0][0] ;
        long long int min2 = arr[0][0] ; 
        for (int i=0;i<=row-1;i++) {
            for (int j=0;j<=col-1;j++) {
                if (arr[i][j] < min1) {
                    min1 = arr[i][j];
                }
                else if (arr[i][j] > min1 && arr[i][j] < min2) 
                {
                    min2 = arr[i][j]; 
                }
                print[v][m] = min1;
                min1 = min2 ;
                min2 = 0;
            }
        }
    }
    for (int i=0;i<=row-1;i++) {
        for (int j=0;j<=col-1;j++) {
            arr[i][j] = print[i][j];
        }
    }
}