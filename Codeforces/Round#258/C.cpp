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
		LL n,k,d1,d2;
		cin >> n >> k >> d1 >> d2;
		LL a,b,c;
		
		a = (k+2*d1+d2)/3;
		b = (k-d1+d2)/3;
		c = (k-d1-2*d2)/3;

		LL mx = max(a,b);
		mx = max(mx,c);
		LL dif = 3*mx - (a+b+c);

		if( dif>(n-k) ){
			cout << "no\n";
		}
		else{
			LL rem = n-k-dif;
			if(rem%3==0)
				cout << "yes\n";
			else{
				cout << "no\n";
			}
		}
	}
	return 0;
}