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
	LL mul[7] = {20,360,7200,144000,2880000,57600000,1152000000};
	int n;
	while( (cin>>n) && (n) ){
		vector<int> dVals;
		getchar();
		rep(i,n){
			int nDash=0, nDots=0;
			string digit;
			getline(cin, digit);

			if(digit[0]=='S'){
				dVals.pb(0);
			}

			else{
				rep(id,digit.sz){
					if(digit[id]=='.')
						nDots++;
					if(digit[id]=='-')
						nDash++;
				}
				dVals.pb(nDash*5+nDots);
			}
		}
		LL ans = dVals[dVals.sz-1];
		int mulID = 0;
		fd(j, dVals.sz-2, 0){
			ans += dVals[j]*mul[mulID];
			mulID++;
		}
		cout << ans << endl;
	}
	return 0;
}