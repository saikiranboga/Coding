#include <stdio.h>

int main(){
  int t,n,j;
  scanf("%d",&t);
  while(t--){    
    scanf("%d",&n);
    if(n%2)
      printf("BOB\n");
    else
      printf("ALICE\n");
  }
  return 0;
}
