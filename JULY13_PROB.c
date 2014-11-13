#include <stdio.h>
#include <math.h>

int main(){
  long long int T1,T2,T3,T4,t;
  scanf("%lld",&t);
  while(t--){
    double prob = 0.0;
    scanf("%lld %lld %lld %lld",&T1,&T2,&T3,&T4);
    prob = (double)T1/(double)(T1+T2);
    prob = round(prob*10000000)/10000000;
    printf("%.7lf\n",prob);
  }
  return 0;
}
