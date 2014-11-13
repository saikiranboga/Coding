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

ofstream fout ("test_cases.out");
ifstream fin ("test_cases.in");

int main(){
    srand( time(NULL) );
    forn(t, 50){
        int N = 1+rand()%200;
        int k = 1+rand()%N;
        if(k==N)
            continue;
        fout << N << " " << k << endl;
        k = 1+rand()%N;
        int a[N];
        forn(i, N){
            double p = rand()%100;
            if(i>0 && p < 30)
                a[i] = a[i-1];
            else
                a[i] = 1+rand()%200;
            fout << a[i] << " ";
        }
        fout << endl;
    }
	return 0;
}