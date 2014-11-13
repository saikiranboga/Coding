#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define MX 100010
#define MOD 1000000007
vector< int > adj[MX];
LL col[MX];
LL dp[MX][2];

void dfs(int x, int f){
	if(col[x]==1){
		dp[x][0] = 0;
		dp[x][1] = 1;
	}
	else{
		dp[x][0] = 1;
		dp[x][1] = 0;
	}
	for(int i=0; i<adj[x].size(); i++){
		int y = adj[x][i];
		if(y!=f){
			dfs(y, x);
			LL no_black = dp[x][0];
			LL one_black = dp[x][1];
			dp[x][0] = dp[x][1] = 0;
			
			// y have black-node trees
			if(dp[y][1]>0){
				dp[x][1] += one_black * dp[y][1]; // we have CUT the joint between x and y, and there is one black in each of them
				dp[x][1] += no_black  * dp[y][1]; // we have NOTCUT the joint, and there are no black in x part + one black in y part
				dp[x][0] += no_black  * dp[y][1]; // we have CUT the joint, and there is no black node in x part
			}

			// number of y having all white node trees
			if(dp[y][0]>0){
				dp[x][1] += one_black * dp[y][0];
				dp[x][0] += no_black  * dp[y][0];
			}

			dp[x][0] = dp[x][0]%MOD;
			dp[x][1] = dp[x][1]%MOD;
		}
	}
	//cout << x << " " << dp[x][0] << " " << dp[x][1] << endl;
	return;
}

int main(){
	int n, x;
	cin >> n;
	for(int i=1;i<=n-1;i++){
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	for(int i=0;i<n;i++)
		cin >> col[i];

	dfs(0, -1);
	cout << dp[0][1] << endl;
	return 0;
}