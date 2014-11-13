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

LL f(LL n,LL k){
	LL r = 0, i = 1;
	while(i<=n){
		r = (r+k)%i;
		i += 1;
	}
	return r+1;
}

int main(){
	LL n, d;
	while(cin>>n>>d && !(n==0&&d==0)){
		cout << n << " " << d << " " << f(n,d) << endl;
	}
	return 0;
}