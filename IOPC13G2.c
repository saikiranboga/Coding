#include<stdio.h>
int sum[100002];
int main(){
  int i,m,n,k,p,q;
  for(i=0;i<=100000;i++)
    sum[i] = 0;
  scanf("%d%d%d",&n,&m,&k);
  for(i=0;i<m;i++){
    scanf("%d%d",&p,&q);
    sum[p]++;
    sum[q]++;
  }
  int count=0;
  for(i=0;i<=100000;i++){
    if(sum[i]>=k){
      count++;
    }
  }
  printf("%d\n",count);
  return 0;
}
