#include <stdio.h>
#include <string.h>

char in[1000000];
char in2[1000000];
char folder1[50][5000];
char folder2[50][5000];


int testcase;
int main() {
    scanf("%d",&testcase);
    while (testcase--) {
        int flag = 0;
        scanf("%s",in);
        scanf("%s",in2);
        int x=strlen(in);
        int y=strlen(in2);
        /*
        for (int i=0;i<=t-1;i++) {
            printf("%c",in[i]);
        }
        printf("\n####\n");
        for (int i=0;i<=y-1;i++) {
            printf("%c",in2[i]);
        }
        printf("\n####\n");
        */
        int q=0;
        int t=0;
        for (int i=1;i<=x;i++) {
            if (in[i] == '/' || i==x) {
                t=0;
                q++;
                continue;
            }
            folder1[q][t] = in[i];
            t++;
        }
        t=0;
        int e=0;
        for (int i=1;i<=y;i++) {
            if (in2[i] == '/' || i==y && flag == 0) {
                /*printf("%d",strlen(folder2[e]));
                for (int j=0;j<=t-1;j++) {
                    printf("%c",folder2[e][j]);
                }
                printf("\n");*/
                for (int k=0;k<=q-1;k++) {
                    if (strcmp(folder2[e],folder1[k]) == 0) {
                        t=0;
                        e++;
                        i++;
                        break;
                    }
                    else if (strcmp(folder2[e],folder1[k]) != 0 && k==q-1) {
                        flag = 1;
                    }
                }
            }
            folder2[e][t] = in2[i];
            t++;
        }
        if (flag == 1) {
            printf("not valid\n");
        }
        else {
            printf("valid\n");
        }
    }
}
