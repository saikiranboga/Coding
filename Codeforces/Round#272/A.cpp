#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

int main(){

	int n, m;
	cin >> n >> m;
	int times = n;
	int posb[n+1];
	for(int i=0; i<n+1; i++)
		posb[i] = 0;
	posb[n] = 1;
	int n_ones = n;
	while(n_ones>1){
		times -= 1;
		n_ones -= 2;
		posb[times] = 1;
	}
	int ans = -1;
	for(int i=1; i<=n; i++){
		if(posb[i]==1 && i%m==0){
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}