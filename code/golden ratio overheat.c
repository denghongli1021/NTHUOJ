#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char f0[2020];
char f1[2020];
long long int len[100];

char f(int n,long long int k) {
    if (n==0) return f0[k];
    if (n==1) return f1[k];

    if (k >= len[n-2]) return f(n-1,k-len[n-2]);
    else return f(n-2,k);
}

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        long long int n,k;
        scanf("%s %s %lld %lld",f0,f1,&n,&k);
        len[0] = strlen(f0);
        len[1] = strlen(f1);

        for (int i=2;i<=n;i++) {
            len[i] = len[i-2] + len[i-1];
        }

        char ans = f(n,k);
        printf("%c\n",ans);
    }
}

