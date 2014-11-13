/*
ID: freeman92
PROG: BALLS
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

#define Max 100001

typedef struct node
{
    int count[3];
}node;

bool comp(node a, node b){
    return a.count[0] > b.count[0];
}

int main(){
    int n;
    cin >> n;
    node ct[Max];
    forn(i, Max){
        ct[i].count[0] = 0;
        ct[i].count[1] = 0;
        ct[i].count[2] = 0;
    }

    int p1, p2;
    forn(i, n){
        cin >> p1 >> p2;
        if(p1 == p2){
            ct[p1].count[0]++;
            ct[p1].count[1]++;
            ct[p1].count[2]++;
        }
        else{
            ct[p1].count[0]++;
            ct[p2].count[0]++;
            ct[p1].count[1]++;
            ct[p2].count[2]++;
        }
    }

    sort(ct, ct+Max, comp);
    /*
    forn(i, n){
        cout << i << " ";
        cout << ct[i].count[0] << " ";
        cout << ct[i].count[1] << " ";
        cout << ct[i].count[2] << endl;
    }
    */
    int atl;
    
    if(n&1)
        atl = n/2+1;
    else
        atl = n/2;
    
    //atl = n/2;
    if(ct[0].count[0]>=atl){
        int mx_top = ct[0].count[1];
        int mx_bottom = ct[0].count[2];

        fore(i, 1, n){
            if(ct[i].count[0]<atl)
                break;
            else{
                mx_top = max(mx_top, ct[i].count[1]);
                mx_bottom = max(mx_bottom, ct[i].count[2]);
            }
        }
        if(mx_top < atl)
            cout << atl-mx_top << endl;
        else
            cout << 0 << endl;
    }
    else{
        cout << "Impossible\n";
    }

	return 0;
}