#include<stdio.h>

unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k);
void delete_3d_array(unsigned ***arr);


unsigned random_seed=7122;
unsigned Random(){
	return random_seed=random_seed*0xdefaced+1;
}
int main(){
	int n,m,k,_;
	scanf("%d%d%d%d%u",&_,&n,&m,&k,&random_seed);
	while(_--){
		unsigned ***arr=new_3d_array(n,m,k);
		int i,j,l;
		for(i=0;i<n;++i){
			for(j=0;j<m;++j){
				for(l=0;l<k;++l){
					arr[i][j][l]=Random();
				}
			}
		}
		for(i=0;i<5;++i){
			unsigned a,b,c;
			a=Random()%n;
			b=Random()%m;
			c=Random()%k;
			if(i)putchar(' ');
			printf("%u",arr[a][b][c]);
		}
		puts("");
		delete_3d_array(arr);
	}
	return 0;
}
unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k)
{
    unsigned* lk; //layer 3 for k
    unsigned** lm; //layer 2 for m
    unsigned*** ln; //layer 1 for n

    unsigned i,j;

    lk = (unsigned *) malloc(sizeof(unsigned)*n*m*k);
    lm = (unsigned **) malloc(sizeof(unsigned*)*n*m);
    ln = (unsigned ***) malloc(sizeof(unsigned**)*n);

    for(i=0;i<n;i++)
    {
        ln[i]=lm+i*m;
        for(j=0;j<m;j++)
        {
            lm[i*m+j]=lk+(i*m+j)*k;
            //or
            //ln[i][j]=lk+(i*m+j)*k;
        }
    }

    return ln;
}
void delete_3d_array(unsigned ***arr)
{
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
}
