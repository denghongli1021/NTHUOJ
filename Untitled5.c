#include <stdio.h>
#include <string.h>
#include <math.h>

char A[1000+5][1000+5]; //before
char B[1000+5][1000+5]; //change to 16進位
int numof7 [1000+5];  //7的數量
int print[1000+5] ; //放的是numof7存的數字中，數字前m大的index
int print2[1000+5];


int n,m;
int count = 0;
int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf(" %s",A[i]);
        numof7[i] = 0;
        int count1 = 0;
        for (int j=0;j<=strlen(A[i]);j++) {
            if (A[i][j] == '|' || j==strlen(A[i])) {
                int y=0;
                //printf("%d ",count);
                for (int o=9;o>=0;o--) {
                    if (count >= pow(10,o) || y>0) {
                        int x1= count / pow(10,o);
                        count = count - x1*pow(10,o);
                        //printf("%d ",x1);
                        B[i][count1] = (char)(x1+48);
                        if (B[i][count1] == '7') {
                            numof7[i] ++;
                        }
                        count1 ++;
                        y++;
                    }
                }

                count = 0;
                continue ;
            }

            count = count*16;
            if (A[i][j] == 'A') {
                count = count + 10;
            }
            else if (A[i][j] == 'B') {
                count = count + 11;
            }
            else if (A[i][j] == 'C') {
                count = count + 12;
            }
            else if (A[i][j] == 'D') {
                count = count + 13;
            }
            else if (A[i][j] == 'E') {
                count = count + 14;
            }
            else if (A[i][j] == 'F') {
                count = count + 15;
            }
            else {
                int x=A[i][j] - 48;
                count = count + x;
            }
        }
    }
    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n-1;i++) {
            if (numof7[i] > numof7[i+1]) {
                int temp = numof7[i];
                numof7[i] = numof7[i+1];
                numof7[i+1] = temp;
                int t=strlen(B[i]);
                if (strlen(B[i+1]) > t) t = strlen(B[i+1]);
                for (int j=0;j<=t-1;j++) {
                    char temp2 = B[i][j];
                    B[i][j] = B[i+1][j];
                    B[i+1][j] = temp2;
                }
            }
            else if (numof7[i] == numof7[i+1] ) {
                if (strlen(B[i]) > strlen(B[i+1])) {
                    int temp = numof7[i];
                    numof7[i] = numof7[i+1];
                    numof7[i+1] = temp;
                    int t=strlen(B[i]);
                    if (strlen(B[i+1]) > t) t = strlen(B[i+1]);
                    for (int j=0;j<=t-1;j++) {
                        char temp2 = B[i][j];
                        B[i][j] = B[i+1][j];
                        B[i+1][j] = temp2;
                    }
                }
                else if (strlen(B[i]) == strlen(B[i+1])) {
                    for (int j=0;j<=strlen(B[i]) - 1;j++) {
                        if (B[i][j] > B[i+1][j]) {
                            int temp = numof7[i];
                            numof7[i] = numof7[i+1];
                            numof7[i+1] = temp;
                            int t=strlen(B[i]);
                            for (int j=0;j<=t-1;j++) {
                                char temp2 = B[i][j];
                                B[i][j] = B[i+1][j];
                                B[i+1][j] = temp2;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int k=1;k<=n+1;k++) {
        for (int i=n-m+1;i<=n-1;i++) {
            int t=strlen(B[i]);
            int t1=strlen(B[i+1]);
            if (t > t1) {
                int temp = numof7[i];
                numof7[i] = numof7[i+1];
                numof7[i+1] = temp;
                for (int j=0;j<=t-1;j++) {
                    char temp2 = B[i][j];
                    B[i][j] = B[i+1][j];
                    B[i+1][j] = temp2;
                }
            }
            else if (t == t1) {
                for (int j=0;j<=t-1;j++) {
                    if (B[i][j] > B[i+1][j]) {
                        int temp = numof7[i];
                        numof7[i] = numof7[i+1];
                        numof7[i+1] = temp;
                        int t=strlen(B[i]);
                        for (int j=0;j<=t-1;j++) {
                            char temp2 = B[i][j];
                            B[i][j] = B[i+1][j];
                            B[i+1][j] = temp2;
                        }
                        break;
                    }
                    else if (B[i][j] < B[i+1][j]) {
                        break;
                    }
                }
            }
        }
    }
    for (int i=n-m+1;i<=n;i++) {
        for (int j=0;j<=strlen(B[i])-1;j++) {
            printf("%c",B[i][j]);
        }
        printf("\n");
    }
}
