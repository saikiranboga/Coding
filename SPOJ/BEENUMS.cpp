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
	while( (cin>>n) && (n!=-1) ){
		LL c = (n-1)/3;
		LL under = 1+4*c;
		LL sq = sqrt(under);
		if( (3*c+1==n) && (under==sq*sq) && (sq%2==1) ){
			cout << "Y\n";
		}else{
			cout << "N\n";
		}
	}
	return 0;
}