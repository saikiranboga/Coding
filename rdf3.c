#include<stdio.h>
double a[100001][35];

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
  int n,k,i,j,t,p,q;
  n = 100000;
  k = 34;
  for(i=0;i<=n;i++){
    for(j=0;j<=k;j++){
      if(j == 0)
	{
	  a[i][j] = i;
	}
      else if(i == 0)
	{
	  a[i][j] = 0;
	}
      else
	{
	  a[i][j] = ((i-1)*a[i-1][j] + a[i-1][j-1])/i;
	}
    }
  }
  fastRead(&t);
  while(t--){
    fastRead(&p);
    fastRead(&q);
    //    printf("(%d,%d):",p,q);
    if(q > 34)
      {
	printf("0.0000000000\n");
      }
    else
      {
	printf("%.10f\n",a[p][q]);
      }
  }
  return 0;
}
