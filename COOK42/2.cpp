#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define ll long long

#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define ford(i, up, bot) for(int i = (up); i > (bot); --i)
#define fordi(i, up, bot) ford(i, up, bot-1)

#define pb push_back
#define mp make_pair

typedef pair<int, int> pt;

bool comp(pt a, pt b){
	return a.second < b.second;
}

int main(){
	int t, n, x, s, e;
	cin >> t;
	while(t--){
		cin >> n >> x;
		vector<pt> se(n);
		bool inter[n];
		forn(i, n){
			cin >> s >> e;
			se[i].first = s;
			se[i].second = e;
			inter[i] = false;
		}

		sort( se.begin(), se.end(), comp);

		forn(i, n){
			int endi = se[i].second;
			vector<int> v;
			forn(j, n){
				if( (se[j].first<=endi) && (endi<=se[j].second) )
					if(!inter[j])
						v.pb(j);
			}
			fordi(j, v.size()-1, x-1)
				inter[v[j]] = true;
		}

		int ans = 0;
		forn(i, n)
			if(inter[i])
				ans++;

		cout << ans << endl;
	}
	return 0;
}