#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL adj[2005][40];

int main(){
	int n;
	cin >> n;
	LL block, pw;
	string s;

	memset(adj,0,sizeof(adj));

	for(int i=0;i<n;i++){
		cin >> s;
		for(int j=0;j<n;j++){
			if(s[j]=='0') continue;
			block = j/64;
			pw = j%64;
			adj[i][block] |= (1LL<<pw);
		}
	}

	int p = (n+63)/64;
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) continue;
			block = j/64;
			pw = j%64;
			if(adj[i][block] & (1LL<<pw) ) continue;
			for(int k=0;k<=p;k++){
				if(adj[i][k]&adj[j][k]){
					ans++;
					break;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}