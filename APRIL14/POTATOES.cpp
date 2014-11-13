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

#define maxn 2500

vector<int> primes;
 
void generate_primes()
{
   char erat[ maxn ];
   fill( erat, erat + maxn, 0 );
   int i, j;
   for( i = 2; i < maxn; ++i )
      if( !erat[ i ] )
      {
         erat[ i ] = 1;
         for( j = i + i; j < maxn; j += i )
            erat[ j ] = 2;
      }
   for( i = 2; i < maxn; ++i )
      if( erat[ i ] == 1 )
         primes.push_back( i );
}

int main(){
    ios_base::sync_with_stdio(false);
    int t,x,y;
    cin >> t;
    generate_primes();
    while(t--){
        cin >> x >> y;
        int sum = x+y;
        vector<int>::iterator it = upper_bound(primes.begin(), primes.end(), sum);
        cout << primes[it-primes.begin()]-sum << endl;
    }
	return 0;
}