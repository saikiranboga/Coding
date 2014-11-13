#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

bool intx(PII a, PII b){
	if(a.ff <= b.ff){
		if( a.ss >= b.ff)
			return true;
		return false;
	}
	else{
		if( b.ss >= a.ff )
			return true;
		return false;
	}
	return false;
}

int main(){
	int p,q,l,r;
	cin >> p >> q >> l >> r;

	vector< PII > x, z, tmp;

	int a,b;
	for(int i=0;i<p; i++){
		cin >> a >> b;
		z.pb( mp(a,b) );
	}

	for(int i=0;i<q; i++){
		cin >> a >> b;
		x.pb( mp(a,b) );
		tmp.pb( mp(a,b) );
	}


	int ans = 0;
	for(int t=l; t<=r; t++){

		for(int i=0;i<q; i++){
			tmp[i].ff = x[i].ff + t;
			tmp[i].ss = x[i].ss + t;
		}

		bool suit = false;

		for(int i=0; (i<q) && (suit==false); i++){

			for(int j=0; j<p; j++){
				if( intx(tmp[i], z[j]) ){
					ans++;
					suit = true;
					break;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}