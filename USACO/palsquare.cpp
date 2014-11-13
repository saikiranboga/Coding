/*
ID: saikira2
PROG: palsquare
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

map<int, char> sub;

string convert(int n, int base){
    string ret = "";
    while(n>=base){
        ret = sub[ n%base ] + ret;
        n = n/base;
    }
    ret = sub[n] + ret;
    return ret;
}

bool isPalin(string s){
    int sz = s.size();
    forn(i, sz/2)
        if(s[i]!=s[sz-1-i])
            return false;
    return true;
}

int main(){
	ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int base;
    fin >> base;
    
    sub[0] = '0';
    sub[1] = '1';
    sub[2] = '2';
    sub[3] = '3';
    sub[4] = '4';
    sub[5] = '5';
    sub[6] = '6';
    sub[7] = '7';
    sub[8] = '8';
    sub[9] = '9';
    sub[10] = 'A';
    sub[11] = 'B';
    sub[12] = 'C';
    sub[13] = 'D';
    sub[14] = 'E';
    sub[15] = 'F';
    sub[16] = 'G';
    sub[17] = 'H';
    sub[18] = 'I';
    sub[19] = 'J';
    sub[20] = 'K';

    fori(i, 1, 300)
        if( isPalin( convert(i*i, base) ) )
            fout << convert(i, base) << " " << convert(i*i, base) << endl;
	return 0;
}