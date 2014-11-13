/*
ID: saikira2
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstring>
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
	freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    
    int n,m;
    scanf("%d %d", &n, &m);
    int mx = 250*250*2 + 1;
    int exist[250*250*2 + 1] = {0};
    //memset(exist, 0, mx);

    fori(p, 0, m)
        fori(q, p, m)
            exist[p*p + q*q] = 1;

    int sols = 0;
    fori(b, 1, m*m){
        fori(a, 0, 2*m*m-(b*(n-1)) ){
            int i;
            for(i=0; i<n && exist[a+b*i]; i++);
            if(i==n){
                sols++;
                printf("%d %d\n", a, b);
            }
        }
    }
    if(!sols)
        puts("NONE");
	return 0;
}