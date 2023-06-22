#include <stdio.h>

int main() {
    int a = 10;
    int b = 0;
    int c = 0;
    int d = 10;
    if (a == d) {
        printf("1\n");
    }
    if (a && d) {
        printf("2\n");
    }
    if (b == c) {
        printf("3\n");
    }
    if (b && c) {
        printf("4\n");
    }
}
