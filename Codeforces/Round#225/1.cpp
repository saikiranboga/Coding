//codeforces 384B
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

int main(){
	ios::sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	int a[n+1][m+1];
	
	fori(i, 1, n)
		fori(j, 1, m)
			cin >> a[i][j];

	cout << (m*(m-1))/2 << endl;
	fori(i, 1, m){
		fori(j, i+1, m){
			if(k==0)
				cout << i << ' ' << j << endl;
			else
				cout << j << ' ' << i << endl;
		}
	}

	return 0;
}