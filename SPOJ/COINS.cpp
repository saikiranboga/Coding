#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define M 10000000

LL ex[M];

void fillEx(){
	ex[0] = 0;
	ex[1] = 1;
	for(LL i=2;i<M;i++)
		ex[i] = max(i, ex[i/2]+ex[i/3]+ex[i/4]);
}

LL get(LL n){
	if(n<M)
		return ex[n];
	else
		return max(n,get(n/2)+get(n/3)+get(n/4));
}

int main(){
	fillEx();
	LL n;
	while(cin >> n){
		cout << get(n) << endl;
	}
	return 0;
}