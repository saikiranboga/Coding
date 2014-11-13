#include <cstdio>

typedef long long LL;

#define gi(n) scanf("%d",&n)
#define pi(n) printf("%d\n",n)

#define MAXN 100000000
#define SQRTT 10001

LL flag[MAXN>>6];


#define ifc(x) (flag[x>>6]&(1LL<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1LL<<((x>>1)&31)))


void fill(){
	int cnt = 1;
	pi(2);
	for(int i=3; i<=SQRTT; i+=2){
		if(!ifc(i)){
			cnt++;
			if(cnt%100==1)
				pi(i);
			for(int j=i*i; j<MAXN; j+=2*i)
				isc(j);
		}
	}
	
	for(int i=SQRTT+2; i<MAXN; i+=2){
		if(!ifc(i)){
			cnt++;
			if(cnt%100==1)
				pi(i);
		}
	}
}

int main(){

	fill();
	return 0;
}