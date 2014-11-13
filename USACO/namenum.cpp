/*
ID: saikira2
PROG: namenum
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

int main(){
    ifstream fin ("namenum.in");
    ofstream fout ("namenum.out");
    ifstream fin2 ("dict.txt");

    ll n;
    fin >> n;
    string name;
    ll num;
    vector< pair<ll, string> > as;
    map<char, int> val;

    val['A'] = 2; val['B'] = 2; val['C'] = 2;
    val['D'] = 3; val['E'] = 3; val['F'] = 3;
    val['G'] = 4; val['H'] = 4; val['I'] = 4;
    val['J'] = 5; val['K'] = 5; val['L'] = 5;
    val['M'] = 6; val['N'] = 6; val['O'] = 6;
    val['P'] = 7; val['R'] = 7; val['S'] = 7;
    val['T'] = 8; val['U'] = 8; val['V'] = 8;
    val['W'] = 9; val['X'] = 9; val['Y'] = 9;

    while(fin2 >> name){
        //fout << name << endl;
        num = 0;
        forn(i, name.size())
            num = num*10 + val[name[i]];
        as.pb( mp(num, name) );
    }

    //forn(i, as.size()){
    //    fout << as[i].F << " " << as[i].S << endl;
    //}

    int flag = 0;
    forn(i, as.size()){
        if(as[i].F == n){
            fout << as[i].S << endl;
            flag = 1;
        }
    }

    if(!flag){
        fout << "NONE\n";
    }

	return 0;
}