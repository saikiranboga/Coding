#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define mx 100000

int dp[100010];
int ans[100010];
int visited[100010];
int k;

int process(int u){
	if(u == mx+1)
		return 1;
	if(u > mx+1)
		return 0;
	if(visited[u] == 0){
		visited[u] = 1;
		dp[u] = ( process(u+1) + process(u+k) ) % MOD;
		ans[ mx - u + 1 ] = dp[u];
	}
	return dp[u];
}

void post(){
	for(int i=1; i<=mx; i++)
		ans[i] = ( ans[i] + ans[i-1] ) % MOD;
}

int main(){
	
	int t;
	cin >> t >> k;
	
	for(int i=0; i<=mx; i++){
		ans[i] = 0;
		dp[i] = 0;
		visited[i] = 0;
	}
	

	process(1);
	post();

	int a, b;
	while(t--){
		cin >> a >> b;
		cout << (ans[b] - ans[a-1]) << endl;
	}

	return 0;
}