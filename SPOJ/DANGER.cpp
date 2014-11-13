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

int calL(LL n){
	LL cur = 1;
	int lg = 0;
	while(cur<n){
		cur = cur*2;
		lg++;
	}
	if(cur!=n)
		lg--;
	return lg;
}

int main(){
	string s;
	while(cin>>s && s!="00e0"){
		LL n = (int)(s[0]-'0')*10;
		n += (int)(s[1]-'0');
		int z = (int)(s[3]-'0');
		n *= pow(10,z);

		//cout << n << endl;
		LL pw = calL(n);
		//cout << pw << endl;
		LL ans = 2*(n-pow(2,pw))+1;

		cout << ans << endl;
	}
	return 0;
}