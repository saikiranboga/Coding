#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main(){
	LL t;
	cin >> t;
	while(t--){
		LL n;
		cin >> n;
		LL tot = 0;
		LL x;
		for(int i=0;i<n;i++){
			cin >> x;
			tot = (tot+x)%n;
		}
		if(tot==0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}