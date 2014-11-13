#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long SmallC(long long n, long long r, long long MOD)
{
    vector< vector<long long> > C(2,vector<long long> (r+1,0));
 
    for (long long i=0; i<=n; i++)
    {
        for (long long k=0; k<=r && k<=i; k++)
            if (k==0 || k==i)
                C[i&1][k] = 1;
            else
                C[i&1][k] = (C[(i-1)&1][k-1] + C[(i-1)&1][k])%MOD;
    }
    return C[n&1][r];
}
 
long long Lucas(long long n, long long m, long long p)
{
    if (n==0 && m==0) return 1;
    long long ni = n % p;
    long long mi = m % p;
    if (mi>ni) return 0;
    return Lucas(n/p, m/p, p) * SmallC(ni, mi, p);
}
 
long long C(long long n, long long r, long long MOD)
{
    return Lucas(n, r, MOD);
}
 
int main()
{
     
    long long n,r,p;
    while (~scanf("%lld%lld%lld",&n,&r,&p))
    {
        cout << n << " " << r << " " << p << endl;
          printf("%lld\n",C(n,r,p));
    }
}