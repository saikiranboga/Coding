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
	int nHALF=0, n34=0, n14=0;
	string s;
	rep(i,n){
		cin >> s;
		if(s=="1/2")
			nHALF++;
		else if(s=="1/4")
			n14++;
		else if(s=="3/4")
			n34++;
	}

	int req = 1;
	if(n34>=n14){
		req += (n34);
		n14 = 0;
	}
	else{
		req += (n34);
		n14 -= n34;
	}

	req += (nHALF)/2;
	if(nHALF%2==0)
		nHALF = 0;
	else
		nHALF = 1;

	if(nHALF==1){
		if(n14<=2){
			req += 1;
			n14 = 0;
			nHALF = 0;
		}
		else{
			req += 1;
			n14 -= 2;
			nHALF = 0;
		}
	}

	if(n14>0)
		req += ( (n14-1)/4 + 1 );

	cout << req << endl;

	return 0;
}