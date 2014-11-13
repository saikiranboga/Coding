#include<stdio.h>

#define MOD 1000000007

int main(){
  int n,k,i;

  scanf("%d %d",&n,&k);

  long long int ans = 1;
  if(n == 1 && k != 1){
    printf("0\n");
  }
  else if(n == 1 && k ==1){
    printf("1\n");
  }
  else if(k == 1){
    for( i=1;i <= (n-2);i++){
      ans = ((ans%MOD)*(n%MOD))%MOD;
    }
    ans = ans%MOD;
    printf("%lld\n",ans);
  }
  else if(k == 2){
    //    n^(n-2) * (n-1)^n * 4^(n-1);
    for(i=1; i<=(n-2); i++){
      ans = ((ans%MOD)*(n%MOD))%MOD;
    }
    for( i=1; i<=n; i++){
      ans = ((ans%MOD)*((n-1)%MOD))%MOD;
    }
    for( i=1; i <= (n-1); i++){
      ans = ((ans%MOD)*4)%MOD;
    }
    ans = ans%MOD;
    printf("%lld\n",ans);
  }

  else if(k == 3){
    //    n^(n-2) * (n-1)^(2*n) * 3^(3*n-2);
    //  n^(n-2) * (n-1)^(3n-3) * 3^(3*n-2)
    for( i=1; i <= (n-2); i++){
      ans = ((ans%MOD)*(n%MOD))%MOD;
    }
    for( i=1; i <= (2*n); i++){
      ans = ((ans%MOD)*((n-1)%MOD))%MOD;
    }
    for( i=1; i <= ((3*n)-2); i++){
      ans = ((ans%MOD)*3)%MOD;
    }
    ans = ans%MOD;
    printf("%lld\n",ans);
  }
  return 0;
}
