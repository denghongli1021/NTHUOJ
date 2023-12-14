#include <stdio.h>
#include <string.h>


int num[1000005];
int print[1000005];
int main() {
    int n,m;
    int q=0;
    int flag = 0;
    scanf("%d %d",&n,&m);
    for (int i=0;i<=n-1;i++) {
        scanf("%d",&num[i]);
    }
    for (int i=m;i<=n-1;i++) {
        if (i>= m+1) {
            if (num[i] > num[i-m-1]) continue;
        }
        for (int j=1;j<=m;j++) {
            if (num[i] < num[i-j]) break;
            else if (j==m) {
                print[q] = i+1;
                flag =1;
                q++;
            }
        }
    }

    if (flag == 1) {
        for (int i=0;i<=q-1;i++) {
            printf("%d%c",print[i]," \n"[i==q-1]);
        }
    }
    else {
        printf("ouo\n");
    }
}
