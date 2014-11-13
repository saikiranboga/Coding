/*
ID: saikira2
PROG: numtri
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

typedef struct node
{
    int val;
    int mx;
}node;

node tri[1000][1000];

int main(){
	ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int r;
    fin >> r;
    forn(i, r)
        fori(j, 0, i)
            fin >> tri[i][j].val;
    forn(j, r)
        tri[r-1][j].mx = tri[r-1][j].val;
    if(r > 1){
        fordi(i, r-2, 0)
            fori(j, 0, i)
                tri[i][j].mx = max(tri[i+1][j].mx, tri[i+1][j+1].mx) + tri[i][j].val;
    }
    fout << tri[0][0].mx << endl;
	return 0;
}