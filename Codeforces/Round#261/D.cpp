#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

#define PI 3.1415926
#define inf 1000000000

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)

#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) cout << n

int main(){

	int n;
	cin >> n;
	int ar[n];
	rep(i,n)
		cin >> ar[i];
	map<int, int> lc;
	map<int, int> rc;

	int left[n], right[n];
	memset(left, 0, sizeof(n));
	memset(right, 0, sizeof(n));
	
	left[0] = 1;
	lc[ar[0]] = 1;
	for(int i=1; i<n; i++){
		if(lc.find(ar[i])==lc.end()){
			lc[ar[i]] = 1;
			left[i] = 1;
		}
		else{
			lc[ar[i]] += 1;
			left[i] = lc[ar[i]];
		}
	}

	right[n-1] = 1;
	rc[ar[n-1]] = 1;
	for(int i=n-2; i>=0; i--){
		if(rc.find(ar[i])==rc.end()){
			rc[ar[i]] = 1;
			right[i] = 1;
		}
		else{
			rc[ar[i]] += 1;
			right[i] = rc[ar[i]];
		}
	}
	sort(left, left+n);
	sort(right, right+n);

	LL ans = 0;
	for(int i=0;i<n;i++){
		int idx = upper_bound(left, left+n, right[i])-left;
		if(idx<n)
			ans += (n-idx);
	}

	cout << ans << endl;

	return 0;
}