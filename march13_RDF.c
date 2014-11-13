#include<stdio.h>
int n,k;

double rec(int prob,int num,int iteration){
  int i;
  double res;
  double sum = 0.0;
  if(num == 0){
    return 0.0;
  }
  else if(iteration == k){
    res = (double)((double)num/prob);
    return res;
  }
  else{
    for( i = 0; i < num; i++){
      if(i == 0 || i == 1 ){
	sum += rec(prob,i,iteration+1);
      }
      else{
	if(iteration <k-1)
	  sum += rec(prob*i,i,iteration+1);
	else{
	  sum += rec(prob,i,iteration+1);
	}
      }
    }
    return sum;
  }
}
int main(){
  int i,t;
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&n,&k);
    else{
      double sum = rec(n,n,0);
      printf("%f\n",sum);
    }
  }
  return 0;
}

