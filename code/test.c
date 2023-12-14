#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int a = -123;
    int ans = 0;
    bool neg = false;
    if (a < 0) {
        neg = true;
    }
    int tmp = a % 10;
    if (tmp == 0) {
        while (tmp == 0) {
            a = a / 10;
            tmp = a % 10;
        }
    }
    while (a) {
        ans = ans * 10 + tmp;
        a = a / 10;
        tmp = a % 10;
    }
    printf("%d",ans);
}
