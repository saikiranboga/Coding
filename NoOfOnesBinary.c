#include<stdio.h>
int ways[1000001]={1,1,2};

int main(){
  int i,count;
  int n,g,t;
  for(i=3;i<1000001;i++){
    ways[i] = (ways[i-1]+ways[i-2])%1000000007;
  }
  scanf("%d",&t);
  while(t--){
    count = 0;
    scanf("%d%d",&n,&g);
    n = ways[n];
    while(n){
      n &= n-1;
      count++;
    }
    if(count==g)
      printf("CORRECT\n");
    else
      printf("INCORRECT\n");
  }
  return 0;
}
