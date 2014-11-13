/*
ID: saikira2
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
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

typedef pair<int, int> pt;

enum {Sa=0,Su,M,T,W,Th,F};

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n;
    fin >> n;
    int mnths = n*12;
    int year = 1900;
    int first = M;
    int m, freq[7];
    memset(freq, 0, sizeof(freq));
    fori(i, 1, mnths){
    	m = i%12;
    		if(m == 2){
    			if(year%100==0){
    				if(year%400==0){
    					//centurion leap-year
    					freq[(first+5)%7]++;
    					//cout << (first+5)%7 << endl;
    					//change first, increment it by 1
    					first = (first+1)%7;
    				}
    				else{
    					//centurion non-leap year
    					freq[(first+5)%7]++;
    					//cout << (first+5)%7 << endl;
    					//dont change first, it remains same
    				}
    			}
    			else{
    				if( year%4>0 ){
    					// non-leap year
    					freq[(first+5)%7]++;
    					//cout << (first+5)%7 << endl;
    					//dont change first, it remains same
    				}
    				else{
    					//leap year
    					freq[(first+5)%7]++;
    					//cout << (first+5)%7 << endl;
    					//change first, increment it by 1
    					first = (first+1)%7;
    				}
    			}
    		}
    		else if( (m==4) || (m==6) || (m==9) || (m==11) ){
    			freq[(first+5)%7]++;
	    		//cout << (first+5)%7 << endl;
    			first = (first+2)%7;
    		}
			else{
				freq[(first+5)%7]++;
				//cout << (first+5)%7 << endl;
    			first = (first+3)%7;
			}

    		if(m==0){
    			//cout << year << endl;
    			//cout << endl;
    			year++;
    		}
    }

    forn(i, 6)
    	fout << freq[i] << ' ';
    fout << freq[6] << endl;
    return 0;
}