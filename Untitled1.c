#include <stdio.h>

int main() {
    int a,b,c,d;
    scanf("%d.%d %d.%d",&a,&b,&c,&d);
    int max1,max2;
    max1 = 100*a+b;
    max2 = 100*c+d;

    max1 *= max2;
    max2 = max1/10000;
    max1 %= 10000;
    printf("%d.%4d",max2,max1);
}
