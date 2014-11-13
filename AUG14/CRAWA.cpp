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
	int t;
	cin >> t;
	while(t--){
		LL x,y;
		cin >> x >> y;
		
		bool exists = false;

		if(x==0 && y==0){
			cout << "YES\n";
			exists = true;
		}

		if(exists) continue;

		if(x>0 && x%2==1){
			//positive vertical lines
			if( y>=(-1)*(x-1) && y<=(x+1) ){
				cout << "YES\n";
				exists = true;
			}
		}

		if(exists) continue;

		if(x<0 && abs(x)%2==0){
			//negative vertical lines
			if( y>=x && y<=abs(x) ){
				cout << "YES\n";
				exists = true;
			}
		}

		if(exists) continue;

		if(y>0 && y%2==0){
			//positive horizontal lines
			if( x>=(-1)*y &&  x<=y-1 ){
				cout << "YES\n";
				exists = true;
			}
		}

		if(exists) continue;

		if(y<0 && abs(y)%2==0){
			//negative horizontal lines
			if(x>=y && x<=abs(y)+1){
				cout << "YES\n";
				exists = true;
			}
		}

		if(exists) continue;

		cout << "NO\n";

	}
	return 0;
}