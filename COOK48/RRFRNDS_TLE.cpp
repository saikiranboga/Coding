#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#ifndef pb
#define pb push_back
#endif

typedef long long int LL;

int N;
int visited[2000];
vector<vector<int> > G;

LL dfs(int v){
	LL ret = 0;
	visited[v] = 1;
	int sz = G[v].size();
	for(int i=0;i<sz;i++){
		visited[G[v][i]] = 1;
	}
	for(int i=0;i<sz;i++){
		int frnd = G[v][i];
		int frnd_sz = G[frnd].size();
		for(int j=0;j<frnd_sz;j++){
			if(!visited[G[frnd][j]]){
				ret++;
				visited[G[frnd][j]] = 1;
			}
		}
	}
	return ret;
}

int getFriendSuggestions(){
	LL ans = 0;
	for(int i=0;i<N;i++){
		memset(visited,0,sizeof(visited));
		ans += dfs(i);
	}
	return ans;
}

int main()
{
	cin >> N;
	G.resize(N);
	string s;

	for(int i=0;i<N;i++){
		cin >> s;
		for(int j=0;j<N;j++){
			if(s[j]=='1'){
				G[i].pb(j);
				G[j].pb(i);
			}
		}
	}

	cout << getFriendSuggestions() << endl;

	return 0;
}