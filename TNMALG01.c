#include<stdio.h>
#include<math.h>
int  main(){
  int t,w,l,temp;
  float temp2;
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&l,&w);
    temp = w/l;
    temp2 = 2*(pow((temp+1),2))-1;
    temp = temp2;
    if(w == 0){
      printf("0\n");
    }
    else{
      printf("%d\n",temp);
    }
  }
  return 0;
}

