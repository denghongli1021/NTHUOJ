#include <stdio.h>
#include <string.h>

char map[105][105];

int possi = 0;

int search_str (int x,int y,int step,int size) {
    if (step == 11) {
        possi ++;
    }
    else {
        //printf("%d\n",step);
        int x1,y1,x2,y2;
        char ans;
        if (step == 1) {
            ans = 'I';
        }
        else if (step == 2) {
            ans = 'C';
        }
        else if (step == 3) {
            ans = 'P';
        }
        else if (step == 4) {
            ans = 'C';
        }
        else if (step == 5) {
            ans = 'A';
        }
        else if (step == 6) {
            ans = 'S';
        }
        else if (step == 7) {
            ans = 'I';
        }
        else if (step == 8) {
            ans = 'A';
        }
        else if (step == 9) {
            ans = 'S';
        }
        else if (step == 10) {
            ans = 'G';
        }


        if (x <= 2) {
            x1 = 1;
        }
        else {
            x1 = x - 2;
        }

        if (y <= 2) {
            y1 = 1;
        }
        else {
            y1 = y - 2;
        }

        if (x == size) {
            x2 = size;
        }
        else if (x == size - 1) {
            x2 = size;
        }
        else {
            x2 = x + 2;
        }

        if (y == size) {
            y2 = size;
        }
        else if (y == size - 1) {
            y2 = size;
        }
        else {
            y2 = y + 2;
        }

        for (int i = x1;i<=x2;i++) {
            for (int j = y1;j<=y2;j++) {
                //printf("%d\n",(i-x)*(i-x)+(j-y)*(j-y));
                if ( (i-x)*(i-x)+(j-y)*(j-y) == 5 ) {
                    //printf("%c %c\n",map[i][j],ans);
                    if (map[i][j] == ans) {
                        //printf("%d %d %d %d\n",i,j,step,size);
                        search_str(i,j,step+1,size);
                    }
                }
            }
        }
    }
}

int main() {
    int size;
    scanf("%d",&size);
    for (int i=1;i<=size;i++) {
        for (int j=1;j<=size;j++) {
            scanf(" %c",&map[i][j]);
        }
    }

    /*for (int i=1;i<=size;i++) {
        for (int j=1;j<=size;j++) {
            printf(" %c",map[i][j]);
        }
        printf("\n");
    }*/

    for (int i= 1;i<=size;i++) {
        for (int j=1;j<=size;j++) {
            if (map[i][j] == 'I') {
                //printf("%d %d\n",i,j);
                search_str(i,j,2,size);
            }
        }
    }

    if (possi > 0) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}
