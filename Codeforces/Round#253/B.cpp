#include <iostream>
#include <string>
#include <string.h>
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

int findMaxTandemRepeat(string s){
	int max_len = 0;
	int sz = s.size();
	
	fori(len, 1, sz/2){
		for(int start=0;sz-start-2*len>=0;start++){
			//cout << start << " " << len << endl;
			int st1 = start;
			int st2 = start+len;
			int l = 0;
			while(l<len){
				if(s[st1]=='?' || s[st2]=='?'){
					//do nothing
				}
				else if(s[st1]!=s[st2]){
					break;
				}
				st1++;
				st2++;
				l++;
			}
			if(l==len){
				if(len>max_len){
					max_len = len;
					break;
				}
			}
		}
	}
	return 2*max_len;
}

int main(){
	ios::sync_with_stdio(false);
	string s;
	int n,k;
	cin >> s >> k;
	n = s.size();
	s.append(string(k,'?'));
	cout << findMaxTandemRepeat(s) << endl;
	return 0;
}