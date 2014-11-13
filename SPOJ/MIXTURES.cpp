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

int cut(int, int, int);

int dp[110][110];
int col[110][110];
int ar[110];
int n;

void getColSmoke(int i, int j){
	int smoke = 0;
	if(i==j){
		col[i][j] = ar[i];
		dp[i][j] = 0;
		return;
	}
	if(j-i==1){
		col[i][j] = (ar[i]+ar[j])%100;
		dp[i][j] = ar[i]*ar[j];
		return;
	}
	int mn,res;
	mn = inf;
	fu(pos,i,j-1){
		res = cut(i,pos,j);
		mn = min(res,mn);
	}
	if(mn == inf)
		mn = 0;
	dp[i][j] = mn;
}

int cut(int left, int ct, int right){
	
	if(left==ct && ct==right){
		dp[left][right] = 0;
		return 0;
	}

	int lcol, rcol, lsmo, rsmo;

	getColSmoke(left, ct);
	lsmo = dp[left][ct];
	lcol = col[left][ct];

	getColSmoke(ct+1, right);
	rsmo = dp[ct+1][right];
	rcol = col[ct+1][right];

	if( (lsmo + rsmo + lcol*rcol) < dp[left][right] ){
		dp[left][right] = lsmo + rsmo + lcol*rcol;
		col[left][right] = (lcol+rcol)%100;
	}
	return dp[left][right];
}

void solve(){
	rep(pos,n-1){
		cut(0,pos,n-1);
	}
}

int main(){
	while(cin>>n){
		rep(i,n)
			cin >> ar[i];
		rep(i,n)
			rep(j,n)
				dp[i][j] = inf;
		solve();
		if(dp[0][n-1]==inf)
			cout << 0 << endl;
		else
			cout << dp[0][n-1] << endl;
	}
	return 0;
}
