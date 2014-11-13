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
		int n,k;
		cin >> n >> k;
		int ar[n];
		int ev_cnt = 0, od_cnt = 0;
		rep(i,n){
			cin >> ar[i];
			if(ar[i]%2==0)
				ev_cnt++;
			else
				od_cnt++;
		}
		
		if(k==0){
			if(od_cnt==0)
				cout << "NO\n";
			else
				cout << "YES\n";
		}
		else{
			if( ev_cnt >= k )
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}