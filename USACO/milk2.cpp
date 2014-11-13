/*
ID: saikira2
PROG: milk2
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
	ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n;
    fin >> n;
    vector<pt> times(n);
    int st, ed;
    forn(i,n){
    	fin >> st >> ed;
    	times[i].F = st;
    	times[i].S = ed;
    }
    sort(times.begin(), times.end());

    vector<pt> lr(n);
    lr[0].F = times[0].F;
    lr[n-1].S = times[n-1].S;
    int idle = 0;
    int cont = 0;
    int max_right = times[0].S;

    lr[0].S = times[0].S;
    fore(i,1,n){
    	if(times[i].F <= max_right){
    		//cout << "1\n";
    		lr[i].F = lr[i-1].F;
    		if(times[i].S > max_right)
    			max_right = times[i].S;
    		else{
    			times[i].S = max_right;
    			lr[i].S = max_right;
    		}
    	}
    	else{
    		//cout << "2\n";
    		lr[i].F = times[i].F;
    		// a discontinuity, so calc cont. of prev
    		if( (max_right - lr[i-1].F) > cont )
    			cont = (max_right - lr[i-1].F);

    		// change cur max_right
    		max_right = times[i].S;
    		if( (times[i].F-times[i-1].S) > idle)
    			idle = (times[i].F-times[i-1].S);
    	}
    	//cout << lr[i].F << " " << lr[i].S << endl;
    }

    if( (max_right - lr[n-1].F) > cont )
    	cont = (max_right - lr[n-1].F);

    /*
    fordi(i,n-2,0){
    	if(times[i].S >= times[i+1].F)
    		lr[i].S = lr[i+1].S;
    	else{
    		lr[i].S = times[i].S;
    		if( (times[i+1].F-times[i].S) > idle)
    			idle = (times[i+1].F-times[i].S);
    	}
    }
/*
    forn(i,n){
    	if( (lr[i].S - lr[i].F) > cont )
    		cont = (lr[i].S - lr[i].F);
    }
*/
    fout << cont << " " << idle << endl;

	return 0;
}