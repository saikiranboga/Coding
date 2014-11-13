#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int x, y;
		vector<int> adj[n+1];
		vector< pair<int, int> > T;

		for(int i=0;i<n-1;i++){
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		bool vis[n+1];
		memset(vis, false, sizeof(vis));
		
		T.push_back( make_pair(1,0) );
		vis[1] = true;
		int v, lvl;
		int ii = 0;
		while(T.size()!= n){
			v = T[ii].first;
			lvl = T[ii].second;
			for(int j=0; j<adj[v].size(); j++){
				if(!vis[ adj[v][j] ]){
					T.push_back( make_pair(adj[v][j],lvl+1) );
					vis[ adj[v][j] ] = true;
				}
			}
			ii++;
		}

		int ans = 0;
		int sz = T.size();

		int alice = 0, bob = sz-1;
		int numnodes = 0;
		while(alice<=bob){
			int lvl = T[alice].second;
			int i=alice;
			while(i<=bob && T[i].second==lvl) // Alice is removing nodes
				i++;
			ans++; // Alice turn completed
			numnodes += (i-alice); // accum num of nodes removed in this turn by Alice
			alice = i; // index of first root which Alice removes in next turn
			if(alice>bob) // Alice removed all nodes
				break;
			bob--; // bob removes just one node
			numnodes++; // accum node removed by bob
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}