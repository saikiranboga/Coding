#include<stdio.h>
#include<math.h>
const long double pi = 2.0*acos(0.0);
long double min(long double a,long double b)
{
  return ( a<b?a:b );
}
long double max(long double a,long double b)
{
  return ( a>b?a:b );
}
int main()
{
  long double t,w,h,i,temp;
  long double r,a,aa,v;
  scanf("%Lf",&t);
  while(t--)
    {
      scanf("%Lf%Lf",&w,&h);
      v=0;
      r = min( h/3.0 , w/(pi*2.0) );
      a = h - 2*r ;
      v = max( v , pi*r*r*a );
      int wCase,wcase2;
      a=w;
      if(h>=w*(pi+2))
	{
	  wCase = 1;
	  r=w/2.0;
	}
      else if(h<=w*(pi+1)/2.0)
	{
	  wCase = 2;
	  r=h/(pi+1)/2.0;
	}
      else
	{
	  wCase = 3;
	  r = h*(pi+1);
	  r += w;
	  aa = ((2*h*w*(pi+1)) - (w*w*pi*(pi+2)));
	  if(aa>=0){
	    aa = sqrt(aa);
	    r -= aa;
	    r /= (2*(pi+1)*(pi+1));
	  }
	  else
	    r = 0;
	  if(w> 4*r || w< 2*r)
	    {
	      r = 0;
	    }
	}
      v = max( v , pi*r*r*w );
      temp=w;
      w=h;
      h=temp;
      r = min( h/3.0 , w/(pi*2.0) );
      a = h - 2*r ;
      v = max( v , pi*r*r*a );
      a=w;
      if(h>=w*(pi+2))
	{
	  wcase2 = 9;
	  r=w/2.0;
	}
      else if(h<=w*(pi+1)/2.0)
	{
	  wcase2 = 10;
	  r=h/((pi+1)*2.0);
	}
      else
	{
	  wcase2 = 11;
	  r = h*(pi+1);
	  r += w;
	  aa = ((2*h*w*(pi+1)) - (w*w*pi*(pi+2)));
	  if(aa>=0){
	    aa = sqrt(aa);
	    r -= aa;
	    r /= (2*(pi+1)*(pi+1));
	  }
	  else
	    r = 0;
	  if(w> 4*r || w< 2*r)
	    {
	      r = 0;
	    }
	}
      if(v < pi*r*r*a)
	wCase = wcase2;
      v = max( v , pi*r*r*a );
      printf("%.15Lf\n",v);
    }
  return 0;
} 
