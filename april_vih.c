#include<stdio.h>
#define MOD 1000000007
long long int ar[1002][12];

/*inline void fastRead(long long int *a)
{
  register char c=0;
  while (c<33) c=getchar_unlocked();
  *a=0;
  while (c>33)
    {
      *a=*a*10+c-'0';
      c=getchar_unlocked();
    }
    }*/

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
long long int f(n,k){
  if(n == 2){
    ar[n][k] = k;
    return k;
  }
  else if(n == 1){
    ar[n][k] = 0;
    return 0;
  }
  else if(ar[n][k]){
    return ar[n][k];
  }
  else{
    long long int temp;
    temp = ((((k-1)*power(k,n-2))%MOD)+f(n-2,k))%MOD;
    ar[n][k] = temp;
    return temp;
  }
}

int main(){
  long long int n,k,t,pwr;
  //  fastRead(&t);
  scanf("%d",&t);
  int i,j;
  for(i=2;i<1001;i++){
    for(j=1;j<11;j++){
      f(i,j);
    }
  }
  while(t--){
    //    fastRead(&n);
    //    fastRead(&k);
    scanf("%d%d",&n,&k);
    printf("%lld\n",ar[n][k]);
  }
  return 0;
}
