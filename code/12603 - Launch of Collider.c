#include <stdio.h>

int type[200005];
int sit[200005];
int min = 1000000000;


int main() {
    int T;
    scanf("%d",&T);
    char input;
    for (int i=1;i<=T;i++) {
        scanf(" %c",&input);
        //printf(" %c",input);
        if (input == 'L') {
            type[i] = 1;
        }
        else if (input == 'R') {
            type[i] = 2;
        }
    }
    for (int i=1;i<=T;i++) {
        scanf(" %d",&sit[i]);
        //printf("%d ",sit[i]);
    }
    for (int i = 1;i<=T;i++) {
        if (type[i] == 2) {
            //int find = 0;
            for (int j = i+1;j<=T;j++) {
                if (type[j] == 1) {
                    //find = 1;
                    if (min > (sit[j] - sit[i]) ) {
                        min = sit[j]-sit[i];
                    }
                    //printf("Ok\n");
                    break;
                }
            }
        }
    }
    if (min == 1000000000) {
        printf("-1\n");
    }
    else {
        printf("%d\n",min/2);
    }
}
