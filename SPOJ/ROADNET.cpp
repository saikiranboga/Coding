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

int w[210][210];
int dist[210][210];
int mark[210][210];

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		memset(w, 0,sizeof(w) );
		memset(dist, 0,sizeof(dist) );
		memset(mark, 0,sizeof(mark) );

		fu(i,1,n){
			fu(j,1,n){
				cin >> w[i][j];
				dist[i][j] = w[i][j];
			}
		}

		//floyd-warshall algorithm
		fu(k,1,n){
			fu(i,1,n){
				fu(j,1,n){
					if(i==j || i==k || j==k)
						continue;
					if( dist[i][j] > dist[i][k] + dist[k][j] ){
						//cout << "0: " << i << " " << j << " " << k << endl;
						dist[i][j] = dist[i][k] + dist[k][j];
						mark[i][j] = 0;
					}
					else if( dist[i][j] == dist[i][k] + dist[k][j] ){
						//cout << "1: " << i << " " << k << " " << j << endl;
						mark[i][j] = 1;
					}
				}
			}
		}
		//end

		/*
		cout << endl;
		fu(i,1,n){
			fu(j,1,n){
				cout << dist[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		fu(i,1,n){
			fu(j,1,n){
				cout << mark[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/

		fu(i,1,n){
			fu(j,i+1,n){
				if( mark[i][j]==0 ){
					cout << i << " " << j << endl;
				}
			}
		}

	}
	return 0;
}