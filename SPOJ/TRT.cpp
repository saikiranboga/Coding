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

int dp[2010][2010];
int v[2010];
int n;

int fill(int a, int b){
	if(a>b)
		return 0;
	int age = a+n-b;
	if(b==a){
		dp[a][b] = age*v[a];
		return dp[a][b];
	}
	if(dp[a][b]!=0)
		return dp[a][b];
	dp[a][b] = max(age*v[a]+fill(a+1,b), age*v[b]+fill(a,b-1));
	return dp[a][b];
}

int main(){
	cin >> n;
	rep(i,n)
		cin >> v[i];
	memset(dp,0,sizeof(dp));
	cout << fill(0,n-1) << endl;
	return 0;
}