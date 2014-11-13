#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <set>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef complex<double> cd;

#define FOR(i,n) for(i=0;i<n;i++)
#define EPS 1e-14

typedef struct poly{
 public:
  vector<cd> coeffs;
  poly(){
    coeffs = vector<cd>(1,0);
  }
  poly(vector<cd> c){
    coeffs = c;
  }
  poly(vector<long long int> c){
    int i;
    FOR(i,c.size())
      coeffs.push_back(c[i]);
  }
  poly(const poly &poli){
    coeffs = poli.coeffs;
  }

  vector<cd>  trim(vector<cd> x) {
    vector<cd> ret;
    int at = x.size() - 1;
    while ((at>=0) && fabs(real(x[at]) < EPS))
      --at;
    if (at < 0)
      return vector<cd>(1, cd(0, 0));
    for (int i = 0; i <= at; ++i)
      ret.push_back(x[i]);
    return ret;
  }

  vector<cd> DFT(poly A, cd w){
    int n = A.coeffs.size();
    if(n==1)
      return vector<cd>(1,A.coeffs[0]);    
    vector<cd> coeffs0 = vector<cd>(n/2);
    vector<cd> coeffs1 = vector<cd>(n/2);
    int i;
    FOR(i,n){
      if(i&1)
	coeffs1[i/2] = A.coeffs[i];
      else
	coeffs0[i/2] = A.coeffs[i];
    }

    poly a0 = poly(coeffs0), a1 = poly(coeffs1);

    vector<cd> y0 = DFT(a0, w*w);
    vector<cd> y1 = DFT(a1, w*w);

    vector<cd> ret;
    cd _w = 1;
    FOR(i,n/2){
      ret.push_back(y0[i]+_w*y1[i]);
      _w = _w*w;
    }
    _w = 1;
    FOR(i,n/2){
      ret.push_back(y0[i]-_w*y1[i]);
      _w = _w*w;
    }
    return ret;
  }

  poly operator*(const poly &B){
    poly a = poly(coeffs);
    poly b = B;
    int n = max(a.coeffs.size(), b.coeffs.size());
    int p2=1;
    while( p2<n )
      p2 *= 2;
    p2 *= 2;

    while(a.coeffs.size() < p2)
      a.coeffs.push_back(0);
    while(b.coeffs.size() < p2)
      b.coeffs.push_back(0);

    n = p2;

    vector<cd> w1 = DFT(a, cd( cos(2*M_PI/n), sin(2*M_PI/n) ) );
    vector<cd> w2 = DFT(b, cd( cos(2*M_PI/n), sin(2*M_PI/n) ) );
    
    int i;
    FOR(i,w1.size())
      w1[i] *= w2[i];

    vector<cd> w = DFT(poly(w1), cd( cos(2*M_PI/n), -sin(2*M_PI/n) ) );

    FOR(i,w.size()){
      imag(w[i]) = 0;
      real(w[i]) /= w.size();
    }
    return poly(trim(w));
  }

}poly;

int main(){
  int i;
  long long int n;
  scanf("%lld",&n);

  if(n <= 2000){
    long long int ip[10000];
    FOR(i,n)
      scanf("%lld",&ip[i]);
    set<long long> res;
    int l,r;
    FOR(l,n){
      long long S = 0;
      for(r=l; r<n; r++){
	S += ip[r];
	res.insert(S);
      }
    }
    cout << res.size()-1 << endl;

  }
  else{
    long long int total,tmp;
    vector<long long> a(5000002),b(5000002),res,v,dsum;
    set<long long> s;

    a[0] = 1;
    b[0] = 1;

    total = 0;
    for(i=1; i<=n; i++){
      scanf("%lld",&tmp);
      v.push_back(tmp);
      total += tmp;
      dsum.push_back(total);
      s.insert(total);
    }

    if(total < 5000001){
      FOR(i,n){
	a[dsum[i]] = 1;
	b[dsum[i]] = 1;
      }
    }

    a.resize(total+1);
    b.resize(total+1);

    reverse( b.begin(), b.end() );

    poly _a = poly(a);
    poly _b = poly(b);
    poly p =  _a*_b;

    long long int p_size = p.coeffs.size();
    //    FOR(i,p_size){
      //      real(p.coeffs[i]) /= (n+0.5);
    //      imag(p.coeffs[i]) = 0;
    //    }
    long long int count = 0;

    for(i=total+1; i<p_size; i++){
      if( real(p.coeffs[i]) > EPS)
	count++;
    }  
    cout << count-1 << endl;
  }
  return 0;
}
