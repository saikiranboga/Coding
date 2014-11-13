/*
ID: saikira2
PROG: gift1
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

typedef pair<int, int> pt;

int main(){

	ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

	int NP;
	fin >> NP;
	map<string, int> account;
	vector< pair<string, int> > init;
	string name;
	forn(i, NP){
		fin >> name;
		account[name] = 0;
		init.pb(mp(name, 0));
	}

	int money, NG;
	string person;
	forn(i, NP){
		fin >> name;
		fin >> money >> NG;
		forn(i, init.size()) {
			if(init[i].first==name)
				init[i].second = money;
		}
		account[name] += money;
		if(NG){
			money -= money%NG;
			account[name] -= money;
			money = money/NG;
		}
		forn(j, NG){
			fin >> person;
			account[person] += money;
		}
	}

	forn(i, init.size()) {
		fout << init[i].first << ' ' << account[init[i].first]-init[i].second << endl;
	}

	return 0;
}