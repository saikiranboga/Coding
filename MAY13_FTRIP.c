#include<stdio.h>
int main(){
  int t,i,j;
  double n,m,s,k;
  scanf("%d",&t);
  while(t--){
    scanf("%lf %lf %lf %lf",&s,&n,&m,&k);
    double prod = 1;
    double num = 0,denom = 0;
    num += prod;
    for(i=1;i<k;i++){
      if(s-m-n+i+1 <= 0){
      }
      else{
	//	prod *= ((m-1-i)/(i+1))*((n-i-1)/(s-m-n+i+2));
	prod *= ((m-i)/(i))*((n-i)/(s-m-n+i+1));
	num += prod;
      }
    }
    denom = num;
    for(i=k;i<m;i++){
      if((s-m-n+i+1) <= 0){
      }
      else{
	//	prod *= ((m-1-i)/(i+1))*((n-i-1)/(s-m-n+i+2));
	prod *= ((m-i)/(i))*((n-i)/(s-m-n+i-1+2));
	denom += prod;
      }
    }
    if((m-k-1 == s-n) || (s == n)){
      printf("1.00000000\n");
    }
    else{
      printf("%.18lf\n",(1-(num/denom)));
    }
  }
  return 0;
}
