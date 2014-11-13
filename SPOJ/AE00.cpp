#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	long long ans = 0;
	for(int i=1;i<=sqrt(n);i++){
		ans += ((n/i)-i+1);
	}
	cout << ans << endl;
	return 0;
}