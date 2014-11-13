#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,quo,t,k;
  scanf("%d",&t);
  //  FILE* fp = fopen("pie.txt","w");
  while(t--){
    scanf("%d",&k);
    //    fprintf(fp,"3");
    if(k!=0)
      fprintf(fp,".");
    /*    int rem = 103993%33102;
    for(i=1;i<=k;i++){
      rem *= 10;
      quo = rem/33102;
      rem %= 33102;
      fprintf(fp,"%d",quo);
      }*/
    //    printf("\n");
  }
  return 0;
}
