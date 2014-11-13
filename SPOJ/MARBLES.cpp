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

LL nCk(LL n, LL k){
	LL num = 1, den = 1;
	LL g;
	if(k>n-k)
		k = n-k;
	fu(i,0,k-1){
		num *= (n-i);
		den *= (k-i);
		g = __gcd(num,den);
		num /= g;
		den /= g;
	}
	return num;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		LL n, k;
		cin >> n >> k;

		if(n<k || k<0){
			cout << 0 << endl;
		}
		else if(n==k){
			cout << 1 << endl;
		}
		else{
			cout << nCk(n-1,k-1) << endl;
		}
	}
	return 0;
}