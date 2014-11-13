#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long LL;

int main()
{
	LL t,n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		LL ans = (n*(n+2)*(2*n+1))/8;
		cout << ans << endl;
	}
	return 0;
}