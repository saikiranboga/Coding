#include<stdio.h>
#define MOD 1000000007
long long int fib(n){
  if(n == 2)
    return 1;
  if(n == 1)
    return 1;
  return ((fib(n-1)%MOD)+(fib(n-2)%MOD))%MOD;
}
int main(){
  long long int n,t;
  scanf("%lld",&t);
  while(t--){
    scanf("%lld",&n);
    printf("%lld\n",(fib(n)%MOD));
  }
  return 0;
}
