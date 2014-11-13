#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
 
const int maxn = 100100;
 
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
 
 
// tree node: the maximum number in the interval and the quantity of that number
struct node
{
   node() : num( -1 ), cnt( -1 ) {}
   int num;
   int cnt;
};
 
// nearly primes quantity between 1-10000
const int maxp = 10000;
 
// for each prime p store:
// a vector of numbers in input divisible by p
// a vector of indexes of corresponding numbers in initial array
// a tree for querying for range max
vector<int> nums[ maxp ];
vector<int> indexes[ maxp ];
vector<node> trees[ maxp ];
 
// combine results from left and right subtrees
// if the max numbers are the same, accumulate cnt-s
// else choose the biggest number
node best_node( node lval, node rval )
{
   if( lval.num == rval.num && lval.num != -1 )
      lval.cnt += rval.cnt;
   return lval.num < rval.num ? rval : lval;
}
 
// ti - tree index, ni - node index, [from, to] - the interval the corresponding node is responsible for
node init_tree( int ti, int ni, int from, int to )
{
   if( from == to )
   {
      trees[ ti ][ ni ].num = nums[ ti ][ from ];
      trees[ ti ][ ni ].cnt = 1;
      return trees[ ti ][ ni ];
   }
   int mid = ( from + to ) / 2;
   node lval = init_tree( ti, ni * 2, from, mid  );
   node rval = init_tree( ti, ni * 2 + 1, mid + 1, to );
   return trees[ ti ][ ni ] = best_node( lval, rval );
}
 
// [l, r] - query segment margins
node get_max( int ti, int ni, int from, int to, int l, int r )
{
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
 
// input
int a[ maxn ];
int n, m;
 
 
int main()
{
   generate_primes();
   cin >> n >> m;
   int x, y, g;
   for( int i = 0; i < n; ++i )
   {
      cin >> a[ i ];
      g = a[ i ];
      int j = 0;
 
      while( g > 1 )
      {
         // find the index next prime factor of g
         while( g % primes[ j ] != 0 && primes[ j ] * primes[ j ] <= g )
            ++j;
         if( g % primes[ j ] != 0 )
         {
            // if g has prime factor > sqrt( g ), find its index
            j = lower_bound( primes.begin(), primes.end(), g ) - primes.begin();
         }
 
         while( g % primes[ j ] == 0 )
            g /= primes[ j ];
 
         // add i-th number information to the j-th prime structures
         nums[ j ].push_back( a[ i ] );
         indexes[ j ].push_back( i + 1 );
 
         ++j;
      }
   }
   for( int i = 0; i < primes.size(); ++i )
   {
      if( nums[ i ].size() == 0 ) // no number dividible by this prime
         continue;
      trees[ i ].resize( nums[ i ].size() * 4 ); // allocate appropriate tree size
      init_tree( i, 1, 0, nums[ i ].size() - 1 );
   }
   for( int i = 0; i < m; ++i )
   {
      cin >> g >> x >> y;
      node res;
      int j = 0;
      while( g > 1 )
      {
         // the same as in input, find the index of next prime factor
         while( g % primes[ j ] != 0 && primes[ j ] * primes[ j ] <= g )
            ++j;
         if( g % primes[ j ] != 0 )
         {
            j = lower_bound( primes.begin(), primes.end(), g ) - primes.begin();
         }
 
         while( g % primes[ j ] == 0 )
            g /= primes[ j ];
 
         // found the prime factor, now map the [x, y] segment to [l, r] segment for tree querying
         int l = lower_bound( indexes[ j ].begin(), indexes[ j ].end(), x ) - indexes[ j ].begin(); // the first element greater or equal to x
         int r = upper_bound( indexes[ j ].begin(), indexes[ j ].end(), y ) - indexes[ j ].begin() - 1; // the first element less or equal to y
 
         if( nums[ j ].size() > 0 && l <= r )
         {
            node tmp = get_max( j, 1, 0, nums[ j ].size() - 1, l, r );
            if( tmp.num > res.num )
                res = tmp;
         }
 
         ++j;
      }
       
      cout << res.num << ' ' << res.cnt << endl;
   }
   return 0;
}