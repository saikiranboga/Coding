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
	int n;
	cin >> n;
	int box[n];
	bool used[n];
	forn(i, n){
		cin >> box[i];
		used[i] = false;
	}	

	sort(box, box+n);

	int up = 0;
	int ans = 0;
	forn(i, n){
		if(used[i]==false){
			up = 1;
			used[i] = true;
			fore(j, i+1, n){
				if(!used[j] && box[j]>=up){
					up++;
					used[j] = true;
				}
			}
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}