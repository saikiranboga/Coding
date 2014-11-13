#include <stdio.h>

int main(){
  long long int n,i;
  double x1,y1,x2,y2,x3,y3,d1,d2,d3,temp;
  scanf("%lld",&n);
  long long int ans = 0;

  for(i=0;i<n;i++){
    scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);

    temp = (x1-x2);
    temp *= temp;
    d1 = temp;

    temp = (y1-y2);
    temp *= temp;
    d1 += temp;

    temp = (x2-x3);
    temp *= temp;
    d2 = temp;

    temp = (y2-y3);
    temp *= temp;
    d2 += temp;

    temp = (x1-x3);
    temp *= temp;
    d3 = temp;

    temp = (y1-y3);
    temp *= temp;
    d3 += temp;

    if( (d1 == (d2+d3)) || ( d2 == (d1+d3)) || ( d3 == (d1+d2)) )
      ans++;
  }
  printf("%lld\n",ans);
  return 0;
}
