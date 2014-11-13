#include<stdio.h>
int main(){
  int i,M,inp[100001];
  scanf("%d",&M);
  for(i=1;i<=M;i++){
    scanf("%d",&inp[i]);
  }
  if(M > 1){
    printf("2\n%d %d\n",inp[1],inp[2]);
  }
  else{
    printf("1\n%d\n",inp[1]);
  }
  return 0;
}
