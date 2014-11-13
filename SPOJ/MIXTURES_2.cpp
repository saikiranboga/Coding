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

int n;
int cols[110];
int cum_cols[110];

int C[110][110];
int F[110][110];

void solve(){

	cum_cols[0] = 0;
	fu(i,1,n){
		cum_cols[i] = cols[i]+cum_cols[i-1];
		//cout << cum_cols[i] << " ";
	}
	//cout << endl;
	
	rep(i,n+1)
		rep(j,n+1)
			F[i][j] = inf;

	fu(i,1,n){
		fu(j,1,n){
			if(j>=i)
				C[i][j] = (cum_cols[j]-cum_cols[i-1])%100;
			else
				C[i][j] = 0;
		}
	}
/*
	rep(i,n+1){
		rep(j,n+1)
			cout << C[i][j] << " ";
		cout << endl;
	}
*/
	fu(i,1,n)
		F[i][i] = 0;

	int mn,res;

	for(int dif=1;dif<n;dif++){
		for(int i=1; i+dif<=n; i++){
			for(int k=i;k<dif+i; k++){
				res = F[i][k] + F[k+1][i+dif] + C[i][k]*C[k+1][i+dif];
				F[i][i+dif] = min(F[i][i+dif],res);
			}
		}
	}
}

int main(){

	while(cin >> n){
		cols[0] = 0;
		fu(i,1,n)
			cin >> cols[i];

		solve();
		cout << F[1][n] << endl;
	}
	return 0;
}