#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 200010

int height[MAX], excess[MAX], cnt[2*MAX], active[MAX];
queue<int> q;
int s, t, N;

class Edge{
public:
	int from, to, cap, flow, res_flow, index;

	Edge(int from, int to, int cap, int flow, int res_flow, int index):
		from(from), to(to), cap(cap), flow(flow), res_flow(res_flow), index(index){
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
	memset(excess, 0, sizeof(excess));
	memset(cnt, 0, sizeof(cnt));
	memset(active,0,sizeof(active));

	active[s] = active[t] = 1;
	height[s] = N;
	cnt[N] = 1;
	cnt[0] = N-1;

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

void gap(int k){
	for(int v=0;v<N;v++){
		if(height[v]<k)
			continue;
		cnt[height[v]]--;
		height[v] = max(height[v], N+1);
		cnt[height[v]]++;
		if(!active[v] && v!=s && v!=t){
			active[v] = 1;
			q.push(v);
		}
	}
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

	//clearing a queue
	queue<int> empty;
   	swap(q, empty);

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
		if(excess[u]!=0){
			if(cnt[height[u]]==1)
				gap(height[u]);
			else
				height[u] = 1+minimum;
		}
		else{
			active[u] = 0;
			q.pop();
		}
	}
	return excess[t];
}

vector<int> vA, primes;
vector<int> middle;
map<int,int> gL, gR;

const int limit = 31650; //sqrt(10^9)
const int max_factor = 10;
const int inf = 1000000000;
bool is_prime[limit+1];

int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

vector<int> factorize(int x){
	vector<int> ret;
	for(int i=0; i<primes.size() && primes[i]*primes[i]<=x; i++){
		int d = primes[i];
		if(x%d==0){
			ret.pb(d);
			middle.pb(d);
			while(x%d==0){
				x /= d;
			}
		}
	}
	if(x>1){
		ret.pb(x);
		middle.pb(x);
	}
	return ret;
}

void fillPrimes(){
	memset(is_prime, true, sizeof(is_prime));
	for(int i=2;i<=limit;i++){
		if(is_prime[i]){
			primes.pb(i);
			for(int j=i*i; j<=limit;j+=i){
				is_prime[j] = false;
			}
		}
	}
}

int main(){

	fillPrimes();
	int tcases;
	cin >> tcases;
	while(tcases--){
		int n;
		cin >> n;
    	
    	gL.clear(); gR.clear();
    	vA.clear();
    	
    	int x;
    	for(int i = 0; i < n; i++){
      		cin >> x;
      		vA.push_back(x);
    	}

    	int g;
    	for(int j = 0; j < n; j++){
    		cin >> x;
    		for(int i = 0; i < n; i++){
    			if(vA[i] < x){
          			g = gcd(vA[i],x);
          			if(g > 1){
            			if(!gL.count(g)){
              				gL[g] = 0;
            			}
            			gL[g]++;
          			}
        		}
        		else if(vA[i] > x){
          			g = gcd(vA[i],x);
          			if(g > 1){
            			if(!gR.count(g)){
              				gR[g] = 0;
            			}
            			gR[g]++;
          			}
        		}
      		}
    	}

    	map<int,int>::const_iterator it, it2;
    	int id, id2;

    	vector<vector<int> > left_factors, right_factors;
    	middle.clear();

    	for(it = gL.begin(), id = 1; it != gL.end(); ++it, id++){
      		//addEdge(source, id, it->second);
      		left_factors.pb(factorize(it->first)); //this also adds them to middle

    	}
    	for(it = gR.begin(), id = gL.size()+1;it != gR.end(); it++, id++){
      		//addEdge(id, target, it->second);
      		right_factors.pb(factorize(it->first)); //this also adds them to middle
    	}
    
    	sort(middle.begin(), middle.end()); // sorts the middle nodes
    	middle.erase( unique(middle.begin(), middle.end()), middle.end() ); // removes duplicates and erases the space

    	G.clear();
    	N = gL.size()+middle.size()+gR.size()+2;
    	G.resize(N);
		int source = 0, target = N-1;
		s = source, t = target;
		
		int sz,k, ind;
    	for(it = gL.begin(), id = 1, ind = 0; it != gL.end(); ++it, id++, ind++){
      		addEdge(source, id, it->second);
      		sz = left_factors[ind].size();
      		for(int j=0;j<sz;j++){
      			k = lower_bound(middle.begin(),middle.end(),it->first)-middle.begin();
      			addEdge(id,gL.size()+k+1,inf);
      		}
    	}
    	
    	for(it = gR.begin(), id = gL.size()+middle.size()+1, ind = 0;it != gR.end(); it++, id++, ind++){
      		addEdge(id, target, it->second);
      		sz = right_factors[ind].size();
      		for(int j=0;j<sz;j++){
      			k = lower_bound(middle.begin(),middle.end(),it->first)-middle.begin();
      			addEdge(gL.size()+k+1, id, inf);
      		}
    	}
    	

    	//displayG();

    	cout << maxFlow(source, target) << endl;
	}
	return 0;
}