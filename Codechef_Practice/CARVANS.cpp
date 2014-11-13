#include <stdio.h>
#include <limits.h>

int main(){
  int t,i,speed,n;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    int ahead = INT_MAX;
    int ans = 0;
    for(i=0;i<n;i++){
      scanf("%d",&speed);
      if(speed > ahead)
	ans++;
      else
	ahead = speed;
    }
    printf("%d\n",n-ans);
  }
  return 0;
}
