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

int main(){
	int n, k;
	cin >> n >> k;

	int f[n];
	for(int i=0; i<n; i++){
		cin >> f[i];
	}

	sort(f, f+n);

	if(k >= n){
		int ans = 2*(f[n-1]-1);
		cout << ans << endl;
	}
	else{
		int ans = 0;
		for(int i=n-1; i>=0; i-= k)
			ans += (f[i]-1)*2;
		cout << ans << endl;
	}

	return 0;
}