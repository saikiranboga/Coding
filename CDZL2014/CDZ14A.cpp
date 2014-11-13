#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdlib>
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
    int r, b, g;
}node;

int main(){
    int t;
    cin >> t;
    while(t--){
	string s;
    cin >> s;
    int sz = s.size();
    node* l = new node[sz];
    node* r = new node[sz];
    l[0].r = -10000000;
    l[0].b = -10000000;
    l[0].g = -10000000;
    if(s[0]=='R')
        l[0].r = 0;
    else if(s[0]=='B')
        l[0].b = 0;
    else
        l[0].g = 0;
    fore(i, 1, sz){
        l[i].r = l[i-1].r;
        l[i].b = l[i-1].b;
        l[i].g = l[i-1].g;
        if(s[i]=='R')
            l[i].r = i;
        else if(s[i]=='B')
            l[i].b = i;
        else
            l[i].g = i;
    }

    r[sz-1].r = 10000000;
    r[sz-1].b = 10000000;
    r[sz-1].g = 10000000;
    if(s[sz-1]=='R')
        r[sz-1].r = sz-1;
    else if(s[sz-1]=='B')
        r[sz-1].b = sz-1;
    else
        r[sz-1].g = sz-1;
    fordi(i, sz-2, 0){
        r[i].r = r[i+1].r;
        r[i].b = r[i+1].b;
        r[i].g = r[i+1].g;
        if(s[i]=='R')
            r[i].r = i;
        else if(s[i]=='B')
            r[i].b = i;
        else
            r[i].g = i;
    }
    /*
    cout << "l:\n";
    forn(i, sz){
        cout << i << ": " << l[i].r << " " << l[i].b << " " << l[i].g << endl;
    }

    cout << "r:\n";
    forn(i, sz){
        cout << i << ": " << r[i].r << " " << r[i].b << " " << r[i].g << endl;
    }
    */
    int mn = 100000;
    forn(i, sz){
        if(s[i]=='R'){
            //both left
            int dist_l = max( i-l[i].b+1, i-l[i].g+1 );
            //cout << i << ": " << dist_l << " ";
            mn = min(mn, dist_l);

            //both right
            dist_l = max( r[i].b-i+1, r[i].g-i+1);
            //cout << dist_l << " ";
            mn = min(mn, dist_l);

            //one left, one right
            dist_l = r[i].b - l[i].g +1;
            //cout << dist_l << " ";
            mn = min(mn, dist_l);

            dist_l = r[i].g - l[i].b + 1;
            //cout << dist_l << endl;
            mn = min(mn, dist_l);
        }
        else if(s[i]=='B'){
            //both left
            int dist_l = max( i-l[i].r+1, i-l[i].g+1 );
            //cout << i << ": " << dist_l << " ";
            mn = min(mn, dist_l);

            //both right
            dist_l = max( r[i].r-i+1, r[i].g-i+1);
            //cout << dist_l << " ";
            mn = min(mn, dist_l);

            //one left, one right
            dist_l = r[i].r - l[i].g +1;
            //cout << dist_l << " ";
            mn = min(mn, dist_l);

            dist_l = r[i].g - l[i].r + 1;
            //cout << dist_l << endl;
            mn = min(mn, dist_l);
        }
        else if(s[i]=='G'){
            //both left
            int dist_l = max( i-l[i].b+1, i-l[i].r+1 );
            //cout << i << ": " << dist_l << " ";
            mn = min(mn, dist_l);

            //both right
            dist_l = max( r[i].b-i+1, r[i].r-i+1);
            //cout << dist_l << " ";
            mn = min(mn, dist_l);

            //one left, one right
            dist_l = r[i].b - l[i].r +1;
            //cout << dist_l << " ";
            mn = min(mn, dist_l);

            dist_l = r[i].r - l[i].b + 1;
            //cout << dist_l << endl;
            mn = min(mn, dist_l);
        }

    }

    cout << mn << endl;
    }
	return 0;
}