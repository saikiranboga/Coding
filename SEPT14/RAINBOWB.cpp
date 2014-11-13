#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

#define LL long long int

int main()
{
	int n;
	cin >> n;
	if(n<13)
		cout << 0 << endl;
	else{
		if(n==13 || n==14){
			cout << 1 << endl;
			return 0;
		}
		int mn = 1;
		int mx = n-13;

		LL ans = 0;
		LL x;
		for(int i=mn; i<=mx; i++){
			x = (n-i) / 2;
			
		}

	}

	return 0;
}