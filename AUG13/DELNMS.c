#include <stdio.h>

int main(){
  int i,n,t;
  scanf("%d",&t);
  while(t--){
    int ar[10010];
    scanf("%d",&n);
    for(i=0; i<n; i++)
      scanf("%d",&ar[i]);
    printf("%d\n",n);
    for(i=n; i>0; i--)
      printf("%d 1\n",i);
  }
  return 0;
}
