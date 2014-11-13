#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
int main(){
  int t;
  double P,S,l,mv;
  scanf("%d",&t);
  while(t--){
    scanf("%lf %lf",&P,&S);

    l = (P - sqrt(P*P - 24*S))/12;

    mv = l*(S/2-l*(P/4-l));

    printf("%.2lf\n",mv);
  }
  return 0;
}
