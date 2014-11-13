#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

#define PI 3.1415926

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

LL A[5010], B[5010];
LL dp[5010][5010];
LL sz1,sz2;

LL inf = 100000000000LL;

LL rec(LL a, LL b){

	if(dp[a][b]!=-1)
		return dp[a][b];

	// pair up elems from A and B
	LL pairUP = abs(A[a]-B[b]) + rec(a+1, b+1);

	// not pair with elem from B
	LL notPairUP = rec(a, b+1);

	LL minm = min(pairUP, notPairUP);
	dp[a][b] = minm;
	return dp[a][b];
}

void solve(){

	memset(dp, -1, sizeof(dp));

	// no rem elements implies 0 abs
	// diff
	dp[sz1][sz2] = 0;

	// impossible to pair if all of
	// second arr elements are used
	rep(i, sz1)
		dp[i][sz2] = inf;

	// some elems of B remain unmatched
	rep(i, sz2)
		dp[sz1][i] = 0;

	rec(0, 0);
}

int main(){
	int n, m;
	cin >> n >> m;

	if(n<=m){
		rep(i,n)
			cin >> A[i];
		rep(i,m)
			cin >> B[i];
		sz1 = n, sz2 = m;
	}
	else{
		rep(i,n)
			cin >> B[i];
		rep(i,m)
			cin >> A[i];
		sz1 = m, sz2 = n;
	}

	sort(A,A+sz1);
	sort(B,B+sz2);

	solve();

	cout << dp[0][0] << endl;

	return 0;
}