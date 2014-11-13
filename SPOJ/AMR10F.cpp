#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,a,d;
		cin >> n >> a >> d;
		int sum = (n*a) + (n*(n-1)*d)/2;
		cout << sum << endl;
	}
	return 0;
}