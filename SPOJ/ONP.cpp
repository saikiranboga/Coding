#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <stack>
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
	int t;
	cin >> t;
	while(t--){
		stack<char> s;
		string exp;
		cin >> exp;
		for(int i=0;i<exp.size();i++){
			if(exp[i]==')'){
				cout << s.top();
				s.pop();
			}
			else if(exp[i]>='a' && exp[i]<='z'){
				cout << exp[i];
			}
			else if(exp[i]!='('){
				s.push(exp[i]);
			}
		}
		cout << endl;
	}
	return 0;
}