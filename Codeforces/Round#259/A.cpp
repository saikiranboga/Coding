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
	char ar[n][n];
	rep(i,n){
		rep(j,n){
			ar[i][j] = '*';
		}
	}
	int m = 1;
	for(int i=0;i<=n/2;i++,m++){
		for(int j=0;j<m;j++){
			ar[i][n/2-j] = 'D';
			ar[i][n/2+j] = 'D';
		}
	}
	m = n/2;
	for(int i=n/2+1;i<n;i++,m--){
		for(int j=0;j<m;j++){
			ar[i][n/2-j] = 'D';
			ar[i][n/2+j] = 'D';
		}
	}
	rep(i,n){
		rep(j,n){
			cout << ar[i][j];
		}
		cout << endl;
	}
	return 0;
}