#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--){
    long long count = 0, i, gg, n = (int)1e9;
    cin >> n;
    for(i=1; i*i<=n; i++)
      count += (n/i);
    i--;
    count = 2*count - i*i;
    gg = __gcd(n*n, count);
    cout << count/gg << '/' << n*n/gg << '\n';
  }
  return 0;
}
