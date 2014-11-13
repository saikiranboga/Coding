/*
ID: saikira2
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
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

bool isprime(int n){
    int up = sqrt(n)+1;
    fori(i, 2, up){
        if(n%i == 0)
            return false;
    }
    return true;
}

int main(){
	ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    
    int a, b;
    fin >> a >> b;

    int a_len = 0;
    int tmp = a;
    while(tmp){
        a_len++;
        tmp /= 10;
    }
    int num;
    vector<int> ppals;

    ppals.pb(5);
    ppals.pb(7);
    ppals.pb(11);

    for(int d1=1; d1<=9; d1+=2){
        fori(d2, 0, 9){

            num = d1*101 + d2*10;
            //fout << num << endl;
            if( isprime(num) )
                ppals.pb(num);

            num = d1*1001 + d2*110;
            //fout << num << endl;
            if( isprime(num) )
                ppals.pb(num);

            fori(d3, 0, 9){

                num = d1*10001 + d2*1010 + d3*100;
                //fout << num << endl;
                if( isprime(num) )
                    ppals.pb(num);

                num = d1*100001 + d2*10010 + d3*1100;
                //fout << num << endl;
                if( isprime(num) )
                    ppals.pb(num);
                fori(d4, 0, 9){

                    num = d1*1000001 + d2*100010 + d3*10100 + d4*1000;
                    //fout << num << endl;
                    if( isprime(num) )
                        ppals.pb(num);

                    num = d1*10000001 + d2*1000010 + d3*100100 + d4*11000;
                    //fout << num << endl;
                    if( isprime(num) )
                        ppals.pb(num);
                }
            }
        }
    }

    sort( ppals.begin(), ppals.end() );

    vector<int>::iterator it;
    it = lower_bound(ppals.begin(), ppals.end(), a);
    int pos = it-ppals.begin();
    int sz = ppals.size();

    while(pos<sz && ppals[pos]<=b){
        fout << ppals[pos] << endl;
        pos++;
    }

	return 0;
}