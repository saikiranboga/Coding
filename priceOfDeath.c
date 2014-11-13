#include<stdio.h>
int a[10000000];
#define MOD 1000000007
int costOfAssasination(long long int n){
  if(n<=10000000){
    if(a[n-1]){
      return a[n-1];
    }
    else{
      a[n-1] = (((costOfAssasination(n-1))%MOD)+((2*((costOfAssasination(n-2))%MOD))%MOD)+((3*((costOfAssasination(n-3))%MOD))%MOD)+((costOfAssasination(n-4))%MOD))%MOD;
      return a[n-1];
    }
  }
  else{
    return (((costOfAssasination(n-1))%MOD)+((2*((costOfAssasination(n-2))%MOD))%MOD)+((3*((costOfAssasination(n-3))%MOD))%MOD)+((costOfAssasination(n-4))%MOD))%MOD;
    
  }
}
int main(){
  a[0]=1;
  a[1]=2;
  a[2]=5;
  a[3]=12;
  long long int n;
  scanf("%lld",&n);
  printf("%d\n",costOfAssasination(n));
  return 0;
}
