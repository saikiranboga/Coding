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
//ifstream fin ("test_cases.in");

int main(){
    srand( time(NULL) );
    fout << 10 << endl;
    forn(t, 10){
        int N = (90-60+1)+rand()%60;
        int M = (90-60+1)+rand()%60;
        fout << N << " " << M << endl;

        int pij;
        int a[N][M];
        forn(i, N){
            forn(j, M){
                pij = 1+rand()%10;
                a[i][j] = rand()%pij;
                fout << pij << " ";
            }
            fout << endl;
        }
        forn(i, N){
            forn(j, M)
                fout << a[i][j] << " ";
            fout << endl;
        }
        fout << endl;
    }
	return 0;
}