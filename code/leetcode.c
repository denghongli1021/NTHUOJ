#include <stdio.h>
#include <string.h>

int main () {
    int a,b;
    char str1[1000];
    char str2[1000];
    //scanf("number = \"%d\", digit = \"%d\"",&a,&b);
    scanf("%s",str1);
    scanf("%s",str1);
    scanf("%s",str1);

    scanf("%s",str2);
    scanf("%s",str2);
    scanf("%s",str2);

    int j = 1;
    while (str1[j] >= '0' && str1[j]<= '9') {
        str1[j-1] = str1[j];
        j++;
    }
    str1[j-1] = '\0';

    j = 1;
    while (str2[j] >= '0' && str2[j]<= '9') {
        str2[j-1] = str2[j];
        j++;
    }
    str2[j-1] = '\0';

    //printf("%s\n",str1);
    //printf("%s\n",str2);

    int len = strlen(str1);
    int c,d;
    int w;
    int find = 0;
    //printf("%d\n",len);
    for (int i=0;i<=len-1;i++) {
        if (str1[i] == str2[0] && find == 0) {
            c = i;
            w = c;
            find = 1;
            //printf("step1\n");
            continue;
        }
        if (str1[i] == str2[0]) {
            d = i;
            int find2 = 0;
            int j1 = 0;
            int j2 = 0;
            while (find2 == 0) {
                //printf("step2\n");
                if (j1 == len-1 || j2 == len-1) {
                    find2 = 1;
                }
                if (j1 == c) {
                    j1 ++ ;
                }
                if (j2 == d) {
                    j2 ++ ;
                }
                if (str1[j1] < str1[j2]) {
                    w = d;
                    find2 = 2;
                }
                if (str1[j1] > str1[j2]) {
                    find2 = 1;
                }
                j1++;
                j2++;
            }
        }
    }
    printf("\"");
    for (int i=0;i<=len-1;i++) {
        if (i == w) continue;
        printf("%c",str1[i]);
    }
    printf("\"");
}
