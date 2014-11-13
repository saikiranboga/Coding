#include<stdio.h>
int main(){
  int t,i,min,index;
  int bottles[9];
  int sum[6];
  scanf("%d",&t);
  while(t--){
    for(i=0;i<9;i++)
      scanf("%d",&bottles[i]);
    sum[0] = bottles[1]+bottles[2]+bottles[3]+bottles[4]+bottles[6]+bottles[8];
    sum[1] = bottles[1]+bottles[2]+bottles[3]+bottles[5]+bottles[6]+bottles[7];

    sum[2] = bottles[0]+bottles[1]+bottles[4]+bottles[5]+bottles[6]+bottles[8];
    sum[3] = bottles[0]+bottles[1]+bottles[3]+bottles[5]+bottles[7]+bottles[8];

    sum[4] = bottles[0]+bottles[2]+bottles[4]+bottles[5]+bottles[6]+bottles[7];
    sum[5] = bottles[0]+bottles[2]+bottles[3]+bottles[4]+bottles[7]+bottles[8];

    min = sum[0];
    index = 0;
    for(i=1;i<6;i++)
      if(sum[i]<min){
	min = sum[i];
	index = i;
      }
    switch(index){
    case 0:
      {
	printf("BCG %d\n",min);
	break;
      }
    case 1:
      {
	printf("BGC %d\n",min);
	break;
      }
    case 2:
      {
	printf("CBG %d\n",min);
	break;
      }
    case 3:
      {
	printf("CGB %d\n",min);
	break;
      }
    case 4:
      {
	printf("GBC %d\n",min);
	break;
      }
    case 5:
      {
	printf("GCB %d\n",min);
	break;
      }
    }
  }
  return 0;
}
