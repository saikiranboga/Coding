
/*
ID: freeman92
LANG: C++
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cmath>
#include <stdint.h>
#include <unistd.h>
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
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    forn(i, 250000){
        int n = rand()%26;
        cout << (char)('a'+n);
    }
    cout << "\n";
    forn(i, 250000){
        int n = rand()%26;
        cout << (char)('a'+n);
    }
    return 0;
}