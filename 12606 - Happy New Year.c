#include <stdio.h>
#include <string.h>


int bob;
int max;
int min;
int main() {
    int test;
    scanf("%d",&test);

    scanf("%d",&bob);
    max = bob;
    min = bob;

    int test2;
    while (test--) {
        scanf("%d",&test2);
        if (test2 > max ) {
            max = test2;
        }
        else if (test2 < min) {
            min = test2;
        }
    }
    //printf("\n\n%d %d\n",max ,min);
    int dis;
    dis = dis +  (max - bob)*2;
    dis = dis + (bob-min)*2;
    printf("%d\n",dis);

}
