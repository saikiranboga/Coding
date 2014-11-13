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
	int ar[n];
	rep(i,n)
		cin >> ar[i];
	int i;
	int mn = ar[0];
	for( i=1; i<n && ar[i]>=ar[i-1]; i++);
	if(i==n){
		cout << 0 << endl;
		return 0;
	}
	int ind = i;
	if(ar[i]>mn){
		cout << -1 << endl;
		return 0;
	}

	for( i++; i<n && ar[i]>=ar[i-1] && ar[i]<=mn; i++);
	if(i!=n){
		cout << -1 << endl;
		return 0;
	}
	cout << n-ind << endl;
	return 0;
}