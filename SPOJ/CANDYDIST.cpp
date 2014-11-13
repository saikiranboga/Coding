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
	LL n;
	while(cin>>n && n){
		LL c[n],p[n];
		rep(i,n){
			scanf("%lld",&c[i]);
		}
		rep(i,n){
			scanf("%lld",&p[i]);
		}
		sort(c,c+n);
		sort(p,p+n);

		LL ans = 0;
		rep(i,n){
			ans += (c[n-1-i]*p[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}