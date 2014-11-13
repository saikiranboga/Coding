#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#define MOD 1000000009
#define ll long long
using namespace std;

inline ll mod(ll a, ll b)
{ 
	if(a >= b)
		return a%b;
	if(a < 0)
		return (a%b+b)%b;
	else 
		return a;
}

int main() {
	
	int t;
	cin >> t;
	while(t--){
		int n,q;
		cin >> n >> q;
		vector<ll> v(n);
	
		for(int i=0;i<n;++i)
			cin >> v[i];
		
		for(int i=0;i<q; ++i){
			int m;
			cin >> m;
			map<ll,ll> cnt;
			for(int i = 0; i<n; ++i){
				cnt[mod(v[i],m)]++;
			}
			vector<ll> a;
			for(map<ll,ll>::iterator it = cnt.begin(); it!=cnt.end();++it){
				a.push_back(it->first);
			}
			n=a.size();
			ll dp[2][m];
			memset(dp,0,sizeof(dp));
			//for i = 0, not choosing
			dp[0][0] = 1;
			// for i = 0, choosing
			dp[0][mod(a[0],m)] += cnt[a[0]];
			
			for(int i = 1; i < n ; ++i){
				
				// not choosing loop
				for(int j=0;j<m; ++j){
					dp[i&1][j] = dp[(i-1)&1][j]; 
				}
				
				//choosing loop
				for(int j=0;j<m;++j){
					ll newval = (j+mod(a[i],m))%m;
					dp[i&1][newval] += (dp[(i-1)&1][j] * cnt[a[i]]);
					dp[i&1][j] = mod(dp[i&1][j], MOD);
				}
			}
			
			printf("%lld\n",dp[(n-1)&1][0]);
		}
	}
	return 0;
}