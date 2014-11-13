#include<stdio.h>
int main(){
  int t,n,i,sum;
  scanf("%d",&t);
  while(t--){
    sum = 0;
    scanf("%d",&n);
    for(i=1;i<=n/2;i++){
      if(n%i==0)
	sum += i;
    }
    printf("%d\n",sum);
  }
  return 0;
}
