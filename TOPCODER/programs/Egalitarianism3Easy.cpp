#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class Egalitarianism3Easy {

public:
	int maxCities(int n, vector<int> a, vector<int> b, vector<int> len) {
		if(n<=2)
			return n;
		int g[11][11];
		memset(g, -1, sizeof(g));
		for(int i=0;i<n-1;i++){
			g[i][i] = 0;
			g[a[i]][b[i]] = len[i];
			g[b[i]][a[i]] = len[i];
		}
		g[n-1][n-1] = 0;
		g[n][n] 	= 0;

		bool visited[n+1];
		memset(visited, false, sizeof(visited));

		visited[1] = true;
		dfs(1, g, n, visited);

		// for(int i=1;i<=n;i++){
		// 	for(int j=1;j<=n;j++){
		// 		cout << g[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		int mx = 1<<n;
		vector<int> nodes;
		int ans = 1;
		for(int i=1; i<=mx; i++){
			nodes.clear();
			for(int j=0;j<n; j++){
				if(i&(1<<j))
					nodes.push_back(j+1);
			}
			if(nodes.size()>1){
				int d = g[ nodes[0] ][ nodes[1] ];
				bool okay = true;
				for(int ii=0; ii<nodes.size(); ii++){
					for(int j=ii+1;j<nodes.size(); j++){
						if(g[nodes[ii]][nodes[j]]!=d){
							okay = false;
							break;
						}
					}
				}
				if(okay){
					if(nodes.size()>ans){
						ans = nodes.size();
						// for(int ii=0; ii<nodes.size(); ii++)
						// 	cout << nodes[ii] << " ";
						// cout << endl;
					}
				}
			}
		}

		return ans;
	}
	void dfs(int cur,int g[11][11], int n, bool visited[]){
		for(int i=1;i<=n;i++){
			if(visited[i]==false && g[cur][i]>=0){
				visited[i] = true;
				dfs(i, g, n, visited);
				for(int j=1; j<=n; j++){
					if(g[cur][j]<0 && g[i][j]>=0)
						g[cur][j] = g[cur][i] + g[i][j];
				}
			}
		}
		return;
	}
};
