#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
	int t;
	cin >> t;
	while(t--){
		LL a,b,s;
		cin >> a >> b >> s;
		LL n = (2*s)/(a+b);
		LL d = (b-a)/(n-5);
		LL st = a-2*d;
		cout << n << endl;
		for(int i=0;i<n;i++){
			cout << st+i*d << " ";
		}
		cout << endl;
	}
	return 0;
}