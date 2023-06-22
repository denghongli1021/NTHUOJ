#include <stdio.h>

int game[1005];
int coin[1005];
int main () {
    int gameNum;
    int coinNum;
    int test;
    scanf("%d %d",&gameNum,&coinNum);

    for (int i=1;i<=gameNum;i++) {
        scanf(" %d",&game[i]);
    }

    for (int i=1;i<=coinNum;i++) {
        scanf(" %d",&coin[i]);
    }

    int t=1;
    int count = 0;
    for (int i=1;i<=gameNum;i++) {
        if (coin[t] >= game[i]) {
            count++;
            t++;
        }
    }
    printf("%d\n",count);
}
