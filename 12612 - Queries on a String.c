#include <stdio.h>
#include <string.h>

char str[10005];
int main () {
    scanf("%s",str);
    int T;
    scanf(" %d",&T);
    int a,b,c;
    int len;
    char tmp,tmp2;
    while (T--) {
        scanf(" %d %d %d",&a,&b,&c);
        len = b-a+1;
        c %= len; //���@�w���Ʒ|�ܦ^�쥻���r��
        for (int k=1;k<=c;k++) {
            tmp = str[a-1];
            str[a-1] = str[b-1];
            for (int i=a;i<=b-1;i++) {
               tmp2 = str[i];
               str[i] = tmp; //�n�[tmp2
               tmp = tmp2;
            }
        }
    }
    printf("%s\n",str);
}
