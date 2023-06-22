#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int N,M;
int Qremain,Rremain,ans=0;
//char chessboard[20][20]={'\0'};
int row[10]={0};
char kind[10]={'\0'};
int place(int i);
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        //memset(chessboard, '\0', sizeof(chessboard));
        memset(row, '\0', sizeof(row));
        memset(kind, 0, sizeof(kind));
        Qremain=N;
        Rremain=M;
        int i,j;
        ans=place(0);
        printf("%d\n",ans);
    }
}
int place(int i)
{
    int testcase=0;
    int flag=0;
    if(N+M==1)return 1;
    for(int j=0;j<N+M;j++,flag=0)
    {
        if(i==0)
        {
            if(Qremain>0)
            {
                kind[i]='Q';
                row[i]=j;
                //chessboard[i][j]='Q';
                Qremain--;
                testcase+=place(i+1);
                Qremain++;
                //chessboard[i][j]='\0';
            }
            if(Rremain>0)
            {
                kind[i]='R';
                row[i]=j;
                //chessboard[i][j]='R';
                Rremain--;
                testcase+=place(i+1);
                Rremain++;
                //chessboard[i][j]='\0';
            }
            kind[i]='\0';
        }
        else
        {
            for(int y=0;y<i;y++)
            {
                if(row[y]==j || (abs(j-row[y])==abs(i-y) && kind[y]=='Q'))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {

                if(Qremain>0)
                {
                    int flag2=0;
                    for(int y=0;y<i;y++)
                    {
                        if(row[y]==j || (abs(j-row[y])==abs(i-y)) && kind[y]=='R')
                        {
                            flag2=1;
                            break;
                        }
                    }
                    if(flag2==0)
                    {

                        kind[i]='Q';
                        row[i]=j;
                        //chessboard[i][j]='Q';
                        if(i==N+M-1)
                        {
                            return 1;
                        }
                        Qremain--;
                        testcase+=place(i+1);
                        Qremain++;
                        //chessboard[i][j]='\0';
                    }
                }
                if(Rremain>0)
                {
                    kind[i]='R';
                    row[i]=j;
                    //chessboard[i][j]='R';
                    if(i==N+M-1)
                    {
                        return 1;
                    }
                    Rremain--;
                    testcase+=place(i+1);
                    Rremain++;
                    //chessboard[i][j]='\0';
                }
                kind[i]='\0';
            }
        }
    }
    if(i==N+M-1)return 0;

    //printf("check 2\n");
    return testcase;
}
