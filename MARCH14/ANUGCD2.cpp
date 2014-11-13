
/*
ID: freeman92
PROG: ANUGCD2
LANG: C++
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cmath>
#include <stdint.h>
#include <unistd.h>
using namespace std;

#define ll long long

#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define ford(i, up, bot) for(int i = (up); i > (bot); --i)
#define fordi(i, up, bot) ford(i, up, bot-1)

#define pb push_back
#define mp make_pair
#define num first
#define idx second
typedef pair<int, int> pt;
#define Max 100100

vector<int> primes;
int a[Max];
vector<int> nb[Max];
vector<int> index[Max];

void get_primes(){
    char *sieve;
    sieve = new char[Max/8+1];
    // Fill sieve with 1  
    memset(sieve, 0xFF, (Max/8+1) * sizeof(char));
    for(int x = 2; x <= Max; x++)
        if(sieve[x/8] & (0x01 << (x % 8))){
            primes.push_back(x);
            // Is prime. Mark multiplicates.
            for(int j = 2*x; j <= Max; j += x)
                sieve[j/8] &= ~(0x01 << (j % 8));
        }
    delete[] sieve;
    return;
}

//segment tree

node best_node( node lval, node rval )
{
   if( lval.num == rval.num && lval.num != -1 )
      lval.cnt += rval.cnt;
   return lval.num < rval.num ? rval : lval;
}

node build( int ti, int ni, int from, int to ){
   if(from==to){
      st[ ti ][ ni ].num = nums[ ti ][ from ];
      st[ ti ][ ni ].cnt = 1;
      return st[ ti ][ ni ];
   }
   int mid = ( from + to ) / 2;
   node lval = build( ti, ni * 2, from, mid  );
   node rval = build( ti, ni * 2 + 1, mid + 1, to );
   return trees[ ti ][ ni ] = best_node( lval, rval );
}

node get_max( int ti, int ni, int from, int to, int l, int r ){
   l = max( l, from );
   r = min( r, to );
   if( r < from || l > to )
      return node();
   if( l == from && r == to )
      return trees[ ti ][ ni ];
   int mid = ( from + to ) / 2;
   node lval = get_max( ti, ni * 2, from, mid, l, r );
   node rval = get_max( ti, ni * 2 + 1, mid + 1, to, l, r );
   return best_node( lval, rval );
}

//end of seg tree

int main(){
    ios_base::sync_with_stdio(false);
    get_primes();
    int n, m;
    cin >> n >> m;
    forn(i, n){
        cin >> a[i];
        int cur = a[i];
        while(cur>1){
            int pi = 0;
            
            //first prime factor of cur
            while( (cur%primes[pi])>0 ) pi++;

            cur_prime = primes[pi];

            while(cur%cur_prime==0)
                cur = cur/cur_prime;

            //store the index and the number in the index table of primes
            index[cur_prime].pb(i+1);
            nb[cur_prime].pb(a[i]);
            pi++;
        }
    }

    int sz = primes.size();
    forn(i, sz){
        if(index[i].size()>0){
            int s = index[i].size();
            st[i].resize(s*3);
            build(i,1,0,s-1);
        }
    }

    int G, l, r;
    forn(i, m){
        cin >> G >> l >> r;
        int cur = G;
        while(cur>1){
            int pi = 0;
            
            //first prime factor of cur
            while( (cur%primes[pi])>0 ) pi++;

            cur_prime = primes[pi];

            while(cur%cur_prime==0)
                cur = cur/cur_prime;

            l = lower_bound(index[j].begin(), index[j].end(),l);
            r = upper_bound(index[j].begin(), index[j].end(),r);

            //store the index and the number in the index table of primes
            index[cur_prime].push_back(mp(a[i],i));
            pi++;
        }
    }

    return 0;
}