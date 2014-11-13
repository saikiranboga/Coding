#include <stdio.h>
#define MAX 1000000
int list[MAX];
int main()
{
  int t,n,i,j;
  int flag;
  scanf("%d",&t);
  while(t--){
    flag = 1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&list[i]);
    }

    i = 0;
    while(flag == 1 && i<n){
      if( list[i] != i+1){
	flag = 0;
      }
      i++;
    }
    if(flag == 1)
      printf("inverse\n");
    else
      printf("not inverse\n");
  }
  return 0;
}
