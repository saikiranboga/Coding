#include <bits/stdc++.h>
#include <string.h>
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
#define ll long long int

int main(){
	string hn, an;
	int away[100], home[100];
	int away_t[100], home_t[100];
	for (int i = 0; i < 100; ++i){
		away[i] = home[i] = away_t[i] = home_t[i] = 0;
	}

	int n;
	cin >> hn >> an;
	cin >> n;
	int t, pn;
	string team, card;
	vector< PII > reds;
	for (int i = 0; i < n; ++i) {
		cin >> t >> team >> pn >> card;
		if(team == "h"){
			if(card == "r"){
				if(home[pn]<2){
					home[pn] = 2;
					home_t[pn] = t;
					reds.pb( mp(0, pn) );
				}
			}
			else{
				home[pn]++;
				if(home[pn]==2){
					home_t[pn] = t;
					reds.pb( mp(0, pn) );
				}
			}
		}
		else{
			if(card == "r"){
				if(away[pn]<2){
					away[pn] = 2;
					away_t[pn] = t;
					reds.pb( mp(1, pn) );
				}
			}
			else{
				away[pn]++;
				if(away[pn]==2){
					away_t[pn] = t;
					reds.pb( mp(1, pn) );
				}
			}
		}
	}
	for (int i = 0; i < reds.sz; ++i)
	{
		if(reds[i].ff==0){
			cout << hn << " " << reds[i].ss << " " << home_t[reds[i].ss] << endl;
		}
		else{
			cout << an << " " << reds[i].ss << " " << away_t[reds[i].ss] << endl;
		}
	}
	return 0;
}