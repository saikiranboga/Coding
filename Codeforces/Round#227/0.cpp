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

int main(){
	ios::sync_with_stdio(false);
	
	string s;
	cin >> s;
	int s_hh = (s[0]-'0')*10 + (s[1]-'0');
	int s_mm = (s[3]-'0')*10 + (s[4]-'0');

	string t;
	cin >> t;
	int t_hh = (t[0]-'0')*10 + (t[1]-'0');
	int t_mm = (t[3]-'0')*10 + (t[4]-'0');	

	int ans_hh, ans_mm;

	if(s_mm-t_mm < 0){
		ans_hh = 24+s_hh-t_hh-1;
		ans_hh %= 24;
		ans_mm = 60+s_mm-t_mm;
	}
	else{
		ans_hh = 24+s_hh-t_hh;
		ans_hh %= 24;
		ans_mm = s_mm-t_mm;
	}
	cout <<  setfill('0') << setw(2) << ans_hh << ":" <<  setfill('0') << setw(2) << ans_mm << endl;
	return 0;
}