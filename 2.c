#include<stdio.h>
#include<math.h>
int isprime(long long int n){
  if(n==1)
    return 0;
  long long int i=0;
  long long int s = sqrt(n)+2;
  if(n==2||n==3)
    return 1;
  for(i=2;i<s;i++){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}
int main(){
  long long int t;
  long long int n;
  long long int ans = 0;
  scanf("%lld",&t);
  while(t--){
    scanf("%lld",&n);
    ans = 1;
    if(n==3)
      ans = 3;
    else if(isprime(n))
      ans = 2;
    printf("%lld\n",ans);
  }
}
