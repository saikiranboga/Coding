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

bool comp(int a, int b){
	return a > b;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;

	int ans = 0;
	forn(i, n){
		if(s[i]=='.'){
			int lf = i-1;
			while(lf>=0 && s[lf]=='.') lf--;
			int rt = i+1;
			while(rt<n && s[rt]=='.') rt++;
			if( lf<0 && rt>=n ){
				//cout << i << " -1 ";
				ans++;
			}
			else if( s[lf]=='L' && s[rt]=='R' ){
				//cout << i << " -2 ";
				ans++;
			}
			else if( (lf<0 && s[rt]=='R') || (s[lf]=='L' && rt>=n) ){
				//cout << i << " -3 ";
				ans++;
			}
			else if( (lf<0 && s[rt]=='L') || (s[lf]=='R' && rt>=n) ){
			}
			else if( i-lf==rt-i ){
				//cout << i << " -4 ";
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}