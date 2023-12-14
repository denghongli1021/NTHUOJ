#include <stdio.h>

int main( ) {
    int T;
    scanf("%d",&T);
    int find;
    int year;
    int diff;
    int type1,type2;
    while (T--) {
        scanf("%d",&year);
        find = 0;
        diff = 0;
        type1 = type2 = 0;
        int year2 = year;
        if (year % 400 == 0 || year%4==0 && year%100 != 0) {
            type1 = 1;
        }

        while (find == 0) {
            if (year % 400 == 0 || year%4==0 && year%100 != 0) {
                diff += 2;
            }
            else {
                diff += 1;
            }
            year ++ ;
            if (diff % 7 == 0) {
                if (year % 400 == 0 || year%4==0 && year%100 != 0) {
                    type2 = 1;
                }
                else {
                    type2 = 0;
                }
                if (type1 == type2) {
                    printf("%d\n",year);
                    find = 1;
                }
            }
        }
    }
}
