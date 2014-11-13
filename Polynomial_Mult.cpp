#include <cmath>
#include <iostream>
#include <vector>
#include <complex>
using namespace std;
 
#define EPS 1e-14
 
typedef complex<double> cd;
 
typedef struct poly {
  vector<cd> coeffs; // coeff[i] is coefficient of x^i
  poly() { coeffs = vector<cd>(1, 0); }
  poly(vector<cd> c) { coeffs = c; }
  poly(const poly &x) { coeffs = x.coeffs; }
 
  vector<cd> dft(poly p, cd w) {
    int n = p.coeffs.size();
    if (n == 1)
      return vector<cd>(1, p.coeffs[0]);
    vector<cd> coeff0 = vector<cd>(n/2);
    vector<cd> coeff1 = vector<cd>(n/2);
    cd cur = 1;
    for (int i = 0; i < n/2; ++i, cur *= w)
      coeff0[i] = p.coeffs[i] + p.coeffs[i+n/2], coeff1[i] = cur*(p.coeffs[i] - p.coeffs[i+n/2]);
    poly r0 = poly(coeff0), r1 = poly(coeff1);
    vector<cd> df0 = dft(r0, w*w), df1 = dft(r1, w*w);
    vector<cd> ret;
    for (int i = 0; i < n; ++i)
      if (i&1)
	ret.push_back(df1[i/2]);
      else
	ret.push_back(df0[i/2]);
    return ret;
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
 
  poly operator*(const poly &B) {
    poly a = poly(coeffs), b = B;
    int n = max(a.coeffs.size(), b.coeffs.size());
    int p2 = 1;
    while (p2 < n)
      p2 *= 2;
    p2 *= 2;
    while (a.coeffs.size() < p2)
      a.coeffs.push_back(0);
    while (b.coeffs.size() < p2)
      b.coeffs.push_back(0);
    n = p2;
    vector<cd> w1 = dft(a, cd(cos(2*M_PI/n),sin(2*M_PI/n)));
    vector<cd> w2 = dft(b, cd(cos(2*M_PI/n),sin(2*M_PI/n)));
    for (int i = 0; i < w1.size(); ++i)
      w1[i] *= w2[i];
    vector<cd> w = dft(w1, cd(cos(2*M_PI/n),-sin(2*M_PI/n)));
    /*
    for (int i = 0; i < w.size(); ++i)
      w[i] /= double(n), imag(w[i]) = 0; // polys are actually over reals, so destroy any roundoff error in imaginary components
    //    return poly(trim(w));
    */
    return poly(w);
  }
} poly;
 
int main() {
  vector<cd> coeffs, coeffs2;
  coeffs.push_back(1), coeffs.push_back(1); // x + 1
  coeffs2.push_back(2), coeffs2.push_back(1); // x + 2
  poly p(coeffs), q(coeffs2);
  p = p * q; // should give x^2 + 3x + 2

  for (int i = 0; i < p.coeffs.size(); ++i)
    cout << p.coeffs[i] << " "; // it does!
  cout << endl;
  return 0;
}
