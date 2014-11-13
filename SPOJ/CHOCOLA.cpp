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
	LL t;
	cin >> t;
	while(t--){
		LL m,n;
		LL x_tot = 0, y_tot = 0;
		cin >> m >> n;
		m--,n--;
		LL x[m], y[n];
		rep(i,m){
			cin >> x[i];
			x_tot += x[i];
		}
		rep(j,n){
			cin >> y[j];
			y_tot += y[j];
		}

		sort(x,x+m);
		sort(y,y+n);

		LL x_mul = 1, y_mul = 1;
		LL xid=m-1, yid=n-1;
		LL ans = 0;

		while( xid>=0 || yid>=0 ){
			if(xid>=0 && yid>=0){
				if( x[xid] >= y[yid] ){
					ans += x[xid]*x_mul;
					xid--;
					y_mul++;
				}else{
					ans += y[yid]*y_mul;
					yid--;
					x_mul++;
				}
			}
			else if(xid>=0){
				while(xid>=0){
					ans += x[xid]*x_mul;
					xid--;
				}
			}
			else{
				while(yid>=0){
					ans += y[yid]*y_mul;
					yid--;
				}
			}
		}
		if(m!=0 && n!=0)
			cout << ans << endl;
		else if(m==0)
			cout << y_tot << endl;
		else if(n==0)
			cout << x_tot << endl;
		else
			cout << 0 << endl;

	}
	return 0;
}