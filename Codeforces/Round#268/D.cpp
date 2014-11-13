#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define MX 100010
#define MOD 1000000007

int nrs(string s){
	int sz = s.size();
	int ret = 0;
	for(int i=0; i<sz; i++)
		if(s[i]=='r')
			ret++;
	return ret;
}

int main(){
	int m,n;
	cin >> m;
	
	string ar[MX];
	map<string,string> ess;
	
	for(int i=0; i<m; i++){
		cin >> ar[i];
		transform(ar[i].begin(), ar[i].end(), ar[i].begin(), ::tolower);
		ess[ ar[i] ] = ar[i];
	}

	cin >> n;
	string x, y;
	string org, rep;
	int r_org, r_rep;
	for(int i=0; i<n; i++){
		cin >> x >> y;
		transform(x.begin(), x.end(), x.begin(), ::tolower);
		transform(y.begin(), y.end(), y.begin(), ::tolower);
		org = ess[x];
		rep = y;
		r_org = nrs(org);
		r_rep = nrs(rep);
		
		if( r_org < r_rep )
			continue;
		else if( r_org == r_rep ){
			if( org.size() > rep.size() )
				ess[x] = rep;
		}
		else
			ess[x] = rep;
	}

	int len = 0;
	int rs = 0;
	for(int i=0; i<m; i++){
		rs += nrs(ess[ ar[i] ]);
		len += ess[ ar[i] ].size();
	}

	cout << rs << " " << len << endl;

	return 0;
}