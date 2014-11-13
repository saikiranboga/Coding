#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286//3.1415926535897931159979635
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
  int a, b,t;
  double h1, h2, r1, r2, v1, v2;
  double h3,r3,v3,h4,r4,v4,h5,r5,v5,h6,r6,v6,h7,r7,v7,h8,r8,v8,h9,r9,v9;
  scanf("%d",&t);
  while(t--){
    scanf("%d%d",&a,&b);
    int tmp;
    if(a>b){
    	tmp = a;
    	a = b;
    	b = tmp;
    }
    /*    double ans = (b*b*a*PI)/(4.0*(PI+1)*(PI+1));
    double ans2 = (a*a*(b*PI-a))/(4.0*PI*PI);
    double ans3 = (PI*a*a*a)/4.0;
    double as;
    if(a >= b/(1+PI))
      as = MAX(ans,ans2);
    else
      as = ans2;
    if(b >= a*(PI+2))
      as = MAX(as,ans3);
    printf("%.15lf\n",as);
    /*    printf("ans:%.15lf\n",ans);
	  printf("ans2:%.15lf\n",ans2);*/
    
    r1 = a/(2.0*PI);
    h1 = b - 2*r1;

    /*    r2 = MIN(b/(2.0*(PI+1.0)),a/2.0);
    h2 = a;

    r3 = MIN(a/(2.0*(PI+1.0)),b/2.0);
    h3 = b;*/
    r2 = b/(2.0*(PI+1.0));
    h2 = a;

    r3 = a/(2.0*(PI+1.0));
    h3 = b;

    r4 = a/2.0;
    h4 = a;

    r5 = b/2.0;
    h5 = b;

    double temp = (-16*PI*PI*a*a)+(24*(a*a+b*b))+(16*sqrt(2)*(a*a+b*b));
    r6 = 0;
    if(temp >= 0){
      r6 = (4*PI*b)+sqrt(temp);
      r6 = r6/((4*PI*PI)-6-(4*sqrt(2)));
    }
    h6 = a;

    r8 = 0;
    if(temp >= 0 && 4*PI*b >= temp){
      r8 = (4*PI*b)-sqrt(temp);
      r8 = r8/((4*PI*PI)-6-(4*sqrt(2)));
    }
    h8 = a;

    temp = (-16*PI*PI*b*b)+(24*(b*b+a*a))+(16*sqrt(2)*(b*b+a*a));
    r7 = 0;
    if(temp >= 0){
      r7 = (4*PI*a)+sqrt(temp);
      r7 = r7/((4*PI*PI)-6-(4*sqrt(2)));
    }
    h7 = b;

    r9 = 0;
    if(temp >= 0 && 4*PI*a >= temp){
      r9 = (4*PI*a)-sqrt(temp);
      r9 = r9/((4*PI*PI)-6-(4*sqrt(2)));
    }
    h9 = b;

    v1 = (PI*r1*r1*h1);
    v2 = (PI*r2*r2*h2);
    v3 = (PI*r3*r3*h3);
    v4 = (PI*r4*r4*h4);
    v5 = (PI*r5*r5*h5);
    v6 = (PI*r5*r5*h5);
    v7 = (PI*r5*r5*h5);
    v8 = (PI*r5*r5*h5);
    v9 = (PI*r5*r5*h5);
    double max=0,r,h;
    int ind;
    if(v1 > max && 4*r1 <= a){
      max = v1;
      ind = 1;
      r = r1;h = h1;
    }
    if(4*r2 <= a && v2 > max){
      max = v2;
      ind = 2;
      r = r2;h = h2;
    }
    if(v3>max && 4*r2 <= b){
      max = v3;
      ind = 3;
      r = r3;h = h3;
    }
    if(v4>max && 2*r4*(2+PI)<=b){
      max = v4;
      ind = 4;
      r = r4;h = h4;
    }
    if(v5>max && 2*r5*(2+PI)<=a){
      max = v5;
      ind = 5;
      r = r5;h = h5;
    }
    if(v6>max && r6 >0 && 2*PI*r6 <= b){
      max = v6;
      ind = 6;
      r = r6;h = h6;
    }
    if(v7>max && r7 > 0 && 2*PI*r7 <= a){
      max = v7;
      ind = 7;
      r = r7;h = h7;
    }
    if(v8>max && r8 > 0 && 2*PI*r8 <= b){
      max = v8;
      ind = 8;
      r = r8;h = h8;
    }
    if(v9>max && r9 > 0 && 2*PI*r9 <= a){
      max = v9;
      ind = 9;
      r = r9;h = h9;
    }
    //    printf("%.15lf\nind = %d\nr = %.6lf, h = %.6lf\n",max,ind,r,h);
    printf("%.18lf\n",max);
  }
  return 0;
}
