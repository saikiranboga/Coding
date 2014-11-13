#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

int count(int n){
	int ret = 0;
	while(n>0){
		if(n&1)
			ret++;
		n = n>>1;
	}
	return ret;
}

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	int arm[m];
	int fedor;
	for(int i=0;i<m; i++)
		cin >> arm[i];
	cin >> fedor;
	int ans = 0;
	for(int i=0;i<m;i++){
		if( count( arm[i]^fedor ) <= k ){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}