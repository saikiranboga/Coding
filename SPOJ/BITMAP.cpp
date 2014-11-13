#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define inf 1000

bitset<200> b[200];
bool visited[200][200];
int ans[200][200];
int n, m;

queue<pair<int,int> > qu;

vector< pair<int,int> > ones;

void clear( queue<pair<int,int> > &q )
{
	queue<pair<int,int> > empty;
	swap( q, empty );
}

void bfs(pair<int, int> p){
	
	int r = p.F, c = p.S;

	pair<int, int> next;

	int dist = 0;
	int cr = r,cc = c;

	if(cr-1>=0 && !visited[cr-1][cc]){
		qu.push( mp(cr-1,cc) );
		visited[cr-1][cc] = true;
	}
	if(cr+1<n && !visited[cr+1][cc]){
		qu.push( mp(cr+1,cc) );
		visited[cr+1][cc] = true;
	}
	if(cc-1>=0 && !visited[cr][cc-1]){
		qu.push( mp(cr,cc-1) );
		visited[cr][cc-1] = true;
	}
	if(cc+1<m && !visited[cr][cc+1]){
		qu.push( mp(cr,cc+1) );
		visited[cr][cc+1] = true;
	}

	while(!qu.empty()){
		next = qu.front();
		qu.pop();
		cr = next.F;
		cc = next.S;
		if(b[cr][cc]==0){
			dist = abs(cr-r)+abs(cc-c);
			if(ans[cr][cc]>dist){
				ans[cr][cc] = dist;
				if(cr-1>=0 && !visited[cr-1][cc]){
					qu.push( mp(cr-1,cc) );
					visited[cr-1][cc] = true;
				}
				if(cr+1<n && !visited[cr+1][cc]){
					qu.push( mp(cr+1,cc) );
					visited[cr+1][cc] = true;
				}
				if(cc-1>=0 && !visited[cr][cc-1]){
					qu.push( mp(cr,cc-1) );
					visited[cr][cc-1] = true;
				}
				if(cc+1<m && !visited[cr][cc+1]){
					qu.push( mp(cr,cc+1) );
					visited[cr][cc+1] = true;
				}
			}
		}
	}
}

int main(){
	int t;
	string s;
	cin >> t;
	while(t--){
		cin >> n >> m;

		ones.clear();

		for(int i=0;i<n;i++){
			cin >> s;
			b[i].reset();
			for(int j=0;j<m;j++)
				if(s[j]=='1'){
					b[i].set(j);
					ones.pb(mp(i,j));
					ans[i][j] = 0;
				}
				else{
					ans[i][j] = inf;
				}
			}

			for(int i=0;i<ones.size();i++){
				memset(visited,false,sizeof(visited));
				bfs(ones[i]);
			}

			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cout << ans[i][j] << " ";
				}
				cout << endl;
			}

		}
		return 0;
	}