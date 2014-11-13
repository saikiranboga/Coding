#include <stdio.h>
int points[300000][2];

inline void fastRead(int *a)
{
  register char c=0;
  while (c<33) c=getchar_unlocked();
  *a=0;
  while (c>33)
    {
      *a=*a*10+c-'0';
      c=getchar_unlocked();
    }
}

int main(){
  int n,t,i,x,y,d,x1,y1;
  int p,q,sum,count;
  fastRead(&n);
  fastRead(&t);
  for(i=0;i<n;i++){
    fastRead(&points[i][0]);
    fastRead(&points[i][1]);
  }
  while(t--){
    count = 0;
    fastRead(&x);
    fastRead(&y);
    fastRead(&d);
    x1 = x+d;
    y1 = y+d;
    sum = x+y+d;
    for(i=0;i<n;i++){
      p = points[i][0];
      q = points[i][1];
      if(p>=x && p<=x1 && q>=y && q<=y1 && (p+q)<=sum)
	count++;
    }
    printf("%d\n",count);
  }
  return 0;
}
