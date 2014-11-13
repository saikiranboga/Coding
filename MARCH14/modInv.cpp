#include <iostream>
using namespace std;

#define ll long long
#define MOD 1000000009

// Use 64 bits integers to avoid overflow errors during multiplication.
ll modPow(ll a, ll x, ll p) {
    //calculates a^x mod p in logarithmic time.
    if(x==0)
        return 1;
    if(x==1)
        return a;
    ll ret = modPow(a, x/2, p);
    ret = (ret*ret)%MOD;
    if(x&1)
        ret = (ret*a)%MOD;
    return ret;
}

ll modInverse(ll a, ll p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}
ll modBinomial(ll n, ll k, ll p) {
// calculates C(n,k) mod p (assuming p is prime).

    ll numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (int i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }
    
    ll denominator = 1; // k!
    for (int i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }
    
    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}

ll calculate(ll n, ll k) {
    return ( modBinomial(n,k, MOD) );
}
int main(){
    ll n,k;
    cin >> n >> k;
    cout << calculate(n, k) << endl;
    return 0;
}