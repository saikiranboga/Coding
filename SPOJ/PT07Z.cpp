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

vector<vector<int> > G;

int longest;

int maxPath(int u, int len){
	
	int x;
	int ret = len;
	vector<int> sub_len;

	rep(i,G[u].sz){
		x = maxPath(G[u][i], len+1);
		sub_len.pb(x);
	}

	int siz = sub_len.sz;
	if(siz){
		sort(sub_len.begin(), sub_len.end());

		if(siz>=2){
			int mx1 = sub_len[siz-1]-len;
			int mx2 = sub_len[siz-2]-len;
			if(mx1+mx2>longest){
				longest = mx1 + mx2;
			}
		}


		ret = sub_len[siz-1];
		if(ret-len>longest)
			longest = ret-len;
	}
	return ret;
}

int main(){
	int n;
	cin >> n;
	G.resize(n);

	int u, v;

	longest = 0;

	rep(i,n-1){
		cin >> u >> v;
		G[u-1].pb(v-1);
	}
	maxPath(0,0);

	cout << longest << endl;

	return 0;
}