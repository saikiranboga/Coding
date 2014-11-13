#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

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

bool compareSort(PLL a, PLL b){
	if(a.ff<b.ff)
		return true;
	else if(a.ff>b.ff)
		return false;
	else
		return (a.ss<=b.ss)?true:false;
}

bool compareUB(LL a, PLL b){
	if(a<b.ff)
		return true;
	else if(a>=b.ff)
		return false;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		LL PW,TW,n,v,w;
		cin >> PW >> TW >> n;
		vector< PLL > coins;
		rep(i,n){
			cin >> v >> w;
			coins.pb(mp(w,v));
		}
		sort(coins.begin(),coins.end(),compareSort);
		LL NW = TW-PW;
		LL dp[NW+1];
		rep(i,NW+1)
			dp[i] = inf;
		vector< PLL >::iterator it;

		LL end;

		fu(i,1,NW){
			it = upper_bound(coins.begin(), coins.end(), i, compareUB);
			end = it-coins.begin();
			fu(j,0,end-1){
				if(dp[i-coins[j].ff] != inf) // if only we can place this coin to exactly fill 'i' weight
				{
					dp[i] = min(dp[i],dp[i-coins[j].ff]+coins[j].ss);
				}
				else if(i==coins[j].ff) // or this coin has weight exactly 'i'
				{
					if(dp[i]!=inf) //handling multiple coins with same weight
						dp[i] = min(dp[i],coins[j].ss);
					else // first coin with this weight
						dp[i] = coins[j].ss;
				}
			}
		}
		if(dp[NW]!=inf){
			cout << "The minimum amount of money in the piggy-bank is "<< dp[NW] << "." << endl;
		}
		else{
			cout << "This is impossible.\n";
		}
	}
	return 0;
}