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
	LL fl[n];
	rep(i,n)
		cin >> fl[i];
	sort(fl,fl+n);
	LL ans1 = fl[n-1]-fl[0];
    LL ans2 = 0;
    if(fl[0]!=fl[n-1]){
    	LL c1 = 1;
    	LL i=1;
    	while(i<n && fl[i]==fl[i-1]) i++;
    	c1 = i;
    	LL c2 = 1;
    	i = n-2;
    	while(i>=0 && fl[i]==fl[i+1]) i--;
    	c2 = n-1-i;
    	ans2 = c1*c2;
    }
    else{
    	ans2 = ( n*(n-1) )/2;
    }
    cout << ans1 << " " << ans2 << endl;
	return 0;
}