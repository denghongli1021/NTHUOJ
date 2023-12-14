#include<stdio.h>

int original[5005];
int prefix[5005];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    prefix[0] = 0;
    for( int i =1 ;i <= n;i++) {
        scanf(" %d",&original[i]);
        prefix[i] = prefix[i-1]+original[i];
    }
    double max = 0;
    for (int i = m;i<=n;i++) {
        double inmax = 0;
        int temp = 0;
        for (int j = 1 ; j <= n-i+1 ; j++) {
            printf("%d %d\n",i,j);
            temp = prefix[j+i-1]-prefix[j-1];
            if (temp > inmax) {
                inmax = temp;
            }
        }
        if ( (inmax / i) > max) {
            max = inmax/i;
        }
    }
    printf("%.3f\n",max);
}
