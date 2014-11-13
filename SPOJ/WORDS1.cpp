#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

#define PI 3.1415926
#define inf 1000000000

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



int main(){
	int t;
	int has[26], in[26], out[26];
	int adj[26][26];
	string s;

	cin >> t;

	while(t--){
		
		int n, x, y, num_chars = 0;
		cin >> n;

		memset(adj,  0, sizeof(adj));
		memset(in, 0, sizeof(in));
		memset(out,0, sizeof(out));
		memset(has,false, sizeof(has));

		rep(i,n){
			cin >> s;
			x = (int)(s[0]-'a');
			y = (int)(s[s.sz-1]-'a');
			adj[x][y] = 1;
			adj[y][x] = 1;
			if(!has[x]){
				num_chars++;
				has[x] = true;
			}
			if(!has[y]){
				num_chars++;
				has[y] = true;
			}
			out[x]++;
			in[y]++;
		}

		bool foundBeg = false, foundEnd = false;
		bool possible = true;

		rep(i,26){
			if( out[i] == in[i] ){
			}
			else if( out[i] == in[i]+1 ){
				if(foundBeg==true){
					possible = false;
					break;
				}
				else{
					foundBeg = true;
				}
			}
			else if( in[i] == out[i]+1 ){
				if(foundEnd==true){
					possible = false;
					break;
				}
				else{
					foundEnd = true;
				}
			}
			else{
				possible = false;
				break;
			}
		}

		if(possible == false || foundBeg!=foundEnd){
			cout << "The door cannot be opened.\n";
			continue;
		}

		// reached here =>(implies) degrees are okay!
		// need to check for connectivity, using bfs.

		bool visited[26];
		memset(visited, 0, sizeof(visited));

		int st = 0;
		while(!has[st]) st++;

		stack<int> next;
		next.push(st);

		while( !next.empty() ){
			int cur = next.top();
			next.pop();
			if(!visited[cur]){
				visited[cur] = true;
				num_chars--;
				rep(i,26){
					if( adj[cur][i] && !visited[i] )
						next.push(i);
				}
			}
		}
		if( num_chars!=0 ){
			possible = false;
		}

		if( possible==true  ){
			cout << "Ordering is possible.\n";
		}
		else{
			cout << "The door cannot be opened.\n";
		}

	}
	return 0;
}


