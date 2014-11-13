#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 10010

int parent[MAXN];
int rank[MAXN];
int score[MAXN];

void createSet(int x){
	parent[x] = x;
	rank[x] = score[x];
}

int findSet(int x){
	if(x!=parent[x])
		parent[x] = findSet(parent[x]);
	return parent[x];
}

void mergeSets(int x, int y){
	int px = findSet(x);
	int py = findSet(y);
	if(rank[px]==rank[py])
		cout << "Invalid query!\n";
	else if(rank[px]>rank[py])
		parent[py] = px;
	else
		parent[px] = py;
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		memset(parent,0,sizeof(parent));
		memset(rank,0,sizeof(rank));
		memset(score,0,sizeof(score));
		
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> score[i];
			createSet(i);
		}

		int q, type, x, y;
		cin >> q;
		while(q--){
			cin >> type >> x;
			if(type == 0){
				cin >> y;
				mergeSets(x,y);
			} else{
				cout << findSet(x) << endl;
			}
		}
	}
	return 0;
}