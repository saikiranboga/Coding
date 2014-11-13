#include<stdio.h>
int main(){
  int t,k;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&k);
    if(k<=0)
      continue;
    if(k%25!=0)
      printf("%s",&"zyxwvutsrqponmlkjihgfedcba"[25-k%25]);
    k -= k%25;
    while(k>=25){
      printf("zyxwvutsrqponmlkjihgfedcba");
      k -= 25;
    }
    printf("\n");
  }
  return 0;
}
