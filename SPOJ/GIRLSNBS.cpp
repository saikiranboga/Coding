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
	int g,b;
	while( (cin>>g>>b) && !(g==-1&&b==-1) ){
		if(g==0)
			cout << b << endl;
		else if(b==0)
			cout << g << endl;
		else if(abs(g-b)<=1)
			cout << 1 << endl;
		else{
			int mn = min(g,b);
			int mx = max(g,b);
			cout << ( (mx-1)/(mn+1) + 1 ) << endl;
		}
	}
	return 0;
}