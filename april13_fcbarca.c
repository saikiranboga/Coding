#include<stdio.h>
#define MOD 1000000007
long long int power(long long int base,long long int exp){
  long long int temp;
  if(exp == 0)
    return 1;
  else if(exp == 1)
    return base;
  else if(exp%2 == 0){
    temp = power(base,exp/2);
    return (temp*temp)%MOD;
  }
  else{
    temp = power(base,exp/2);
    return (((temp*temp)%MOD)*base)%MOD;
  }
}

int main(){
  long long int n,k,t,pwr;
  scanf("%lld",&t);
  while(t--){
    scanf("%lld%lld",&n,&k);
    if(n == 2){
      printf("%lld\n",k);
    }
    else if(n == 3){
      printf("%lld\n",k*(k-1));
    }
    else{
      pwr = power(k,n-3);
      printf("%lld\n",(pwr*(2*k-1))%MOD);
    }
  }
  return 0;
}
/*

#include<stdio.h>
#define MOD 1000000007
long long int power(long long int base,long long int exp){
  long long int temp;
  if(exp == 0)
    return 1;
  else if(exp == 1)
    return base;
  else if(exp%2 == 0){
    temp = power(base,exp/2);
    return (temp*temp)%MOD;
  }
  else{
    temp = power(base,exp/2);
    return (((temp*temp)%MOD)*base)%MOD;
  }
}

int main(){
  long long int n,k,t,pwr;
  scanf("%lld",&t);
  while(t--){
    scanf("%lld%lld",&n,&k);
    if(n == 2){
      printf("%lld\n",k);
    }
    else if(n == 3){
      printf("%lld\n",k*(k-1));
    }
    else{
      pwr = (power(k,n-3)*((k-1)*(k-1)+k))%MOD;
      printf("%lld\n",pwr);
    }
  }
  return 0;
}
 
*/
