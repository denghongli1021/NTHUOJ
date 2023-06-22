#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char student[105][100005];
int stu[101];
int studentlen [1000];
int main() {
    int N,M; // N 是 學生數 M 是操作數
    char op[25];
    char s[10000];
    int x,y; //用於各項功能的int型別
    scanf("%d %d",&N,&M);
    for (int i=1;i<=100;i++) {
        stu[i] = i;
    }
    for (int k=1;k<=M;k++) {
        scanf("%s",op);
        if (strcmp(op,"add") == 0) {
            scanf("%d %s",&x,s);
            strcat (student[stu[x]],s);
            studentlen[stu[x]] += strlen(s);
            //printf("%s",student[stu[x]]);
        }
        else if (strcmp(op,"all") == 0) {
            for (int i=1;i<=N;i++) {
                printf("%s\n",student[stu[i]]);
            }
        }
        else if (strcmp(op,"delete") == 0) {
            scanf("%d %d",&x,&y);
            int t = studentlen[stu[x]];
            if (y>=studentlen[stu[x]]) {
                y = studentlen[stu[x]];
                studentlen[stu[x]] = 0;
            }
            else {
                studentlen[stu[x]] -= y;
            }
            for (int i=t-1;i>=t-1-y+1;i--) {
                student[stu[x]][i] = '\0';
            }
        }
        else if (strcmp(op,"swap") == 0) {
            scanf("%d %d",&x,&y);
            int temp = stu[x];
            stu[x] = stu[y];
            stu[y] = temp;
            int temp2 = studentlen[x];
            studentlen[x] = studentlen[y];
            studentlen[y] = temp2;
        }
        else if (strcmp(op,"longest") == 0) {
            int longest = studentlen[1];
            int id;
            for (int i=1;i<=N;i++) {

                if (longest < studentlen[i]) {
                    longest = studentlen[i] ;
                    id = i;
                }
            }
            printf("%d %s\n",studentlen[stu[id]],student[stu[id]]);
        }
    }
}



