#include <stdio.h>

int num[100000];

int main() {
    int t;
    int n,k;
    scanf("%d",&t);
    for (int i = 1;i<=t;i++) {
        scanf("%d",&n);
        for (int j = 1;j<=n;j++) {
            scanf("%d",&num[j]);
        }
        int count = 1;
        while (count <= 2) {
            for (int j = 1;j<=n;j++) {
                int check = 0;
                for (k=1;k<=n;k++) {
                    if (k == j) continue;
                    if ( (num[j] == num[k]) ) {

                        check = 1;
                        break;
                    }
                }
                if (check) continue;
                if (k == n+1) {
                    count++;
                    if (count == 2) {
                        printf("%d",num[j]);
                    }
                    else {
                        printf(" %d\n",num[j]);
                    }
                }
            }
        }
    }

}
