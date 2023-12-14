#include <stdio.h>

int index[200005];

int main() {
    int t,j = 1;
    scanf("%d",&t);
    int top = 1;
    for (int i = 1;i<=t;i++) {
        scanf(" %d",&index[i]);
    }
    int find;
    for (int i = 1;i<=t;i++) {
        scanf(" %d",&find);
        if (find == index[top]) {
            printf("1");
            top = top + 1;
        }
        else {
            int num = 0;
            for (j = top ; j<= t ; j++ ) {
                if (index[j] == find) {
                    break;
                }
                num++;
            }
            //printf("J : %d\n",j);
            if (j > t) {
                printf("0");
            }
            else {
                printf("%d",num+1);
                top = top+num+1;
            }
        }
        if (i <= t-1) {
            printf(" ");
        }
        else {
            printf("\n");
        }
    }
}
