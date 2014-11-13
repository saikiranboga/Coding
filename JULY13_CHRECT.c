#include<stdio.h>
int main(){
  int t,N,M,K;
  scanf("%d",&t);
  while(t--){
    scanf("%d%d%d",&N,&M,&K);
    int stones_in_path = 0;
    int total_stones = 0;
    int cells = N*M-2;
    if( (N==1&&M==1) || (N==1&&M==2) || (N==2&&M==1) ){
      printf("0\n");
    }
    else if(N==1 || M==1){
      printf("%d\n",K);
    }
    else{
      int ans;
      if(K == 1)
	printf("1\n");
      else{
	if(K%2 == 0)
	  ans = K/2;
	else
	  ans = (K/2)+1;
	printf("%d\n",ans);
      }
      /*      stones_in_path = (N-1)+(M-2);
      total_stones = K*stones_in_path;
      int ans;
      if(total_stones%cells == 0)
	ans = total_stones/cells;      
      else
	ans = (total_stones/cells) + 1;
      printf("%d\n",ans);
      */
    }
  }
  return 0;
}
