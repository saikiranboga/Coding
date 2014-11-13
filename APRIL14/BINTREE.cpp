#include <iostream>
#include <iomanip>
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

int main(){
    ios_base::sync_with_stdio(false);
    int n,i,j;
    cin >> n;
    while(n--){
        cin >> i >> j;
        int i_dep = 0;
        int j_dep = 0;
        while(i!=j){
          if(i>j){
            i = i/2;
            i_dep++;
          }
          else if(i<j){
            j = j/2;
            j_dep++;
          }
        }
        cout << i_dep+j_dep << endl;
    }
	return 0;
}