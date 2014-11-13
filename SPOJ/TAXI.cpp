#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define MAX 5000

typedef long long int LL;

int height[MAX], excess[MAX];
int s, t, N;

class Edge{
public:
	int from, to, cap, flow, res_flow, index;

	Edge(int from, int to, int cap, int flow, int res_flow, int index):
		from(from),to(to),cap(cap),flow(flow),res_flow(res_flow),index(index){
	}
};

vector<vector<Edge> > G;

void addEdge(int from, int to, int cap){
	Edge ed(from, to, cap, 0, cap, G[to].size());
	Edge ed_rev(to, from, 0, 0, 0, G[from].size());
	G[from].pb(ed);
	G[to].pb(ed_rev);
}

void initializePreflow(){
	memset(height, 0, sizeof(height));
	height[s] = N;
	memset(excess, 0, sizeof(excess));
	int v;
	for(int i=0; i<G[s].size(); i++){
		v = G[s][i].to;
		G[s][i].flow = G[s][i].cap;
		G[v][G[s][i].index].flow = -G[s][i].cap;

		excess[v] = G[s][i].cap;
		excess[s] -= G[s][i].cap;

		G[s][i].res_flow = G[s][i].cap - G[s][i].flow;
		G[v][G[s][i].index].res_flow = G[v][G[s][i].index].cap - G[v][G[s][i].index].flow;
	}
}

void push(int u, int i){
	int amt = min(excess[u], G[u][i].res_flow);
	G[u][i].flow = G[u][i].flow + amt;
	int v = G[u][i].to;
	G[v][G[u][i].index].flow = -G[u][i].flow;
	excess[u] = excess[u]-amt;
	excess[v] = excess[v]+amt;
	G[u][i].res_flow = G[u][i].cap - G[u][i].flow;
	G[v][G[u][i].index].res_flow = G[v][G[u][i].index].cap - G[v][G[u][i].index].flow;
}

void displayG(){
	for(int i=0;i<N;i++){
		cout << i << ": ";
		for(int j=0;j<G[i].size();j++){
			cout << "-> (" << G[i][j].to << "," << G[i][j].cap << ") ";
		}
		cout << endl;
	}
}

int maxFlow(int s, int t){
	initializePreflow();
	queue<int> q;
	int active[N];
	memset(active,0,sizeof(active));
	for(int i=0;i<G[s].size();i++){
		if(G[s][i].to != t){
			q.push(G[s][i].to);
			active[G[s][i].to] = 1;
		}
	}
	int u,minimum;
	while(q.size()!=0){
		u = q.front();
		//cout << "processing: " << u << "...\n";
		minimum = -1;
		for(int i=0; i<G[u].size() && excess[u]>0; i++){
			int v = G[u][i].to;
			if(G[u][i].res_flow>0){
				if(height[u]>height[v]){
					push(u,i);
					if(!active[v] && v!=s && v!=t){
						active[v] = 1;
						q.push(v);
					}
				} else if(minimum==-1){
					minimum = height[v];
				} else{
					minimum = min(minimum, height[v]);
				}
			}
		}
		if(excess[u]!=0)
			height[u] = 1+minimum;
		else{
			active[u] = 0;
			q.pop();
		}
	}
	return excess[t];
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin >> k;
	while(k--){

		int pp,tt;
		LL ss,cc;
		cin >> pp >> tt >> ss >> cc;

		G.clear();
		N = pp+tt+2;
		G.resize(N);

		int s = 0, t = N-1;

		vector<pair<int, int> > persons;
		vector<pair<int, int> > taxis;

		int tx,ty,px,py;
		for(int i=1;i<=pp;i++){
			cin >> px >> py;
			persons.pb(mp(px,py));
			addEdge(tt+i, t, 1);
		}
		for(int i=1;i<=tt;i++){
			cin >> tx >> ty;
			taxis.pb(mp(tx,ty));
			addEdge(s, i, 1);
		}

		LL tsecs;
		for(int i=0;i<tt;i++){
			tx = taxis[i].first;
			ty = taxis[i].second;
			for(int j=0;j<pp;j++){
				px = persons[j].first;
				py = persons[j].second;
				tsecs = abs(tx-px)+abs(ty-py);
				tsecs = tsecs*200;
				if(tsecs<=(cc*ss)){
					addEdge(i+1,tt+j+1,1);
				}
			}
		}

		cout << maxFlow(s, t) << endl;

	}
	return 0;
}