#include<stdio.h>
#define MOD 1000000007
long long int power(long long int n,long long int k){
  if(k == 0){
    return 1;
  }
  else if(k == 1){
    return n;
  }
  else if(k%2 == 0){
    long long temp = (power(n,k/2))%MOD;
    return (temp*temp)%MOD;
  }
  else{
    long long int temp = (power(n,k/2))%MOD;
    return (((n*temp)%MOD)*temp)%MOD;
  }
}

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    long long int n;
    scanf("%lld",&n);
    long long int s = power(26,n/2);
    s = (s-1)%MOD;
    s = (s*power(25,MOD-2))%MOD;
    s = (s*52)%MOD;
    if(n%2){
      long long int extra = power(26,n/2+1);
      s = (s+extra)%MOD;
    }
    printf("%lld\n",s);
  }
  return 0;
}
