/*
ID: saikira2
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

#define ll long long

#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define ford(i, up, bot) for(int i = (up); i > (bot); --i)
#define fordi(i, up, bot) ford(i, up, bot-1)

#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pt;

bool comp(int a, int b){
    return a > b;
}

int main(){
	ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int m, s, c;
    fin >> m >> s >> c;
    int stalls[c];
    forn(i, c)
        fin >> stalls[i];

    sort(stalls, stalls+c);
    vector<int> gaps;
    fore(i, 1, c)
        gaps.pb( stalls[i]-stalls[i-1] );

    sort( gaps.begin(), gaps.end() , comp);

    vector<int> split;

    int ans = 0;
    if(m>=c){
        ans = c;
    }
    else if(m == 1){
        ans = stalls[c-1] - stalls[0] + 1;
    }
    else{
        ans = m;
        fore(i, m-1, c-1)
            ans += gaps[i];
    }

    fout << ans << endl;

	return 0;
}