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

int n,k;
int num[20][110];

int f(int n, int k){
	if(n==0){
		return 0;
	}

	if(k==0){
		return 1;
	}
	
	if(num[n][k]!=-1){
		return num[n][k];
	}

	num[n][k] = 0;
	for(int i=0; i<n && k-i>=0; i++){
		num[n][k] += f(n-1,k-i);
	}
	return num[n][k];

}

int main(){
	rep(i,20)
		rep(j,110)
			num[i][j] = -1;
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		cout << f(n,k) << endl;
	}
	return 0;
}