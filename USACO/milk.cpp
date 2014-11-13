/*
ID: saikira2
PROG: milk
LANG: C++
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <string>
#include <cmath>
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
	ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int n, m;
    fin >> n >> m;
    vector<pt> price;
    int cost, qnt;
    forn(i, m){
        fin >> cost >> qnt;
        price.pb( mp(cost, qnt) );
    }
    sort( price.begin(), price.end() );

    int tc = 0;

    forn(i, n){
        if(n){
            if(price[i].S <= n){
                tc += (price[i].F*price[i].S);
                n -= price[i].S;
            }
            else{
                tc += (price[i].F*n);
                n -= n;
            }
        }
        else{
            break;
        }
    }
    fout << tc << endl;
	return 0;
}