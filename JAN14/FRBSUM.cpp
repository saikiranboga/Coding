#include <stdio.h>
#include <algorithm>
using namespace std;

#define ll long long int


ll check(ll a[], ll size){
	if(a[0] != 1){
		return 1;
	}
	else{
		ll sum[size];
		sum[0] = a[0];
		for(ll i=1; i<size; i++){
			sum[i] = a[i] + sum[i-1];
		}
		ll sm;
		for(ll i=0; i<size-1; i++){
			sm = sum[i]+1;
			if(sm < a[i+1])
				return sm;
		}
		return sum[size-1]+1;
	}
}

int main(){
	ll N;
	scanf("%lld",&N);
	ll ar[N+1];
	for(ll i=1;i<=N;i++)
		scanf("%lld",&ar[i]);

	ll M, l, r;
	scanf("%lld",&M);
	while(M--){
		scanf("%lld %lld",&l,&r);
		ll size = r-l+1;
		ll copy[size];
		for(ll i=l;i<=r;i++){
			copy[i-l] = ar[i];
		}
		sort(copy, copy+size);
		printf("%lld\n",check(copy, size) );
	}

	return 0;
}