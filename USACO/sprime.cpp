/*
ID: saikira2
PROG: sprime
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

ofstream fout ("sprime.out");
ifstream fin ("sprime.in");

int d[8][5] = {
        {2,3,5,7,9},
        {1,3,5,7,9},
        {1,3,5,7,9},
        {1,3,5,7,9},
        {1,3,5,7,9},
        {1,3,5,7,9},
        {1,3,5,7,9},
        {1,3,5,7,9}
    };

int n;

bool isprime(int n){
    if(n==2)
        return true;
    int up = sqrt(n)+1;
    fori(i, 2, up){
        if(n%i == 0)
            return false;
    }
    return true;
}

void check(int len, int num){
    if(len==n){
        if( isprime(num) ){
            fout << num << endl;
        }
    }
    else if( isprime(num) ){
        forn(i, 5){
            num = num*10 + d[len][i];
            check(len+1, num);
            num /= 10;
        }
    }
    return;
}

int main(){
    fin >> n;
    check(0,0);
	return 0;
}