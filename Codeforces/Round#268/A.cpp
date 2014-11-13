#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

int main(){
	
	int n, m;
	cin >> n;
	
	int ans = 0;
	int p, q;
	
	int mark[n+1];
	for(int i=0;i<=n;i++)
		mark[i] = 0;
	
	int x;

	cin >> p;
	for(int i=0;i<p;i++){
		cin >> x;
		mark[x] = 1;
	}

	cin >> q;
	for(int i=0;i<q;i++){
		cin >> x;
		mark[x] = 1;
	}

	bool pos = true;
	for(int i=1;i<=n;i++){
		if( mark[i] == 0){
			pos = false;
			break;
		}

	}

	if(pos==true){
		cout << "I become the guy.\n";
	}
	else{
		cout << "Oh, my keyboard!\n";
	}

	return 0;
}