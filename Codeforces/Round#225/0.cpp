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
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	if(n%2==0){
		cout << ( (n*n)/2 ) << endl;
		forn(i, n){
			if(i%2==0){
				forn(j, n/2)
					cout << 'C' << '.';
				cout << endl;
			}
			else{
				forn(j, n/2)
					cout << '.' << 'C';	
				cout << endl;
			}
		}
	}
	else{
		int a = n/2;
		int ans = a+1;
		ans *= ans;
		ans = ans + (a*a);
		cout << ans << endl;
		forn(i, n){
			if(i%2==0){
				forn(j, n/2)
					cout << 'C' << '.';
				cout << 'C' << endl;
			}
			else{
				forn(j, n/2)
					cout << '.' << 'C';	
				cout << '.' << endl;
			}
		}
	}
	return 0;
}