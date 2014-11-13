#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

#define PI 3.1415926

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
bool visited[10010];
bool dfs(int u){
	visited[u] = true;
	rep(i,G[u].sz)
	{
		if(visited[G[u][i]]==false)
		{
			if( dfs(G[u][i]) == false)
				return false;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main(){

	int n,m;
	cin >> n >> m;
	int u,v;
	G.resize(n);
	rep(i,m)
	{
		cin >> u >> v;
		G[u-1].pb(v-1);
	}
	memset(visited,false,sizeof(visited));

	bool tree = dfs(0);

	rep(i,n)
	{
		if(visited[i]==false)
		{
			tree = false;
			break;
		}
	}

	if(tree == true)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}