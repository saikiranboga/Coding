#include <stdlib.h>
#include <stdio.h>
#define MOD 1000000007

long long int modpow(long long int base, long long int exp, long long int modulus)
{
    base %= modulus;
    long long int result = 1;
    while (exp > 0)
    {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}


int main(){
  long long int t,i,j,k;
  long long int V,N;
  scanf("%lld",&t);
  while(t--){
    long long int P[100];
    long long int Q[100];
    long long int L[100];

    long long int V,N,p0,p1,A0,B0,C0,M0,q0,q1,A1,B1,C1,M1;

    scanf("%lld %lld",&V,&N);
    scanf("%lld %lld %lld %lld %lld %lld",&p0,&p1,&A0,&B0,&C0,&M0);
    scanf("%lld %lld %lld %lld %lld %lld",&q0,&q1,&A1,&B1,&C1,&M1);

    P[0] = p0;
    P[1] = p1;
    Q[0] = q0;
    Q[1] = q1;
    for(j=2;j<N;j++){
      P[j] = ( A0*A0*P[j-1] + B0*P[j-2] + C0 )%M0;
      Q[j] = ( A1*A1*Q[j-1] + B1*Q[j-2] + C1 )%M1;
    }
    for(j=0;j<N;j++){
      L[j] = P[j]*(M1)+ Q[j] + 1;
    }

    long long int ans,temp;
    ans = V;
    for(j=0;j<N;j++){
      ans = (modpow(ans,L[j]-1,MOD))%MOD;
    }
    
    printf("%lld\n",ans);
  }
  return 0;
}

