#include <stdio.h>
#include <math.h>
#include <string.h>

char A[1000+5][1000+5];
char B[1000+5][1000+5];
int numof7[1000+5];
int n,m;
int count;


int main() {
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++) {
        count = 0;
        scanf(" %s",A[i]);
        numof7[i] = 0;
        int count1 = 0;
        int t=strlen(A[i]);
        for (int j=0;j<=t;j++) {
            if (A[i][j] == '|' || j==t) {
                int y=0;
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
            if (A[i][j] == 'A') {
                count = count *16 +10;
            }
            else if (A[i][j] == 'B') {
                count = count *16 +11;
            }
            else if (A[i][j] == 'C') {
                count = count *16 +12;
            }
            else if (A[i][j] == 'D') {
                count = count *16 +13;
            }
            else if (A[i][j] == 'E') {
                count = count *16 +14;
            }
            else if (A[i][j] == 'F') {
                count = count *16 +15;
            }
            else {
                int x = A[i][j] - 48;
                count = count *16+x;
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n-1;j++) {
            if (numof7[j] > numof7[j+1]) {
                int temp = numof7[j];
                numof7[j] = numof7[j+1];
                numof7[j+1] = temp;
                int t=strlen(B[j]) ;
                if (strlen(B[j+1])>t ) t = strlen(B[j+1]);
                for (int k=0;k<=t-1;k++) {
                    char buffer = B[j][k];
                    B[j][k] = B[j+1][k];
                    B[j+1][k] = buffer;
                }
            }
            else if (numof7[j] == numof7[j+1]) {
                if (strlen(B[j]) > strlen(B[j+1])) {
                    int temp = numof7[j];
                    numof7[j] = numof7[j+1];
                    numof7[j+1] = temp;
                    int t=strlen(B[j]) ;
                    if (strlen(B[i+1]) > t) t = strlen(B[i+1]);
                    for (int k=0;k<=t-1;k++) {
                        char buffer = B[j][k];
                        B[j][k] = B[j+1][k];
                        B[j+1][k] = buffer;
                    }
                }
                else if (strlen(B[j]) == strlen(B[j+1])) {
                    int t=strlen(B[j]) ;
                    for (int k=0;k<=t-1;k++) {
                        if (B[j][k] < B[j+1][k]) {
                            break;
                        }
                        else if (B[j][k] > B[j+1][k]) {
                            int temp = numof7[j];
                            numof7[j] = numof7[j+1];
                            numof7[j+1] = temp;
                            int t=strlen(B[j]) ;
                            if (strlen(B[j+1])>t ) t = strlen(B[j+1]);
                            for (int k=0;k<=t-1;k++) {
                                char buffer = B[j][k];
                                B[j][k] = B[j+1][k];
                                B[j+1][k] = buffer;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=n-m+1;j<=n-1;j++) {
            if (strlen(B[j]) > strlen(B[j+1])) {
                int temp = numof7[j];
                numof7[j] = numof7[j+1];
                numof7[j+1] = temp;
                int t=strlen(B[j]) ;
                for (int k=0;k<=t-1;k++) {
                    char buffer = B[j][k];
                    B[j][k] = B[j+1][k];
                    B[j+1][k] = buffer;
                }
                break;
            }
            else if (strlen(B[j]) == strlen(B[j+1])) {
                int t=strlen(B[j]) ;
                for (int k=0;k<=t-1;k++) {
                    if (B[j][k] < B[j+1][k]) {
                        break;
                    }
                    else if (B[j][k] > B[j+1][k]) {
                        int temp = numof7[j];
                        numof7[j] = numof7[j+1];
                        numof7[j+1] = temp;
                        int t=strlen(B[j]) ;
                        if (strlen(B[j+1])>t ) t = strlen(B[j+1]);
                        for (int k=0;k<=t-1;k++) {
                            char buffer = B[j][k];
                            B[j][k] = B[j+1][k];
                            B[j+1][k] = buffer;
                        }
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
