#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define rep(i,n) for(int i=0;i<n;i++)

#define MAX 100010

int m,n;
int mn;
int visited[MAX];
vector< vector< PII > > G;

void dfs(int u, int rev_edges){
	int s = G[u].sz;
	
	rep(i,s){
		if(!visited[G[u][i].ff]){
			if( G[u][i].ff == n ){
				if(G[u][i].ss==1){
					if(rev_edges < mn)
						mn = rev_edges;
				}
				else{
					if(rev_edges+1 < mn)
						mn = rev_edges+1 ;
				}
				continue;
			}
			visited[G[u][i].ff] = 1;
			if(G[u][i].ss==1)
				dfs(G[u][i].ff, rev_edges);
			else
				dfs(G[u][i].ff, rev_edges+1);
			visited[G[u][i].ff] = 0;
		}
	}
}

int main(){
	int x,y;
	scanf("%d %d",&n, &m);
	G.resize(n+1);
	rep(i,m){
		scanf("%d %d",&x, &y);
		if(x!=y){
			G[x].pb( mp(y,1) );
			G[y].pb( mp(x,-1) );
		}
	}
	mn = MAX;
	memset(visited, 0, sizeof(visited));
	visited[1] = 1;
	dfs(1, 0);
	if(mn == MAX)
		printf("-1\n");
	else
		printf("%d\n",mn);
	return 0;
}