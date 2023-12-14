#include <stdio.h>

int len,T,p;
char original[1000000];
char alphabet[30];
int main () {
    scanf("%d %d",&len,&T);
    scanf("%s",original);
    char a,b,tmp;
    for (int i=0;i<=25;i++) {
        alphabet[i] = 'a'+i;
    }
    while (T--) {
        scanf(" %c %c",&a,&b);
        //
        //printf("\n%c%c\n",a,b);
        for (int i = 0;i<=25;i++) {
            if (alphabet[i] == a) {
                for (int j= 0;j<=25;j++) {
                    if (j== i) continue;
                    if (alphabet[j] == b) {
                        tmp = alphabet[i];
                        alphabet[i] = alphabet[j];
                        alphabet[j] = tmp;
                        //printf("\n\nKO\n\n");
                        break;
                    }
                }
                break;
            }
        }
    }
    for (int i=0;i<=len-1;i++) {
        p = original[i] - 'a';
        printf("%c",alphabet[p]);
    }
    printf("\n");
    //for (int i=0;i<=25;i++) {
        //printf("%c",alphabet[i]);
    //}
}
