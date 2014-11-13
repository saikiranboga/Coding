#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
	if(a.first < b.first)
		return true;
	else if(a.first > b.first)
		return false;
	else
		return a.second <= b.second;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int A[n+1];
		for(int i=1;i<=n;i++)
			cin >> A[i];
		vector< pair<int, int> > lr;
		int x, y;
		for(int j=0;j<m;j++){
			cin >> x >> y;
			lr.push_back( make_pair(x,y) );
		}
		sort(lr.begin(), lr.end(), comp);

		bool posb = true;
		bool mark[n+1];
		memset(mark, false, sizeof(mark));

		for(int i=0; posb && i<m; ){
			x = lr[i].first;
			y = lr[i].second;
			int j;
			for(j=i+1; j<m; ){
				if(lr[j].first<=y){
					y = max(y, lr[j].second);
					j++;
				}
				else
					break;
			}

			i = j;

			for(j=x; j<=y; j++){
				mark[j] = true;
				if( !(A[j]>=x && A[j]<=y) ){
					posb = false;
					break;
				}
			}
		}

		if(posb){
			for(int i=1; i<=n; i++){
				if(!mark[i])
					if(A[i]!=i){
						posb = false;
						break;
					}
			}
		}

		if(posb)
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}
	return 0;
}