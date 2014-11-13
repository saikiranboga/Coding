#include <iostream>
using namespace std;

#define ll long long
#define MOD 1000000007

long long degree(long long a, long long k, long long p) {
  long long res = 1;
  long long cur = a;

  while (k) {
    if (k%2) {
      res = (res * cur)%p;
    }
    k /= 2;
    cur = (cur * cur) % p;
  }
  return res;
}

int get_degree(long long n, long long p) { // returns the degree with which p is in n!
  int degree_num = 0;
  long long u = p;
  long long temp = n;
  while (u <= temp) {
    degree_num += temp/u;
    u *= p;
  }
  return degree_num;
}

long long combinations(int n, int k, long long p) {
  int num_degree = get_degree(n,p) - get_degree(n- k,p);
  int den_degree = get_degree(k,p);
  if (num_degree > den_degree) {
    return 0;
  }
  long long res = 1;
  for (long long i = n; i > n- k; --i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res *ti)%p;
  }
  long long denom = 1;
  for (long long i = 1; i <= k; ++i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    denom = (denom * ti)%p;
  }
  res = (res * degree(denom, p-2, p)) % p;
  return res;
}

int main(){
  ll t, m, n;
  cin >> t;
  while(t--){
    cin >> m >> n;
    cout << combinations(m+n-2, m-1, MOD) << endl;
  }
  return 0;
}