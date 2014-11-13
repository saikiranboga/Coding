#include<stdio.h>
#define MOD 1000000007
long long int ar[1001][11];
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
    ar[n][k] = ((((k-1)*power(k,n-2))%MOD)+f(n-2,k))%MOD;
    return ar[n][k];
  }
}
 
int main(){
  FILE* fp;
  fp = fopen("aprl_vih_buff.txt","w+");
  long long int n,k,t,pwr;
  int i,j;
  for(i=0;i<1001;i++){
    for(j=0;j<11;j++){
      ar[i][j] = 0;
    }
  }
  for(i=2;i<1001;i++){
    for(j=1;j<11;j++){
      f(i,j);
    }
  }
  fprintf(fp,"{");
  for(i=0;i<1001;i++){
    fprintf(fp,"{");
    for(j=0;j<11;j++){
      fprintf(fp,"%lld",ar[i][j]);
      if(j != 10){
        fprintf(fp,",");    
      }
    }
    fprintf(fp,"}");
    if(i != 1000){
      fprintf(fp,",");    
    }
  }
  fprintf(fp,"}");
  return 0;
}
