#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int sz = s.size();
		long long int ans = 1;
		for(int i=0; i<sz; i++){
			if(i%2 == 0){
				if(s[i]=='l')
					ans = (ans*2) % M;
				else
					ans = (ans*2 + 2)  % M;
			}
			else{
				if(s[i]=='l')
					ans = (ans*2 - 1 + M) % M;
				else
					ans = (ans*2 + 1)  % M;
			}
		}
		cout << ans << endl;
	}
	return 0;
}