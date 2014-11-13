#include <stdio.h>
int josephus(int n, int k){
  if(n == 1)
    return 1;
  else
    return ((josephus(n-1,k)+k-1)%n)+1;
}
int main(){
  int i,n,k,ans;
  scanf("%d",&n);
  while(n!=0){
    ans = 0;
    i = 1;
    while(ans!=12){
      ans = josephus(n-1,i);
      if(ans == 12)
	printf("%d\n",i);
      i++;
    }
    scanf("%d",&n);
  }
  return 0;
}
 
