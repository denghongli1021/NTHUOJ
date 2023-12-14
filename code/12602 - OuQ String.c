#include <stdio.h>
#include <string.h>

long long int len[55];

char f (int n,long long int k) {
    if (n == 1) {
        if (k == 0) return 'O';
        else if (k == 1) return 'u';
        else if (k == 2) return 'Q';
    }
    else {
        if (k == 0) return 'O';
        else if (k == (len[n] - 1 ) / 2) return 'u';
        else if (k == len[n]-1 ) return 'Q';
        else if (k <= (len[n] - 1 ) / 2) return f(n-1,k-1);
        else if (k >= (len[n] - 1 ) / 2) return f(n-1,k-2-len[n-1]);
    }
}
int main() {
    int a,b,c;
    char ans ;
    len[1] = 3;
    for (int i=2;i<=50;i++) {
        len[i] = 2*len[i-1] + 3;
    }
    while (~scanf(" %d %d %d",&a,&b,&c)) {
        //printf("%d %d %d",a,b,c);
        for (int i=b;i<=c;i++) {
            //printf("%d\n",i);
            ans = f(a,i);
            printf("%c",ans);
        }
        printf("\n");
    }
}
