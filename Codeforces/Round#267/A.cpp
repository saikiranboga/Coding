#include <bits/stdc++.h>
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
	cin >> n;
	int p, q;
	int ans = 0;
	for(int i=0;i<n;i++){
		cin >> p >> q;
		if( q-p >=2 )
			ans++;
	}
	cout << ans << endl;
	return 0;
}