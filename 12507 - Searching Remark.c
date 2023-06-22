#include <stdio.h>
#include <string.h>

int abs (int a,int b) {
    if (a>b) return a-b;
    else return b-a;
}

int main () {
    int flag,count = 0;
    char ans[25];
    scanf("%s",ans);
    char input[510];
    char token[12] =" \n-/:()[],.";
    char *check;
    while (fgets(input,510,stdin) != NULL) {
        check = strtok(input,token);
        while (check!=NULL) {
            int len = strlen(check);
            for (int i=0;i<=len-1;i++) {
                if (check[i] == ans[i] || abs(check[i] , ans[i]) == 'a'-'A') {
                    flag = 1;
                }
                else {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                count ++;
            }
            flag = 0;
            check = strtok(NULL,token);
        }
    }
    printf("%d\n",count);
}

