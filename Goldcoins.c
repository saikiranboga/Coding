#include<stdio.h>
long unsigned int cost[30][19];
unsigned int amount;

unsigned int currentVal(int f2,int f3){
  int i;
  unsigned int cv = amount >> f2;
  for(i=0; i<f3; i++){
    cv /= 3;
  }
  return cv;
}

long int optAmt(int factor2,int factor3){
  unsigned int cv;
  cv = currentVal(factor2,factor3);
  if(cv < 12){
    cost[factor2][factor3] = cv;
    return (long unsigned int)cv;
  }
  else{
    if(cost[factor2][factor3]== 0)
      cost[factor2][factor3] = (optAmt(factor2+1,factor3)+optAmt(factor2,factor3+1)+optAmt(factor2+2,factor3));
    return cost[factor2][factor3];
  }
}

int main(){
  int i,j;
  while(scanf("%d",&amount) != EOF){
      for(i=0;i<30;i++)
	for(j=0;j<19;j++)
	  cost[i][j] = 0;
      printf("%lu\n",optAmt(0,0));
    }
    return 0;
}
