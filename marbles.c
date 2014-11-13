#include<stdio.h>
int main(){
  int n,k,i,t;
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&n,&k);
    long long int p=1ll;
    n--;k--;
    if(k>n/2)
      k=n-k;
    for(i=1;i<=k;i++){
      p=p*(n+1-i)/i;
    }
    printf("%lld\n",p);
  }  
  return 0;
}
