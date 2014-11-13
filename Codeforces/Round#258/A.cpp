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
	int win[101][101];
	memset(win,0,sizeof(win));
	int cur = 1;
	fu(i,1,100){
		fu(j,i,100)
			win[i][j] = cur;
		fu(j,i,100)
			win[j][i] = cur;
		cur = 1-cur;
	}
	int n,m;
	cin >> n >> m;
	if(win[n][m]==1)
		cout << "Akshat\n";
	else
		cout << "Malvika\n";
	return 0;
}