#include <stdio.h>
#define PI 3.1415926535897931159979635
#define MIN(a,b) ((a)<(b)?(a):(b))
int main(){
  int a, b,t;
  double h1, h2, r1, r2, v1, v2;
  double h3,r3,v3,r4,h4,v4,r5,h5,v5;
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&a,&b);
    r1 = MIN(a/(2.0*PI),b/(2.0*PI));
    h1 = (a+b)-MIN(a,b)-2*r1;

    r2 = MIN(b/(2.0*(PI+1.0)),a/2.0);
    h2 = a;

    r3 = MIN(a/(2.0*(PI+1.0)),b/2.0);
    h3 = b;

    r4 = MIN(b/(2.0*(PI+1.0)),b/2.0);
    if(r4 == b/2.0)
      h4 = b;
    else
      h4 = a;

    r5 = MIN(a/(2.0*(PI+1.0)),a/2.0);
    if(r4 == a/2.0)
      h5 = a;
    else
      h5 = b;

    v1 = (PI*r1*r1*h1);
    v2 = (PI*r2*r2*h2);
    v3 = (PI*r3*r3*h3);
    v4 = (PI*r4*r4*h4);
    v5 = (PI*r5*r5*h5);

    double max;
    if(v1 > v2)
      max = v1;
    else
      max = v2;
    if(v3>max)
      max = v3;
    if(v4>max)
      max = v4;
    if(v5>max)
      max = v5;
    printf("%.15lf\n",max);
  }
  return 0;
}
