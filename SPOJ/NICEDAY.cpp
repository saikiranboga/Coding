#include <bits/stdc++.h>
using namespace std;

#define M 100010

typedef struct Node
{
	int x, y, z;
	bool operator<(const Node& oth) const {
		return x < oth.x;
	}
}Node;

bool compare(Node a, Node b){
	return a.z < b.z;
}

Node ip[M]; // sorted acc to z
set<Node> S; // sorted acc to x
vector<Node> V; // points to be removed

bool inside(int i){
	set<Node>::iterator it =  S.lower_bound(ip[i]);
	if(it==S.begin())
		return false;
	it--; // if lower point found then check for y axis, bcoz
		  // we have already know cur point has higher z and x axis values
	return it->y < ip[i].y;
}

int main(){
	ios::sync_with_stdio(false);
	int t, n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d %d %d", &ip[i].x, &ip[i].y, &ip[i].z);
		sort(ip, ip+n, compare);
		S.clear();
		S.insert(ip[0]); // sentinel
		int ans = 1;
		set<Node>::iterator it;
		for(int i=1;i<n;i++){
			if( inside(i) )
				continue;
			ans++;
			V.clear();
			for(it=S.lower_bound(ip[i]); it!=S.end(); it++){
				if(it->y > ip[i].y)
					V.push_back(*it); // add to the points to be removed
				else
					break;
			}
			for(int j=0;j<V.size(); j++)
				S.erase(V[j]);
			S.insert(ip[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}