#include <stdio.h>
typedef long long LL;

#define MAXN 1000000000
#define SQRTT 31622

int flag[MAXN>>6];


#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))


void fill(){
	int i,j,k;
	for(i=3; i<SQRTT; i+=2){
		if(!ifc(i))
			for(j=i*i, k=i<<1; j<MAXN; j+=k)
				isc(j);
	}

	printf("2\n");
	j=k=1;
	for(i=3; i<MAXN; i+=2){
		if(!ifc(i)){
			j++;
			if(j-k==100){
				printf("%d\n",i);
				k = j;
			}
		}
	}
}

int main(){
	fill();
	return 0;
}