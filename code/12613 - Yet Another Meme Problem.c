#include <stdio.h>
#include <string.h>

int compare (long long int j) {
    long long int value = 0;
    for (int i = 0;i<=10;i++) {
        value = value*10 + 9;
        if (j < value) {
            return i;
            break;
        }
        else if (j == value) {
            return i + 1;
            break;
        }
    }
}

int main() {
    int t;
    scanf("%d",&t);
    long long int a,b;
    for (int i=1;i<=t;i++) {
        scanf(" %lld %lld",&a,&b);
        int pow = compare(b);
        printf("%lld\n",a*pow);
    }
}
