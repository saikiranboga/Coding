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
	cin >> n;
	string s;
	if(n==0)
		cout << 0 << endl;
	else{
		while(n!=0){
			if(abs(n)%2!=0){
				s += '1';
				n = (n-1)/(-2);
			}
			else{
				s += '0';
				n = n/(-2);
			}
		}
		fd(i,s.sz-1,0){
			cout << s[i];
		}
		cout << endl;
	}
	return 0;
}