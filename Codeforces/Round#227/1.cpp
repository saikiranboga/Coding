#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
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

#define Max 1000010

int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	map<int, int> prob;
	int temp;
	int mx = 0;
	forn(i, n){
		cin >> temp;
		mx = mx>temp?mx:temp;
		prob[temp] = 0;
	}
	forn(i, m){
		cin >> temp;
		if(temp>mx || (prob.find(temp)==prob.end()) || prob[temp]==1){
			for(map<int, int>::iterator it = prob.begin(); it != prob.end(); it++){
				if( (it->first <= temp ) && (it->second == 0) ){
					it->second = 1;
					break;
				}
			}
		}
		else{
			prob[temp] = 1;
		}
	}
	int ans = 0;
	for(map<int, int>::iterator it = prob.begin(); it != prob.end(); it++){
		if(it->second == 0)
			ans++;
	}
	cout << ans << endl;

	return 0;
}