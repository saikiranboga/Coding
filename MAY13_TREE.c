#include<stdio.h>
#define MOD 1000000007

int main(){
  int n,k,i;
  scanf("%d %d",&n,&k);
  long long int ans = 1;
  if(k == 1){
    for(i=1;i<=n-2;i++){
      ans = (ans*n)%MOD;
    }
    ans = ans%MOD;
    printf("%lld\n",ans);
  }
  else if((n*k-1)/k == 0){
    printf("0\n");
  }
  else{
    long long int temp = (n-1)*k;
    int temp2 = n*k-2;
    for(i=1;i<=temp2;i++){
      ans = (ans*temp)%MOD;
    }
    ans = ans%MOD;
    printf("%lld\n",ans);
  }
  return 0;
}
