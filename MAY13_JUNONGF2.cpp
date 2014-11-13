#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

#define LL      long long
#define S(x)    scanf("%lld",&x)

#define INC(i,a,b)             for(int i=a;i<b;++i)
#define REP(i,n)               INC(i,0,n)

const LL MOD = 1e9+7;
LL v, n;
LL L[101], P[101], Q[101];
LL a0, b0, c0, m0, a1, b1, c1, m1;
map<LL,LL> power;

void solve();
void generate();
LL getPower(LL);

int main() {
   LL t; S(t);
   while(t--) solve();
   return 0;
}

void solve() {
   S(v); S(n);
   generate();
   
   power.clear();
   power[0] = 1;
   power[1] = v%MOD;
   
   LL req = 1;
   REP(i,n) {
      req *= (L[i]-1)%(MOD-1);
      req %= (MOD-1);
   }
   printf("%lld\n",getPower(req));
}
void generate() {
   S(P[0]); S(P[1]); S(a0); S(b0); S(c0); S(m0);
   INC(i,2,n) P[i] = (a0*a0*P[i-1] + b0*P[i-2] + c0)%m0;
   S(Q[0]); S(Q[1]); S(a1); S(b1); S(c1); S(m1);
   INC(i,2,n) Q[i] = (a1*a1*Q[i-1] + b1*Q[i-2] + c1)%m1;
   
   REP(i,n) L[i] = P[i]*m1 + Q[i] + 1;
}
LL getPower(LL exp) {
   if(power.count(exp)!=0) return power[exp];
   
   LL a = exp/2, b=exp-a;
   power[exp] = (getPower(a)*getPower(b))%MOD;
   return power[exp];
}