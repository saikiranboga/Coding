#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main(){
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		vector<int> gd, mgd;
		int x;
		for(int i=0;i<a;i++){
			cin >> x;
			gd.pb(x);
		}
		for(int i=0;i<b;i++){
			cin >> x;
			mgd.pb(x);
		}

		sort(gd.begin(), gd.end());
		sort(mgd.begin(), mgd.end());

		int id1 = 0, id2 = 0;
		while(id1!=a && id2!=b){
			if(gd[id1]>=mgd[id2]){
				id2++;
			} else{
				id1++;
			}
		}
		if(id1==a)
			cout << "MechaGodzilla\n";
		else
			cout << "Godzilla\n";
	}
	return 0;
}